
find_package(nlohmann_json REQUIRED)

FILE(GLOB PwServer_ALLFILES PWInventory.cpp)
add_library(PW_Server ${PwServer_ALLFILES})

add_library(PW::SERVER ALIAS PW_Server )

target_link_libraries(PW_Server nlohmann_json::nlohmann_json PW::COMMON)
target_include_directories(PW_Server 
PUBLIC
${CMAKE_CURRENT_LIST_DIR}
)

add_executable(PWServerExe main.cpp)
target_link_libraries(PWServerExe PW::SERVER)