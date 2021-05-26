#include "api_login.h"

#include "../db/Users.h"

#include <vector>
using namespace api;
using namespace drogon_model::qabuilder;
void login::asyncHandleHttpRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    Json::Value resctx;
    resctx["status"] = 200;
    resctx["UserInfo"];
    if (req->session()->find("loginInfo"))
    {
        resctx["UserInfo"] = *(req->session()->get<std::shared_ptr<Json::Value>>("loginInfo"));
    }
    else
    {
        auto reqctx = req->getJsonObject();
        if (!reqctx || !(*reqctx).isMember("username") || !(*reqctx).isMember("password"))
        {
            resctx["UserInfo"] = false;
            return callback(drogon::HttpResponse::newHttpJsonResponse(resctx));
        }
        auto db = drogon::app().getDbClient("qabuilder");
        Mapper<Users> mp(db);
        try
        {
            Users t = mp.findOne(Criteria("username", CompareOperator::EQ, (*reqctx)["username"].asString()));
            if (t.getValueOfPassword() != (*reqctx)["password"].asString())
                resctx["UserInfo"] = false;
            else
            {
                std::shared_ptr<Json::Value> userinfo = std::make_shared<Json::Value>();
                (*userinfo)["username"] = t.getValueOfUsername();
                (*userinfo)["priv"] = t.getValueOfPriv();
                req->session()->insert("loginInfo", userinfo);
                resctx["UserInfo"] = *userinfo;
            }
        }
        catch (...)
        {
            resctx["UserInfo"] = false;
        }
    }
    return callback(drogon::HttpResponse::newHttpJsonResponse(resctx));
}