#include "Game.h"

void Game::getGame(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr &)> &&callback, std::string &&game_id)
{
    Json::Value ret;
    ret["result"] = "ok";
    ret["game_id"] = game_id;
    auto resp = drogon::HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}

void Game::createGame(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr &)> &&callback)
{
    auto jsonPtr = req->jsonObject();
    auto isValidName = [](const std::string& name) {
        if (name.size() < 1 || name.size() > 16) 
            return false;
        for (char ch : name)
            if (!std::isalnum(ch) && ch != '_' && ch != '-')
                return false;
        return true;
    };
    std::vector<std::string> playerNames;
    std::array<std::string, 4> playerNamesArray;
    if ((*jsonPtr)["playerNames"].isArray() && (*jsonPtr)["playerNames"].size() == 4)
        for (const auto& name : (*jsonPtr)["playerNames"])
            if (name.isString() && isValidName(name.asString()))
                playerNames.emplace_back(name.asString());
    if (playerNames.size() == 4)
        if (std::unordered_set<std::string>(playerNames.begin(), playerNames.end()).size() == 4)
            playerNamesArray = {playerNames[0], playerNames[1], playerNames[2], playerNames[3]};

    Json::Value ret;
    ret["result"] = "ok";
    ret["game_id"] = "123456";
    auto resp = drogon::HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}