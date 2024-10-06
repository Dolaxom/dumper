#pragma once

#include <string_view>
#include <string>

namespace model {

struct ISerializable {
    virtual std::string ToJson(int dump = -1) const = 0;
    virtual void FromJson(std::string_view json_str) = 0;
};

struct Server : ISerializable {
    std::string id {"0"};
    std::string name {"sample"};

    std::string ToJson(int dump = -1) const override;
    void FromJson(std::string_view json_str) override;
};

struct Channel : ISerializable {
    std::string id {"0"};
    std::string name {"sample"};

    std::string ToJson(int dump = -1) const override;
    void FromJson(std::string_view json_str) override;
};

struct Author : ISerializable {
    std::string id {"0"};
    std::string name {"sample"};

    std::string ToJson(int dump = -1) const override;
    void FromJson(std::string_view json_str) override;
};

struct Message : ISerializable {
    Server server;
    Channel channel;
    Author author;
    std::string content;

    std::string ToJson(int dump = -1) const override;
    void FromJson(std::string_view json_str) override;
};

} // namespace model
