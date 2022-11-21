#include <catch2/catch_test_macros.hpp>

#include "GeometryUtilities.hpp"

#include <stdexcept>
#include <vector>

using namespace GameLib;

TEST_CASE("Rectangle constructor width precondition failure", "[Rectangle]") {
  const Point ORIGIN{0, 0};
  const int BAD_WIDTH{0};
  const int HEIGHT{1};
  REQUIRE_THROWS_AS(Rectangle(ORIGIN, BAD_WIDTH, HEIGHT), std::logic_error);
}

TEST_CASE("Rectangle constructor height precondition failure", "[Rectangle]") {
  const Point ORIGIN{0, 0};
  const int WIDTH{1};
  const int BAD_HEIGHT{0};
  REQUIRE_THROWS_AS(Rectangle(ORIGIN, WIDTH, BAD_HEIGHT), std::logic_error);
}

TEST_CASE("Rectangle failed to narrow from Segment", "[Rectangle]") {
  const Segment SEGMENT{{0, 0}, {1, 0}};
  REQUIRE_THROWS_AS(Rectangle::narrowShapeToRectangle(SEGMENT), std::logic_error);
}

TEST_CASE("Rectangle narrowing from another Rectangle") {
  const Rectangle START_RECTANGLE{{0, 0}, 50, 50};
  const Rectangle NARROWED_RECTANGLE = Rectangle::narrowShapeToRectangle(START_RECTANGLE);
  REQUIRE(START_RECTANGLE == NARROWED_RECTANGLE);
}

TEST_CASE("Rectangle narrowing from a star shape") {
  const Shape STAR({{-1, 1}, {0, 3}, {1, 1}, {3, 1}, {1, 0}, {2, -2}, {0, -1}, {-2, -2}, {-1, 0}, {-3, 1}});
  const Rectangle EXPECTED_RESULT{{-3, -2}, 6, 5};
  const Rectangle NARROWED_STAR = Rectangle::narrowShapeToRectangle(STAR);
  REQUIRE(NARROWED_STAR == EXPECTED_RESULT);
}

TEST_CASE("Rectangle collision from below", "[Rectangle]") {
  const Rectangle TEST_RECT{{0, 0}, 100, 100};
  const std::vector<Point> BELOW_RECTANGLE{{50, 300}, {150, 300}, {150, 200}, {50, 200}};
  const Vec2 COLLISION_VECTOR{0, -150};
  REQUIRE(TEST_RECT.wouldShapeCollideAfterMovement(BELOW_RECTANGLE, COLLISION_VECTOR) == CollisionDirection::DOWN);
}

TEST_CASE("Rectangle collision from above", "[Rectangle]") {
  const Rectangle TEST_RECT{{0, 0}, 100, 100};
  const std::vector<Point> ABOVE_RECTANGLE{{50, -200}, {150, -200}, {150, -100}, {50, -100}};
  const Vec2 COLLISION_VECTOR{0, 150};
  REQUIRE(TEST_RECT.wouldShapeCollideAfterMovement(ABOVE_RECTANGLE, COLLISION_VECTOR) == CollisionDirection::UP);
}

TEST_CASE("Rectangle collision from the left", "[Rectangle]") {
  const Rectangle TEST_RECT{{0, 0}, 100, 100};
  const std::vector<Point> LEFT_RECTANGLE{{-200, 50}, {-100, 50}, {-100, 150}, {-200, 150}};
  const Vec2 COLLISION_VECTOR{150, 0};
  REQUIRE(TEST_RECT.wouldShapeCollideAfterMovement(LEFT_RECTANGLE, COLLISION_VECTOR) == CollisionDirection::LEFT);
}

TEST_CASE("Rectangle collision from the right", "[Rectangle]") {
  const Rectangle TEST_RECT{{0, 0}, 100, 100};
  const std::vector<Point> RIGHT_RECTANGLE{{200, 150}, {300, 150}, {300, 50}, {200, 50}};

  const Vec2 COLLISION_VECTOR{-150, 0};
  REQUIRE(TEST_RECT.wouldShapeCollideAfterMovement(RIGHT_RECTANGLE, COLLISION_VECTOR) == CollisionDirection::RIGHT);
}

TEST_CASE("Rectangle collision from the right while ascending", "[Rectangle]") {
  const Rectangle TEST_RECT{{0, 0}, 100, 100};
  const std::vector<Point> RIGHT_DIAGONAL_RECTANGLE{{150, 0}, {250, 0}, {250, 100}, {150, 100}};

  const Vec2 COLLISION_VECTOR{-100, 50};
  REQUIRE(TEST_RECT.wouldShapeCollideAfterMovement(RIGHT_DIAGONAL_RECTANGLE, COLLISION_VECTOR) ==
          CollisionDirection::RIGHT);
}

TEST_CASE("Rectangle collision from the left while descending", "[Rectangle]") {
  const Rectangle TEST_RECT{{0, 0}, 100, 100};
  const std::vector<Point> LEFT_DIAGONAL_RECTANGLE{{-150, 200}, {-50, 200}, {-50, 100}, {-150, 100}};
  const Vec2 COLLISION_VECTOR{100, -50};
  REQUIRE(TEST_RECT.wouldShapeCollideAfterMovement(LEFT_DIAGONAL_RECTANGLE, COLLISION_VECTOR) ==
          CollisionDirection::LEFT);
}

TEST_CASE("Rectangle collision from the left with two vertices colliding", "[Rectangle]") {
  const Rectangle TEST_RECT{{0, 0}, 100, 100};
  const std::vector<Point> LEFT_DIAGONAL_RECTANGLE{{-150, 200}, {-50, 200}, {-50, 100}, {-150, 100}};
  const Vec2 COLLISION_VECTOR{200, -100};
  REQUIRE(TEST_RECT.wouldShapeCollideAfterMovement(LEFT_DIAGONAL_RECTANGLE, COLLISION_VECTOR) ==
          CollisionDirection::LEFT);
}
