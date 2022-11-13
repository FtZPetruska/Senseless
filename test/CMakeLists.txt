find_package(Catch2 3)

add_executable(test_GeometryUtilities "test_GeometryUtilities.cpp")
target_link_libraries(test_GeometryUtilities PRIVATE Catch2::Catch2WithMain game)
apply_options_to_target(test_GeometryUtilities)

include(Catch)
catch_discover_tests(test_GeometryUtilities)
