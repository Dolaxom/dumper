#include "schema.hpp"
#include <nlohmann/json.hpp>

namespace model {

std::string Server::ToJson() const {
  nlohmann::json data;

  data["id"] = id;
  data["name"] = name;

  return data.dump();
}

std::string Channel::ToJson() const {
  nlohmann::json data;

  data["id"] = id;
  data["name"] = name;

  return data.dump();
}

std::string Author::ToJson() const {
  nlohmann::json data;

  data["id"] = id;
  data["name"] = name;

  return data.dump();
}

std::string Message::ToJson() const {
  using json = nlohmann::json;
  json data;

  json server_data;
  server_data["id"] = server.id;
  server_data["name"] = server.name;

  json channel_data;
  channel_data["id"] = channel.id;
  channel_data["name"] = channel.name;

  json author_data;
  author_data["id"] = author.id;
  author_data["name"] = author.name;

  data["server"] = server_data;
  data["channel"] = channel_data;
  data["author"] = author_data;
  data["content"] = content;

  return data.dump();
}

} // namespace model
