add_library(
  game STATIC
  "Entity.cpp"
  "PhysicalObject.cpp"
  "Player.cpp"
  "GeometryUtilities/Point.cpp"
  "GeometryUtilities/Rectangle.cpp"
  "GeometryUtilities/Shape.cpp"
  "GeometryUtilities/Vec2.cpp")
target_include_directories(game PUBLIC ${SL_PUBLIC_INCLUDE_DIR})
apply_options_to_target(game)
