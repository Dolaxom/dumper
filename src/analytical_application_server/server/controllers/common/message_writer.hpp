#pragma once

#include <string_view>
#include <string>

namespace common {

class MessageWriter {
public:
  void ToPostgres() {

  }

  void ToRedis() {

  }

  std::string GetData() const noexcept {
    return data_;
  }

  void SetData(const std::string& data) {
   data_ = data;
  }


private:
  std::string data_;
};

} // namespace common
