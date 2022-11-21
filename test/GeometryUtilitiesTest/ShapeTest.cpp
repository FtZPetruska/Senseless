#include <catch2/catch_test_macros.hpp>

#include "GeometryUtilities.hpp"

#include <stdexcept>
#include <vector>

using namespace GameLib;

TEST_CASE("Shape constructor precondition failure", "[Shape]") {
  const std::vector<Point> NOT_ENOUGH_VERTICES{{0, 0}};
  REQUIRE_THROWS_AS(Shape(NOT_ENOUGH_VERTICES), std::logic_error);
}

TEST_CASE("Shape normalise vertices", "[Shape]") {
  const std::vector<Point> STARTING_VERTICES{{1, 0}, {2, 0}, {2, 1}};
  const std::vector<Point> EXPECTED_VERTICES{{0, 0}, {1, 0}, {1, 1}};
  const Shape TEST_SHAPE(STARTING_VERTICES);
  REQUIRE(TEST_SHAPE.getNormalisedVertices() == EXPECTED_VERTICES);
}

TEST_CASE("Shape moved in diagonal", "[Shape]") {
  const std::vector<Point> STARTING_VERTICES{{0, 0}, {1, 0}, {1, 1}};
  const std::vector<Point> EXPECTED_VERTICES{{1, 1}, {2, 1}, {2, 2}};
  const Vec2 TRANSLATION{1.0, 1.0};
  Shape test_shape(STARTING_VERTICES);
  test_shape.move(TRANSLATION);
  REQUIRE(test_shape.getVertices() == EXPECTED_VERTICES);
}

TEST_CASE("Shape not moved", "[Shape]") {
  const std::vector<Point> STARTING_VERTICES{{0, 0}, {1, 0}, {1, 1}};
  const Vec2 TRANSLATION{0.0, 0.0};
  Shape test_shape(STARTING_VERTICES);
  test_shape.move(TRANSLATION);
  REQUIRE(test_shape.getVertices() == STARTING_VERTICES);
}

TEST_CASE("Shape collision from above", "[Shape]") {
  const Shape TEST_SHAPE({{-3, 0}, {3, 0}, {0, 2}});
  const Shape MOVING_SHAPE({{-2, 5}, {2, 5}, {0, 3}});
  const Vec2 TRANSLATION{0.0, -2.0};
  REQUIRE(TEST_SHAPE.wouldShapeCollideAfterMovement(MOVING_SHAPE, TRANSLATION) == CollisionDirection::DOWN);
}

TEST_CASE("Shape equal", "[Shape]") {
  const Shape FIRST_SHAPE({{-3, 0}, {3, 0}, {0, 2}});
  const Shape SECOND_SHAPE({{3, 5}, {9, 5}, {6, 7}});
  REQUIRE(FIRST_SHAPE == SECOND_SHAPE);
}

TEST_CASE("Shape not equal", "[Shape]") {
  const Shape FIRST_SHAPE({{-3, 0}, {3, 0}, {0, 2}});
  const Shape SECOND_SHAPE({{-2, 5}, {2, 5}, {0, 3}});
  REQUIRE(FIRST_SHAPE != SECOND_SHAPE);
}
