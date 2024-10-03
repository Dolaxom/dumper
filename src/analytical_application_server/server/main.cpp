#include <userver/components/minimal_server_component_list.hpp>
#include <userver/utest/using_namespace_userver.hpp>
#include <userver/utils/daemon_run.hpp>
 
#include <userver/utest/using_namespace_userver.hpp>
 
#include "controllers/message_handler.hpp"
 
int main(int argc, char* argv[]) {
  auto component_list = components::MinimalServerComponentList()
                            .Append<controllers::msg::MessageHandler>();

  return utils::DaemonMain(argc, argv, component_list);
}
