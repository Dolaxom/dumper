#pragma once

#include <string>
#include "../models/schema.hpp"

namespace controllers::msg {

std::string WriteMessage(const model::Message& msg);

}  // namespace controllers::msg
