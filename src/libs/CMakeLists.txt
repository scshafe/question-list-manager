

add_library(libs 
            STATIC 
            sentence-fetcher.cpp 
            groq-sentence-fetcher.cpp 
            my-json-helper.cpp 
            color-printer.h)

target_include_directories(libs 
                           PUBLIC 
                           ${CMAKE_CURRENT_SOURCE_DIR} 
                           ${JSONCPP_INCLUDE_DIRS})

target_link_libraries(libs ${JSONCPP_LIBRARIES})
