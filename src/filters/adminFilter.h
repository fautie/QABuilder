/**
 *
 *  adminFilter.h
 *
 */

#pragma once

#include <drogon/HttpFilter.h>
using namespace drogon;

class adminFilter : public HttpFilter<adminFilter>
{
  public:
    adminFilter()
    {
    }
    virtual void doFilter(const HttpRequestPtr &req, FilterCallback &&fcb, FilterChainCallback &&fccb) override;
};
