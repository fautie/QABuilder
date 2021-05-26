/**
 *
 *  adminFilter.cc
 *
 */

#include "adminFilter.h"

using namespace drogon;

void adminFilter::doFilter(const HttpRequestPtr &req, FilterCallback &&fcb, FilterChainCallback &&fccb)
{
    // Edit your logic here
    if (req->session() && ((*(req->session()->get<std::shared_ptr<Json::Value>>("loginInfo")))["priv"].asInt() == 1))
    {
        // Passed
        fccb();
        return;
    }
    // Check failed
    auto res = drogon::HttpResponse::newHttpResponse();
    res->setStatusCode(k500InternalServerError);
    fcb(res);
}
