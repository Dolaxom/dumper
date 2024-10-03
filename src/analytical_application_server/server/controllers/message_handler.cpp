#include "message_handler.hpp"
#include "message.hpp"

#include <utility>

namespace controllers::msg {

std::string MessageHandler::HandleRequestThrow(const server::http::HttpRequest& request, server::request::RequestContext& /*request_context*/) const {
  request.GetHttpResponse().SetContentType(http::content_type::kTextPlain);
  model::Message msg;

  return WriteMessage(std::as_const(msg));
}

}  // namespace controllers::msg
