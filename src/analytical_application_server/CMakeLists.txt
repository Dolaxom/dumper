cmake_minimum_required(VERSION 3.22)
project(DAAS CXX) # Dumper Analyzer Application Server
 
find_package(userver COMPONENTS core REQUIRED)
find_package(nlohmann_json REQUIRED)

add_library(${PROJECT_NAME}_objs OBJECT
    server/controllers/message.cpp
    server/controllers/message.hpp
    server/controllers/message_handler.cpp
    server/controllers/message_handler.hpp

    server/models/schema.hpp
    server/models/serialization.hpp
    server/models/deserialization.hpp
)

target_link_libraries(${PROJECT_NAME}_objs userver::core nlohmann_json::nlohmann_json)
target_include_directories(${PROJECT_NAME}_objs PUBLIC src)

add_executable(${PROJECT_NAME} server/main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_objs)

userver_testsuite_add_simple()
