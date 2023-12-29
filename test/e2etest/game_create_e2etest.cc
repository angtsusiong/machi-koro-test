#include <drogon/drogon.h>
#include <gtest/gtest.h>

static const std::string HTTP_ADDRESS = "http://127.0.0.1:8086";

class GameSetupE2ETest : public testing::Test {
protected:
  GameSetupE2ETest() {}

  ~GameSetupE2ETest() override {}

  void SetUp() override {}

  void TearDown() override {}

};

drogon::HttpRequestPtr GetRequestObj(const Json::Value& request_json,
                                     drogon::HttpMethod method, const std::string path)
{
    auto req = drogon::HttpRequest::newHttpJsonRequest(request_json);
    req->setMethod(method);
    req->setPath(path);
    return req;
}

drogon::HttpRequestPtr GetRequestObj(const std::string json_key_name,
                const std::string json_value_name, drogon::HttpMethod method, const std::string path)
{
    Json::Value request_json;
    request_json[json_key_name] = json_value_name;
    return GetRequestObj(request_json, method, path);
}

// GIVEN_empty_WHEN_createGame_THEN_success
TEST_F(GameSetupE2ETest, CreateGameSuccessfully)
{
}
