#include "message_handler.hpp"

#include <utility>

#include "message.hpp"

namespace controllers::msg {

std::string MessageHandler::HandleRequestThrow(const server::http::HttpRequest& request, server::request::RequestContext& /*request_context*/) const {
  using namespace std::string_literals;
  request.GetHttpResponse().SetContentType(http::content_type::kApplicationJson);

  try {
    model::Message user_message;
    user_message.FromJson(request.RequestBody());

    WriteMessage(std::as_const(user_message)).ToPostgres();
    return R"({"status":"ok"})"s;
  } catch (const std::exception& ex) {
    return R"({"status":")"s + ex.what() + R"("})"s;
  }
}

}  // namespace controllers::msg
