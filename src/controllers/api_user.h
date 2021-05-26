#pragma once
#include <drogon/HttpController.h>
using namespace drogon;
namespace api
{
    class user : public drogon::HttpController<user>
    {
      public:
        METHOD_LIST_BEGIN
        METHOD_ADD(user::newUser, "/new/{}", Put, "loginFilter", "adminFilter");
        METHOD_ADD(user::changePriv, "/priv/{}", Put, "loginFilter", "adminFilter");
        METHOD_ADD(user::changePassword, "/password", Put, "loginFilter");
        METHOD_ADD(user::remove, "/remove/{}", Delete, "loginFilter", "adminFilter");
        METHOD_ADD(user::regist, "/regist/{}", Put, "loginFilter");
        METHOD_LIST_END
        void newUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, std::string username);
        void changePriv(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, std::string username);
        void changePassword(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
        void remove(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, std::string username);
        void regist(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, std::string username);
    };
} // namespace api
