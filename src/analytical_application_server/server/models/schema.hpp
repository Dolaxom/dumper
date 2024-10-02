#pragma once

#include <string>

namespace model {

struct BaseSchema {
    std::string id;
    std::string name;
};

struct Server : BaseSchema {

};

struct Channel : BaseSchema {

};

struct Author : BaseSchema {

};

struct Message {
    Server server;
    Channel channel;
    Author author;

    std::string content;
};

} // namespace model

