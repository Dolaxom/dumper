#include "schema.hpp"
#include <nlohmann/json.hpp>

namespace model {

std::string Server::ToJson(int dump) const {
  nlohmann::json data;

  data["id"] = id;
  data["name"] = name;

  return data.dump(dump);
}

std::string Channel::ToJson(int dump) const {
  nlohmann::json data;

  data["id"] = id;
  data["name"] = name;

  return data.dump(dump);
}

std::string Author::ToJson(int dump) const {
  nlohmann::json data;

  data["id"] = id;
  data["name"] = name;

  return data.dump(dump);
}

std::string Message::ToJson(int dump) const {
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

  return data.dump(dump);
}

} // namespace model
