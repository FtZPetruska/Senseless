add_library(
  game STATIC
  "Entities/Doorman.cpp"
  "Entities/Entity.cpp"
  "Entities/EntityFactory.cpp"
  "Entities/Luis.cpp"
  "Entities/Magnetick.cpp"
  "Entities/Player.cpp"
  "Entities/Stalker.cpp"
  "Entities/Vagrant.cpp"
  "PhysicalObject.cpp"
  "Player.cpp"
  "GeometryUtilities/Point.cpp"
  "GeometryUtilities/Rectangle.cpp"
  "GeometryUtilities/Shape.cpp"
  "GeometryUtilities/Vec2.cpp"
  "GeometryUtilities/Segment.cpp")
target_include_directories(game PUBLIC ${SL_PUBLIC_INCLUDE_DIR})
apply_options_to_target(game)
