#pragma once

#include <drogon/HttpController.h>

class Game : public drogon::HttpController<Game>
{
  public:
    METHOD_LIST_BEGIN
    // use METHOD_ADD to add your custom processing function here;
    METHOD_ADD(Game::getGame, "/{1}", drogon::Get);
    METHOD_ADD(Game::createGame, "/", drogon::Post);
    // METHOD_ADD(Game::get, "/{2}/{1}", Get); // path is /Game/{arg2}/{arg1}
    // METHOD_ADD(Game::your_method_name, "/{1}/{2}/list", Get); // path is /Game/{arg1}/{arg2}/list
    // ADD_METHOD_TO(Game::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list

    METHOD_LIST_END
    
    void getGame(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr &)> &&callback, std::string &&game_id);
    void createGame(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr &)> &&callback);
    // your declaration of processing function maybe like this:
    // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
    // void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;
};
