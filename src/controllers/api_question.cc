#include "api_question.h"

#include "../db/Books.h"
#include "../db/Chapters.h"
#include "../db/Qa.h"

#include <string>
#include <texcaller.h>
using namespace api;
using namespace drogon::orm;
using namespace drogon_model::qabuilder;
// add definition of your processing function here
auto tpl =
    "\\documentclass[scheme=plain]{ctexart}\n\\usepackage{amsmath,amsthm,amssymb}\n\\newtheorem{ex}{Ex}\n\\title{An Introduction to Test}\n\\author{QABuilder(On behalf of Author)}\n\\date{\\today}\n\\begin{document}\n    \\maketitle\n    ";
void question::makePaper(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    try
    {
        auto db = drogon::app().getDbClient("qabuilder");
        auto reqctx = req->getJsonObject();
        if (!reqctx || !(*reqctx).isMember("qaid") || !(*reqctx)["qaid"].isArray())
            return callback(drogon::HttpResponse::newNotFoundResponse());
        auto r = db->execSqlSync("select content from qa where id in (" +
                                 (
                                     {
                                         std::string res;
                                         Json::Value arr = (*reqctx)["qaid"];
                                         for (int a = 0; a < arr.size(); a++)
                                             res += std::to_string(arr[a].asInt()) + ",";
                                         res.pop_back();
                                         res;
                                     }) +
                                 ")");
        std::string raw = tpl;
        for (Result::SizeType i = 0; i < r.size(); ++i)
            raw += std::string("\\begin{ex}\n") + r[i]["content"].as<std::string>() + std::string("\\end{ex}\n");
        raw += "\\end{document}";
        std::string pdf, info;
        texcaller::convert(pdf, info, raw, "XeLaTeX", "PDF", 2);
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setContentTypeCode(CT_APPLICATION_PDF);
        resp->setBody(pdf);
        callback(resp);
    }
    catch (...)
    {
        Json::Value res;
        res["status"] = 500;
        res["error"] = "dberr";
        callback(drogon::HttpResponse::newHttpJsonResponse(res));
    }
}
void question::getBooks(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    Json::Value res;
    res["status"] = 200;
    res["books"] = Json::Value(Json::arrayValue);
    auto db = drogon::app().getDbClient("qabuilder");
    Mapper<Books> mp(db);
    std::vector<Books> t = mp.findAll();
    for (auto rc : t)
    {
        res["books"].append(rc.toJson());
    }
    return callback(drogon::HttpResponse::newHttpJsonResponse(res));
}
void question::getChapters(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int bookid)
{
    Json::Value res;
    res["status"] = 200;
    res["chapters"] = Json::Value(Json::arrayValue);
    auto db = drogon::app().getDbClient("qabuilder");
    Mapper<Chapters> mp(db);
    std::vector<Chapters> t = mp.findBy(Criteria(Chapters::Cols::_bookid, CompareOperator::EQ, bookid));
    for (auto rc : t)
    {
        res["chapters"].append(rc.toJson());
    }
    return callback(drogon::HttpResponse::newHttpJsonResponse(res));
}
void question::getQuestions(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int chapterid)
{
    Json::Value res;
    res["status"] = 200;
    res["questions"] = Json::Value(Json::arrayValue);
    auto db = drogon::app().getDbClient("qabuilder");
    Mapper<Qa> mp(db);
    std::vector<Qa> t = mp.findBy(Criteria(Qa::Cols::_chapter, CompareOperator::EQ, chapterid));
    for (auto rc : t)
    {
        res["questions"].append(rc.toJson());
    }
    return callback(drogon::HttpResponse::newHttpJsonResponse(res));
}
void question::getBook(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int bookid)
{
    Json::Value res;
    res["status"] = 200;
    res["book"];
    auto db = drogon::app().getDbClient("qabuilder");
    Mapper<Books> mp(db);
    Books t = mp.findOne(Criteria(Books::Cols::_id, CompareOperator::EQ, bookid));
    res["book"] = t.toJson();
    return callback(drogon::HttpResponse::newHttpJsonResponse(res));
}
void question::updateBook(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int bookid)
{
    Json::Value res;
    res["status"] = 200;
    res["res"] = false;
    auto reqctx = req->getJsonObject();
    if (!reqctx)
        return callback(drogon::HttpResponse::newNotFoundResponse());
    try
    {
        auto db = drogon::app().getDbClient("qabuilder");
        Mapper<Books> mp(db);
        Books t = mp.findOne(Criteria(Books::Cols::_id, CompareOperator::EQ, bookid));
        if (reqctx->isMember("name"))
            t.setName((*reqctx)["name"].asString());
        if (reqctx->isMember("description"))
            t.setDescription((*reqctx)["description"].asString());
        mp.update(t);
        res["res"] = true;
    }
    catch (...)
    {
    }
    callback(drogon::HttpResponse::newHttpJsonResponse(res));
}
void question::newBook(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    Json::Value res;
    res["status"] = 200;
    auto reqctx = req->getJsonObject();
    if (!reqctx || (*reqctx).isMember("id"))
        return callback(drogon::HttpResponse::newNotFoundResponse());
    Books a;
    auto db = drogon::app().getDbClient("qabuilder");
    a.updateByJson(*reqctx);
    try
    {
        Mapper<Books> mp(db);
        mp.insert(a);
    }
    catch (...)
    {
        res["status"] = 500;
    }
    callback(drogon::HttpResponse::newHttpJsonResponse(res));
}
void question::removeBook(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int bookid)
{
    // 注意, 如果存在相关单元就不能删书
    Json::Value res;
    res["status"] = 200;
    auto db = drogon::app().getDbClient("qabuilder");
    Mapper<Books> mpb(db);
    Books tbd = mpb.findOne(Criteria(Books::Cols::_id, CompareOperator::EQ, bookid));
    Mapper<Chapters> mpc(db);
    std::vector<Chapters> c = mpc.findBy(Criteria(Chapters::Cols::_bookid, CompareOperator::EQ, bookid));
    if (c.size() > 0)
    {
        res["status"] = 403;
        res["error"] = "Chapters related to that book exists. Try delete them first.";
        return callback(drogon::HttpResponse::newHttpJsonResponse(res));
    }
    else
    {
        mpb.deleteOne(tbd);
        return callback(drogon::HttpResponse::newHttpJsonResponse(res));
    }
}
void question::getChapter(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int chapterid)
{
    Json::Value res;
    res["status"] = 200;
    res["chapter"];
    auto db = drogon::app().getDbClient("qabuilder");
    Mapper<Chapters> mp(db);
    Chapters t = mp.findOne(Criteria(Chapters::Cols::_id, CompareOperator::EQ, chapterid));
    res["chapter"] = t.toJson();
    return callback(drogon::HttpResponse::newHttpJsonResponse(res));
}
void question::updateChapter(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int chapterid)
{
    Json::Value res;
    res["status"] = 200;
    res["res"] = false;
    auto reqctx = req->getJsonObject();
    if (!reqctx)
        return callback(drogon::HttpResponse::newNotFoundResponse());
    try
    {
        auto db = drogon::app().getDbClient("qabuilder");
        Mapper<Chapters> mp(db);
        Chapters t = mp.findOne(Criteria(Chapters::Cols::_id, CompareOperator::EQ, chapterid));
        if (reqctx->isMember("name"))
            t.setName((*reqctx)["name"].asString());
        if (reqctx->isMember("description"))
            t.setDescription((*reqctx)["description"].asString());
        if (reqctx->isMember("bookid"))
            t.setBookid((*reqctx)["bookid"].asInt());
        mp.update(t);
        res["res"] = true;
    }
    catch (...)
    {
    }
    callback(drogon::HttpResponse::newHttpJsonResponse(res));
}
void question::newChapter(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    Json::Value res;
    res["status"] = 200;
    auto reqctx = req->getJsonObject();
    if (!reqctx || (*reqctx).isMember("id"))
        return callback(drogon::HttpResponse::newNotFoundResponse());
    Chapters a;
    auto db = drogon::app().getDbClient("qabuilder");
    a.updateByJson(*reqctx);
    try
    {
        Mapper<Chapters> mp(db);
        mp.insert(a);
    }
    catch (...)
    {
        res["status"] = 500;
    }
    callback(drogon::HttpResponse::newHttpJsonResponse(res));
}
void question::removeChapter(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int chapterid)
{
    // 注意, 如果存在相关题目就不能删单元
    Json::Value res;
    res["status"] = 200;
    auto db = drogon::app().getDbClient("qabuilder");
    Mapper<Chapters> mpb(db);
    Chapters tbd = mpb.findOne(Criteria(Chapters::Cols::_id, CompareOperator::EQ, chapterid));
    Mapper<Qa> mpc(db);
    std::vector<Qa> c = mpc.findBy(Criteria(Qa::Cols::_chapter, CompareOperator::EQ, chapterid));
    if (c.size() > 0)
    {
        res["status"] = 403;
        res["error"] = "Questions related to that chapter exists. Try delete them first.";
        return callback(drogon::HttpResponse::newHttpJsonResponse(res));
    }
    else
    {
        mpb.deleteOne(tbd);
        return callback(drogon::HttpResponse::newHttpJsonResponse(res));
    }
}
void question::getQuestion(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int questionid)
{
    Json::Value res;
    res["status"] = 200;
    res["question"];
    auto db = drogon::app().getDbClient("qabuilder");
    Mapper<Qa> mp(db);
    Qa t = mp.findOne(Criteria(Qa::Cols::_id, CompareOperator::EQ, questionid));
    res["question"] = t.toJson();
    return callback(drogon::HttpResponse::newHttpJsonResponse(res));
}
void question::updateQuestion(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int questionid)
{
    Json::Value res;
    res["status"] = 200;
    res["res"] = false;
    auto reqctx = req->getJsonObject();
    if (!reqctx)
        return callback(drogon::HttpResponse::newNotFoundResponse());
    try
    {
        auto db = drogon::app().getDbClient("qabuilder");
        Mapper<Qa> mp(db);
        Qa t = mp.findOne(Criteria(Qa::Cols::_id, CompareOperator::EQ, questionid));
        if (reqctx->isMember("content"))
            t.setContent((*reqctx)["content"].asString());
        if (reqctx->isMember("answer"))
            t.setAnswer((*reqctx)["answer"].asString());
        if (reqctx->isMember("comment"))
            t.setComment((*reqctx)["comment"].asString());
        if (reqctx->isMember("book"))
            t.setBook((*reqctx)["book"].asInt());
        if (reqctx->isMember("chapter"))
            t.setChapter((*reqctx)["chapter"].asInt());
        mp.update(t);
        res["res"] = true;
    }
    catch (...)
    {
    }
    callback(drogon::HttpResponse::newHttpJsonResponse(res));
}
void question::newQuestion(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    Json::Value res;
    res["status"] = 200;
    auto reqctx = req->getJsonObject();
    if (!reqctx || (*reqctx).isMember("id"))
        return callback(drogon::HttpResponse::newNotFoundResponse());
    Qa a;
    auto db = drogon::app().getDbClient("qabuilder");
    a.updateByJson(*reqctx);
    try
    {
        Mapper<Qa> mp(db);
        mp.insert(a);
    }
    catch (...)
    {
        res["status"] = 500;
    }
    callback(drogon::HttpResponse::newHttpJsonResponse(res));
}
void question::removeQuestion(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int questionid)
{
    Json::Value res;
    res["status"] = 200;
    auto db = drogon::app().getDbClient("qabuilder");
    Mapper<Qa> mpb(db);
    Qa tbd = mpb.findOne(Criteria(Qa::Cols::_id, CompareOperator::EQ, questionid));
    mpb.deleteOne(tbd);
    return callback(drogon::HttpResponse::newHttpJsonResponse(res));
}
