#pragma once
#include <drogon/HttpController.h>
using namespace drogon;
namespace api
{
    class question : public drogon::HttpController<question>
    {
      public:
        METHOD_LIST_BEGIN
        METHOD_ADD(question::makePaper, "/makePaper", Post);
        // Books API
        METHOD_ADD(question::getBooks, "/books", Get);
        METHOD_ADD(question::getBook, "/books/{1}", Get);
        METHOD_ADD(question::updateBook, "/books/{1}", Put, "loginFilter");
        METHOD_ADD(question::newBook, "/books", Post, "loginFilter");
        METHOD_ADD(question::removeBook, "/books/{1}", Delete, "loginFilter");
        // Chapters API
        METHOD_ADD(question::getChapters, "/chapters/{1}", Get);
        //METHOD_ADD(question::getChapter, "/chapters/{1}", Get);
        METHOD_ADD(question::updateChapter, "/chapters/{1}", Put, "loginFilter");
        METHOD_ADD(question::newChapter, "/chapters", Post, "loginFilter");
        METHOD_ADD(question::removeChapter, "/chapters/{1}", Delete, "loginFilter");
        // Questions API
        METHOD_ADD(question::getQuestions, "/questions/{1}", Get);
        METHOD_ADD(question::getQuestion, "/questions/{1}", Get);
        METHOD_ADD(question::updateQuestion, "/questions/{1}", Put, "loginFilter");
        METHOD_ADD(question::newQuestion, "/questions", Post, "loginFilter");
        METHOD_ADD(question::removeQuestion, "/questions/{1}", Delete, "loginFilter");

        METHOD_LIST_END
        void makePaper(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
        void getBooks(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
        void getBook(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int bookid);
        void updateBook(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int bookid);
        void newBook(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
        void removeBook(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int bookid);
        void getChapters(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int bookid);
        void getChapter(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int chapterid);
        void updateChapter(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int chapterid);
        void newChapter(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
        void removeChapter(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int chapterid);
        void getQuestions(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int chapterid);
        void getQuestion(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int questionid);
        void updateQuestion(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int questionid);
        void newQuestion(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
        void removeQuestion(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, int questionid);
    };
} // namespace api
