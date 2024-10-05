#include "schema.hpp"
#include <string_view>
#include <nlohmann/json.hpp>
#include <stdexcept>

using namespace std::string_literals;

namespace model {

void Server::FromJson(std::string_view json_str) {
    nlohmann::json data;
    try {
        data = nlohmann::json::parse(json_str);

        if (data.find("id") == data.end() || data.find("name") == data.end()) {
            Server server{};
            throw std::invalid_argument("Example of Json object from the Server struct: " + server.ToJson());
        }
    } catch (const std::exception& ex) {
        throw std::invalid_argument("Server::FromJson: "s + ex.what());
    }

    id = data.at("id").get<std::string>();
    name = data.at("name").get<std::string>();
}

void Channel::FromJson(std::string_view json_str) {
    nlohmann::json data;
    try {
        data = nlohmann::json::parse(json_str);

        if (data.find("id") == data.end() || data.find("name") == data.end()) {
            Channel channel{};
            throw std::invalid_argument("Channel::FromJson: Example of Json object from the Channel struct: " + channel.ToJson());
        }
    } catch (const std::exception& ex) {
        throw std::invalid_argument(ex.what());
    }

    id = data.at("id").get<std::string>();
    name = data.at("name").get<std::string>();
}

void Author::FromJson(std::string_view json_str) {
    nlohmann::json data;
    try {
        data = nlohmann::json::parse(json_str);

        if (data.find("id") == data.end() || data.find("name") == data.end()) {
            Author author{};
            throw std::invalid_argument("Author::FromJson: Example of Json object from the Author struct: " + author.ToJson());
        }
    } catch (const std::exception& ex) {
        throw std::invalid_argument(ex.what());
    }

    id = data.at("id").get<std::string>();
    name = data.at("name").get<std::string>();
}

void Message::FromJson(std::string_view json_str) {
    nlohmann::json data;
    try {
        data = nlohmann::json::parse(json_str);

        if (data.find("server") == data.end() || data.find("channel") == data.end()) {
            Server server{};
            throw std::invalid_argument("Message::FromJson: Example of Json object from the Server struct: " + server.ToJson());
        }
    } catch (const std::exception& ex) {
        throw std::invalid_argument(ex.what());
    }

    server.FromJson(data.at("server").dump());
    channel.FromJson(data.at("channel").dump());
    author.FromJson(data.at("author").dump());
    content = data.at("content").get<std::string>();
}

} // namespace model
