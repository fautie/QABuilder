#include "api_user.h"

#include "../db/Users.h"

using namespace api;
using namespace drogon_model::qabuilder;
// add definition of your processing function here
void user::newUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, std::string username)
{
    auto db = drogon::app().getDbClient("qabuilder");
    Mapper<Users> mp(db);
    if (mp.findBy(Criteria(Users::Cols::_username, CompareOperator::EQ, username)).size() == 0)
    {
        auto ptr = req->getJsonObject();
        if (!ptr)
            return callback(drogon::HttpResponse::newNotFoundResponse());
        Users newuser;
        newuser.updateByJson(*ptr);
        mp.insert(newuser);
    };
    return callback(HttpResponse::newHttpResponse());
}
void user::changePriv(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, std::string username)
{
    auto db = drogon::app().getDbClient("qabuilder");
    Mapper<Users> mp(db);
    auto user = mp.findOne(Criteria(Users::Cols::_username, CompareOperator::EQ, username));
    auto ptr = req->getJsonObject();
    if (!ptr)
        return callback(HttpResponse::newNotFoundResponse());
    user.setPriv((*ptr)["priv"].asInt());
    callback(HttpResponse::newHttpResponse());
}
void user::changePassword(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    auto db = drogon::app().getDbClient("qabuilder");
    Mapper<Users> mp(db);
    auto user = mp.findOne(Criteria(Users::Cols::_username, CompareOperator::EQ,
                                    (*(req->session()->get<std::shared_ptr<Json::Value>>("loginInfo")))["username"].asString()));
    auto ptr = req->getJsonObject();
    if (!ptr)
        return callback(HttpResponse::newNotFoundResponse());
    user.setPassword((*ptr)["password"].asString());
    callback(HttpResponse::newHttpResponse());
}
void user::remove(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, std::string username)
{
    auto db = drogon::app().getDbClient("qabuilder");
    Mapper<Users> mp(db);
    if (mp.findBy(Criteria(Users::Cols::_username, CompareOperator::EQ, username)).size() != 0)
        mp.deleteOne(mp.findOne(Criteria(Users::Cols::_username, CompareOperator::EQ, username)));
    return callback(HttpResponse::newHttpResponse());
}
void user::regist(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, std::string username)
{
    auto db = drogon::app().getDbClient("qabuilder");
    Mapper<Users> mp(db);
    if (mp.findBy(Criteria(Users::Cols::_username, CompareOperator::EQ, username)).size() == 0)
    {
        auto ptr = req->getJsonObject();
        if (!ptr)
            return callback(drogon::HttpResponse::newNotFoundResponse());
        Users newuser;
        newuser.updateByJson(*ptr);
        mp.insert(newuser);
    };
    return callback(HttpResponse::newHttpResponse());
}
