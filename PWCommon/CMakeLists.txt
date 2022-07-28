find_package(nlohmann_json REQUIRED)

add_library(PW_Common)
add_library(PW::COMMON ALIAS PW_Common)

target_sources(PW_Common
    PRIVATE
        base64.hpp

        PWCommDef.h
        PWException.cpp
        PWException.h
)

target_include_directories(PW_Common 
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(PW_Common
    PUBLIC
        nlohmann_json::nlohmann_json
)
