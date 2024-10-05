#pragma once

#include <string>

namespace model {

struct ISerializable {
    virtual std::string ToJson() = 0;
    virtual void FromJson() = 0;
};

struct Server : ISerializable {
    std::string id;
    std::string name;

    virtual std::string ToJson() override;
    virtual void FromJson() override;
};

struct Channel : ISerializable {
    std::string id;
    std::string name;

    virtual std::string ToJson() override;
    virtual void FromJson() override;
};

struct Author : ISerializable {
    std::string id;
    std::string name;

    virtual std::string ToJson() override;
    virtual void FromJson() override;
};

struct Message : ISerializable{
    Server server;
    Channel channel;
    Author author;
    std::string content;

    virtual std::string ToJson() override;
    virtual void FromJson() override;
};

} // namespace model
