cmake_minimum_required(VERSION 3.15)
project(question-manager CXX)

find_package(JSONCPP REQUIRED)

add_executable(${PROJECT_NAME} src/controller/main.cpp)
target_link_libraries(${PROJECT_NAME} JsonCpp::JsonCpp)
