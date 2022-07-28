project(PlantWorld
LANGUAGES
C CXX
)
add_subdirectory(PWCommon)
add_subdirectory(PWServer)

enable_testing()
add_subdirectory(PWTests)