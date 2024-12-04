


# file(GLOB view_sources *.cpp)
# target_sources(EMBEDDED-GUI PRIVATE ${view_sources})


add_library(controller STATIC time-helper.cpp vocabulary-manager.cpp)
target_include_directories(controller PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${JSONCPP_INCLUDE_DIRS} libs model)

target_link_libraries(controller ${JSONCPP_LIBRARIES} libs model)