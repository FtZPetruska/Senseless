find_package(spdlog CONFIG REQUIRED)

add_library(game STATIC GeometricUtilities.cpp)
target_link_libraries(game PRIVATE spdlog::spdlog)
target_include_directories(game PUBLIC ${SL_PUBLIC_INCLUDE_DIR})
apply_options_to_target(game)
