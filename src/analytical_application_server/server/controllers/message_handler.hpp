#pragma once

#include <userver/components/component_list.hpp>
#include <userver/server/handlers/http_handler_base.hpp>

#include <userver/utest/using_namespace_userver.hpp>

namespace controllers::msg {

class MessageHandler final : public server::handlers::HttpHandlerBase {
 public:
  static constexpr std::string_view kName = "handler-message";

  using HttpHandlerBase::HttpHandlerBase;

  std::string HandleRequestThrow(const server::http::HttpRequest& request, server::request::RequestContext&) const override;
};

}  // namespace controllers::msg