#pragma once

#include <string>
#include "common/message_writer.hpp"
#include "../models/schema.hpp"

namespace controllers::msg {

common::MessageWriter WriteMessage(const model::Message& msg);

}  // namespace controllers::msg
