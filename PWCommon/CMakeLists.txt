
find_package(nlohmann_json REQUIRED)

FILE(GLOB PwCommon_ALLFILES ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
add_library(PW_Common ${PwCommon_ALLFILES})

target_include_directories(PW_Common 
PUBLIC
${CMAKE_CURRENT_LIST_DIR}
)
add_library(PW::COMMON ALIAS PW_Common)

target_link_libraries(PW_Common nlohmann_json::nlohmann_json)