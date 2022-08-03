find_package(nlohmann_json CONFIG REQUIRED)

add_library(PW_Common)
add_library(PW::COMMON ALIAS PW_Common)

target_sources(PW_Common
    PRIVATE
        base64.hpp
        EchoMessageRequest.cpp
        EchoMessageRequest.h
        EchoMessageResponse.cpp
        EchoMessageResponse.h
        GetInventoryMessageRequest.cpp
        GetInventoryMessageRequest.h
        GetInventoryMessageResponse.cpp
        GetInventoryMessageResponse.h
        PWBaseMessage.cpp
        PWBaseMessage.h
        PWBaseRequest.cpp
        PWBaseRequest.h
        PWBaseResponse.cpp
        PWBaseResponse.h
        PWCommDef.h
        PWException.cpp
        PWException.h
        PWMessageSerializationFactory.cpp
        PWMessageSerializationFactory.h
        PWMessageSerializer.cpp
        PWMessageSerializer.h
        PWMessageTypes.h
)

target_include_directories(PW_Common 
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(PW_Common
    PUBLIC
        nlohmann_json::nlohmann_json
)
