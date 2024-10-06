#include "message.hpp"
#include <utility>

namespace controllers::msg {

common::MessageWriter WriteMessage(const model::Message& msg) {
  common::MessageWriter data;
  data.SetData(std::move(msg.ToJson()));

  return data;
}

}  // controllers::msg
