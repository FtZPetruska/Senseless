set(TEST_NAMES
    "PointTest"
    "RectangleTest"
    "SegmentTest"
    "ShapeTest"
    "Vec2Test")

foreach(TEST_NAME ${TEST_NAMES})
  add_executable("${TEST_NAME}" "${TEST_NAME}.cpp")
  target_link_libraries("${TEST_NAME}" PRIVATE Catch2::Catch2WithMain game)
  apply_options_to_target("${TEST_NAME}")
  catch_discover_tests("${TEST_NAME}")
endforeach()
