/**
 *
 *  loginFilter.cc
 *
 */

#include "loginFilter.h"

using namespace drogon;

void loginFilter::doFilter(const HttpRequestPtr &req,
                         FilterCallback &&fcb,
                         FilterChainCallback &&fccb)
{
    if (req->session()&&req->session()->find("loginInfo"))
    {
        //Passed
        fccb();
        return;
    }
    //Check failed
    auto res = drogon::HttpResponse::newHttpResponse();
    res->setStatusCode(k500InternalServerError);
    fcb(res);
}
