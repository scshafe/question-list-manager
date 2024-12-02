


add_library(model STATIC vocabulary-retriever.cpp json-vocabulary-retriever.cpp)
target_include_directories(model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${JSONCPP_INCLUDE_DIRS})

target_link_libraries(model ${JSONCPP_LIBRARIES})