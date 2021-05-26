/**
 *
 *  Qa.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Qa.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon_model::qabuilder;

const std::string Qa::Cols::_id = "id";
const std::string Qa::Cols::_content = "content";
const std::string Qa::Cols::_answer = "answer";
const std::string Qa::Cols::_comment = "comment";
const std::string Qa::Cols::_book = "book";
const std::string Qa::Cols::_chapter = "chapter";
const std::string Qa::primaryKeyName = "id";
const bool Qa::hasPrimaryKey = true;
const std::string Qa::tableName = "qa";

const std::vector<typename Qa::MetaData> Qa::metaData_={
{"id","int32_t","int(11)",4,1,1,1},
{"content","std::string","text",0,0,0,0},
{"answer","std::string","text",0,0,0,0},
{"comment","std::string","text",0,0,0,0},
{"book","int32_t","int(255)",4,0,0,0},
{"chapter","int32_t","int(255)",4,0,0,0}
};
const std::string &Qa::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Qa::Qa(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            id_=std::make_shared<int32_t>(r["id"].as<int32_t>());
        }
        if(!r["content"].isNull())
        {
            content_=std::make_shared<std::string>(r["content"].as<std::string>());
        }
        if(!r["answer"].isNull())
        {
            answer_=std::make_shared<std::string>(r["answer"].as<std::string>());
        }
        if(!r["comment"].isNull())
        {
            comment_=std::make_shared<std::string>(r["comment"].as<std::string>());
        }
        if(!r["book"].isNull())
        {
            book_=std::make_shared<int32_t>(r["book"].as<int32_t>());
        }
        if(!r["chapter"].isNull())
        {
            chapter_=std::make_shared<int32_t>(r["chapter"].as<int32_t>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 6 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            id_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            content_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            answer_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            comment_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 4;
        if(!r[index].isNull())
        {
            book_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
        index = offset + 5;
        if(!r[index].isNull())
        {
            chapter_=std::make_shared<int32_t>(r[index].as<int32_t>());
        }
    }

}

Qa::Qa(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 6)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            content_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());

        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            answer_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());

        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            comment_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());

        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            book_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[4]].asInt64());
        }
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        dirtyFlag_[5] = true;
        if(!pJson[pMasqueradingVector[5]].isNull())
        {
            chapter_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[5]].asInt64());
        }
    }
}

Qa::Qa(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("content"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["content"].isNull())
        {
            content_=std::make_shared<std::string>(pJson["content"].asString());
        }
    }
    if(pJson.isMember("answer"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["answer"].isNull())
        {
            answer_=std::make_shared<std::string>(pJson["answer"].asString());
        }
    }
    if(pJson.isMember("comment"))
    {
        dirtyFlag_[3]=true;
        if(!pJson["comment"].isNull())
        {
            comment_=std::make_shared<std::string>(pJson["comment"].asString());
        }
    }
    if(pJson.isMember("book"))
    {
        dirtyFlag_[4]=true;
        if(!pJson["book"].isNull())
        {
            book_=std::make_shared<int32_t>((int32_t)pJson["book"].asInt64());
        }
    }
    if(pJson.isMember("chapter"))
    {
        dirtyFlag_[5]=true;
        if(!pJson["chapter"].isNull())
        {
            chapter_=std::make_shared<int32_t>((int32_t)pJson["chapter"].asInt64());
        }
    }
}

void Qa::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 6)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[0]].asInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            content_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            answer_=std::make_shared<std::string>(pJson[pMasqueradingVector[2]].asString());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            comment_=std::make_shared<std::string>(pJson[pMasqueradingVector[3]].asString());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            book_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[4]].asInt64());
        }
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        dirtyFlag_[5] = true;
        if(!pJson[pMasqueradingVector[5]].isNull())
        {
            chapter_=std::make_shared<int32_t>((int32_t)pJson[pMasqueradingVector[5]].asInt64());
        }
    }
}
                                                                    
void Qa::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<int32_t>((int32_t)pJson["id"].asInt64());
        }
    }
    if(pJson.isMember("content"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["content"].isNull())
        {
            content_=std::make_shared<std::string>(pJson["content"].asString());
        }
    }
    if(pJson.isMember("answer"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["answer"].isNull())
        {
            answer_=std::make_shared<std::string>(pJson["answer"].asString());
        }
    }
    if(pJson.isMember("comment"))
    {
        dirtyFlag_[3] = true;
        if(!pJson["comment"].isNull())
        {
            comment_=std::make_shared<std::string>(pJson["comment"].asString());
        }
    }
    if(pJson.isMember("book"))
    {
        dirtyFlag_[4] = true;
        if(!pJson["book"].isNull())
        {
            book_=std::make_shared<int32_t>((int32_t)pJson["book"].asInt64());
        }
    }
    if(pJson.isMember("chapter"))
    {
        dirtyFlag_[5] = true;
        if(!pJson["chapter"].isNull())
        {
            chapter_=std::make_shared<int32_t>((int32_t)pJson["chapter"].asInt64());
        }
    }
}

const int32_t &Qa::getValueOfId() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(id_)
        return *id_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Qa::getId() const noexcept
{
    return id_;
}
void Qa::setId(const int32_t &pId) noexcept
{
    id_ = std::make_shared<int32_t>(pId);
    dirtyFlag_[0] = true;
}



const typename Qa::PrimaryKeyType & Qa::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const std::string &Qa::getValueOfContent() const noexcept
{
    const static std::string defaultValue = std::string();
    if(content_)
        return *content_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Qa::getContent() const noexcept
{
    return content_;
}
void Qa::setContent(const std::string &pContent) noexcept
{
    content_ = std::make_shared<std::string>(pContent);
    dirtyFlag_[1] = true;
}
void Qa::setContent(std::string &&pContent) noexcept
{
    content_ = std::make_shared<std::string>(std::move(pContent));
    dirtyFlag_[1] = true;
}


void Qa::setContentToNull() noexcept
{
    content_.reset();
    dirtyFlag_[1] = true;
}


const std::string &Qa::getValueOfAnswer() const noexcept
{
    const static std::string defaultValue = std::string();
    if(answer_)
        return *answer_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Qa::getAnswer() const noexcept
{
    return answer_;
}
void Qa::setAnswer(const std::string &pAnswer) noexcept
{
    answer_ = std::make_shared<std::string>(pAnswer);
    dirtyFlag_[2] = true;
}
void Qa::setAnswer(std::string &&pAnswer) noexcept
{
    answer_ = std::make_shared<std::string>(std::move(pAnswer));
    dirtyFlag_[2] = true;
}


void Qa::setAnswerToNull() noexcept
{
    answer_.reset();
    dirtyFlag_[2] = true;
}


const std::string &Qa::getValueOfComment() const noexcept
{
    const static std::string defaultValue = std::string();
    if(comment_)
        return *comment_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Qa::getComment() const noexcept
{
    return comment_;
}
void Qa::setComment(const std::string &pComment) noexcept
{
    comment_ = std::make_shared<std::string>(pComment);
    dirtyFlag_[3] = true;
}
void Qa::setComment(std::string &&pComment) noexcept
{
    comment_ = std::make_shared<std::string>(std::move(pComment));
    dirtyFlag_[3] = true;
}


void Qa::setCommentToNull() noexcept
{
    comment_.reset();
    dirtyFlag_[3] = true;
}


const int32_t &Qa::getValueOfBook() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(book_)
        return *book_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Qa::getBook() const noexcept
{
    return book_;
}
void Qa::setBook(const int32_t &pBook) noexcept
{
    book_ = std::make_shared<int32_t>(pBook);
    dirtyFlag_[4] = true;
}


void Qa::setBookToNull() noexcept
{
    book_.reset();
    dirtyFlag_[4] = true;
}


const int32_t &Qa::getValueOfChapter() const noexcept
{
    const static int32_t defaultValue = int32_t();
    if(chapter_)
        return *chapter_;
    return defaultValue;
}
const std::shared_ptr<int32_t> &Qa::getChapter() const noexcept
{
    return chapter_;
}
void Qa::setChapter(const int32_t &pChapter) noexcept
{
    chapter_ = std::make_shared<int32_t>(pChapter);
    dirtyFlag_[5] = true;
}


void Qa::setChapterToNull() noexcept
{
    chapter_.reset();
    dirtyFlag_[5] = true;
}


void Qa::updateId(const uint64_t id)
{
    id_ = std::make_shared<int32_t>(static_cast<int32_t>(id));
}

const std::vector<std::string> &Qa::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "content",
        "answer",
        "comment",
        "book",
        "chapter"
    };
    return inCols;
}

void Qa::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getContent())
        {
            binder << getValueOfContent();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getAnswer())
        {
            binder << getValueOfAnswer();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getComment())
        {
            binder << getValueOfComment();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getBook())
        {
            binder << getValueOfBook();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[5])
    {
        if(getChapter())
        {
            binder << getValueOfChapter();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Qa::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    if(dirtyFlag_[2])
    {
        ret.push_back(getColumnName(2));
    }
    if(dirtyFlag_[3])
    {
        ret.push_back(getColumnName(3));
    }
    if(dirtyFlag_[4])
    {
        ret.push_back(getColumnName(4));
    }
    if(dirtyFlag_[5])
    {
        ret.push_back(getColumnName(5));
    }
    return ret;
}

void Qa::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getContent())
        {
            binder << getValueOfContent();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getAnswer())
        {
            binder << getValueOfAnswer();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getComment())
        {
            binder << getValueOfComment();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getBook())
        {
            binder << getValueOfBook();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[5])
    {
        if(getChapter())
        {
            binder << getValueOfChapter();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Qa::toJson() const
{
    Json::Value ret;
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getContent())
    {
        ret["content"]=getValueOfContent();
    }
    else
    {
        ret["content"]=Json::Value();
    }
    if(getAnswer())
    {
        ret["answer"]=getValueOfAnswer();
    }
    else
    {
        ret["answer"]=Json::Value();
    }
    if(getComment())
    {
        ret["comment"]=getValueOfComment();
    }
    else
    {
        ret["comment"]=Json::Value();
    }
    if(getBook())
    {
        ret["book"]=getValueOfBook();
    }
    else
    {
        ret["book"]=Json::Value();
    }
    if(getChapter())
    {
        ret["chapter"]=getValueOfChapter();
    }
    else
    {
        ret["chapter"]=Json::Value();
    }
    return ret;
}

Json::Value Qa::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 6)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getId())
            {
                ret[pMasqueradingVector[0]]=getValueOfId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getContent())
            {
                ret[pMasqueradingVector[1]]=getValueOfContent();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getAnswer())
            {
                ret[pMasqueradingVector[2]]=getValueOfAnswer();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getComment())
            {
                ret[pMasqueradingVector[3]]=getValueOfComment();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[4].empty())
        {
            if(getBook())
            {
                ret[pMasqueradingVector[4]]=getValueOfBook();
            }
            else
            {
                ret[pMasqueradingVector[4]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[5].empty())
        {
            if(getChapter())
            {
                ret[pMasqueradingVector[5]]=getValueOfChapter();
            }
            else
            {
                ret[pMasqueradingVector[5]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getId())
    {
        ret["id"]=getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getContent())
    {
        ret["content"]=getValueOfContent();
    }
    else
    {
        ret["content"]=Json::Value();
    }
    if(getAnswer())
    {
        ret["answer"]=getValueOfAnswer();
    }
    else
    {
        ret["answer"]=Json::Value();
    }
    if(getComment())
    {
        ret["comment"]=getValueOfComment();
    }
    else
    {
        ret["comment"]=Json::Value();
    }
    if(getBook())
    {
        ret["book"]=getValueOfBook();
    }
    else
    {
        ret["book"]=Json::Value();
    }
    if(getChapter())
    {
        ret["chapter"]=getValueOfChapter();
    }
    else
    {
        ret["chapter"]=Json::Value();
    }
    return ret;
}

bool Qa::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if(pJson.isMember("content"))
    {
        if(!validJsonOfField(1, "content", pJson["content"], err, true))
            return false;
    }
    if(pJson.isMember("answer"))
    {
        if(!validJsonOfField(2, "answer", pJson["answer"], err, true))
            return false;
    }
    if(pJson.isMember("comment"))
    {
        if(!validJsonOfField(3, "comment", pJson["comment"], err, true))
            return false;
    }
    if(pJson.isMember("book"))
    {
        if(!validJsonOfField(4, "book", pJson["book"], err, true))
            return false;
    }
    if(pJson.isMember("chapter"))
    {
        if(!validJsonOfField(5, "chapter", pJson["chapter"], err, true))
            return false;
    }
    return true;
}
bool Qa::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector,
                                            std::string &err)
{
    if(pMasqueradingVector.size() != 6)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty())
      {
          if(pJson.isMember(pMasqueradingVector[0]))
          {
              if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[1].empty())
      {
          if(pJson.isMember(pMasqueradingVector[1]))
          {
              if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[2].empty())
      {
          if(pJson.isMember(pMasqueradingVector[2]))
          {
              if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[3].empty())
      {
          if(pJson.isMember(pMasqueradingVector[3]))
          {
              if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[4].empty())
      {
          if(pJson.isMember(pMasqueradingVector[4]))
          {
              if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[5].empty())
      {
          if(pJson.isMember(pMasqueradingVector[5]))
          {
              if(!validJsonOfField(5, pMasqueradingVector[5], pJson[pMasqueradingVector[5]], err, true))
                  return false;
          }
      }
    }
    catch(const Json::LogicError &e) 
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Qa::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("content"))
    {
        if(!validJsonOfField(1, "content", pJson["content"], err, false))
            return false;
    }
    if(pJson.isMember("answer"))
    {
        if(!validJsonOfField(2, "answer", pJson["answer"], err, false))
            return false;
    }
    if(pJson.isMember("comment"))
    {
        if(!validJsonOfField(3, "comment", pJson["comment"], err, false))
            return false;
    }
    if(pJson.isMember("book"))
    {
        if(!validJsonOfField(4, "book", pJson["book"], err, false))
            return false;
    }
    if(pJson.isMember("chapter"))
    {
        if(!validJsonOfField(5, "chapter", pJson["chapter"], err, false))
            return false;
    }
    return true;
}
bool Qa::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                          const std::vector<std::string> &pMasqueradingVector,
                                          std::string &err)
{
    if(pMasqueradingVector.size() != 6)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
      {
          if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
              return false;
      }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
      if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
      {
          if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
              return false;
      }
      if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
      {
          if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, false))
              return false;
      }
      if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
      {
          if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, false))
              return false;
      }
      if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
      {
          if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, false))
              return false;
      }
      if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
      {
          if(!validJsonOfField(5, pMasqueradingVector[5], pJson[pMasqueradingVector[5]], err, false))
              return false;
      }
    }
    catch(const Json::LogicError &e) 
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Qa::validJsonOfField(size_t index,
                          const std::string &fieldName,
                          const Json::Value &pJson, 
                          std::string &err, 
                          bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(isForCreation)
            {
                err="The automatic primary key cannot be set";
                return false;
            }        
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 1:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;                
            }
            break;
        case 2:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;                
            }
            break;
        case 3:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;                
            }
            break;
        case 4:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 5:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isInt())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
     
        default:
            err="Internal error in the server";
            return false;
            break;
    }
    return true;
}
