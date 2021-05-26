#pragma once
#include <drogon/HttpSimpleController.h>
using namespace drogon;
namespace api
{
class login:public drogon::HttpSimpleController<login>
{
  public:
    virtual void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    //list path definitions here;
    //PATH_ADD("/path","filter1","filter2",HttpMethod1,HttpMethod2...);
    PATH_ADD("/api/login",Post);
    PATH_LIST_END
};
}
