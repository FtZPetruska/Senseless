#include <catch2/catch_test_macros.hpp>

#include "GeometryUtilities.hpp"

using namespace GameLib;

TEST_CASE("Point comparison against itself", "[Point]") {
  const Point A_POINT{1, 1};
  REQUIRE(A_POINT == A_POINT);
}

TEST_CASE("Point comparison against identical point", "[Point]") {
  const Point A_POINT{1, 1};
  const Point SAME_POINT{A_POINT};
  REQUIRE(A_POINT == SAME_POINT);
}

TEST_CASE("Point comparison against different point", "[Point]") {
  const Point A_POINT{1, 1};
  const Point OTHER_POINT{42, 69};
  REQUIRE(A_POINT != OTHER_POINT);
}

TEST_CASE("Point translation right", "[Point]") {
  const Point STARTING_POINT{0, 0};
  const Vec2 TRANSLATION{1.0, 0.0};
  const Point EXPECTED_RESULT{1, 0};
  REQUIRE(STARTING_POINT.translate(TRANSLATION) == EXPECTED_RESULT);
}

TEST_CASE("Point translation left", "[Point]") {
  const Point STARTING_POINT{0, 0};
  const Vec2 TRANSLATION{-1.0, 0.0};
  const Point EXPECTED_RESULT{-1, 0};
  REQUIRE(STARTING_POINT.translate(TRANSLATION) == EXPECTED_RESULT);
}

TEST_CASE("Point translation down", "[Point]") {
  const Point STARTING_POINT{0, 0};
  const Vec2 TRANSLATION{0.0, 1.0};
  const Point EXPECTED_RESULT{0, 1};
  REQUIRE(STARTING_POINT.translate(TRANSLATION) == EXPECTED_RESULT);
}

TEST_CASE("Point translation up", "[Point]") {
  const Point STARTING_POINT{0, 0};
  const Vec2 TRANSLATION{0.0, -1.0};
  const Point EXPECTED_RESULT{0, -1};
  REQUIRE(STARTING_POINT.translate(TRANSLATION) == EXPECTED_RESULT);
}

TEST_CASE("Point translation right-down", "[Point]") {
  const Point STARTING_POINT{0, 0};
  const Vec2 TRANSLATION{1.0, 1.0};
  const Point EXPECTED_RESULT{1, 1};
  REQUIRE(STARTING_POINT.translate(TRANSLATION) == EXPECTED_RESULT);
}

TEST_CASE("Point translation left-down", "[Point]") {
  const Point STARTING_POINT{0, 0};
  const Vec2 TRANSLATION{-1.0, 1.0};
  const Point EXPECTED_RESULT{-1, 1};
  REQUIRE(STARTING_POINT.translate(TRANSLATION) == EXPECTED_RESULT);
}

TEST_CASE("Point translation right-up", "[Point]") {
  const Point STARTING_POINT{0, 0};
  const Vec2 TRANSLATION{1.0, -1.0};
  const Point EXPECTED_RESULT{1, -1};
  REQUIRE(STARTING_POINT.translate(TRANSLATION) == EXPECTED_RESULT);
}

TEST_CASE("Point translation left-up", "[Point]") {
  const Point STARTING_POINT{0, 0};
  const Vec2 TRANSLATION{-1.0, -1.0};
  const Point EXPECTED_RESULT{-1, -1};
  REQUIRE(STARTING_POINT.translate(TRANSLATION) == EXPECTED_RESULT);
}

TEST_CASE("Point horizontal distance", "[Point]") {
  const Point FIRST_POINT{0, 0};
  const Point SECOND_POINT{5, 0};
  const double EXPECTED_DISTANCE{5.0};
  REQUIRE(FIRST_POINT.distance(SECOND_POINT) == EXPECTED_DISTANCE);
}

TEST_CASE("Point vertical distance", "[Point]") {
  const Point FIRST_POINT{0, 0};
  const Point SECOND_POINT{0, -2};
  const double EXPECTED_DISTANCE{2.0};
  REQUIRE(FIRST_POINT.distance(SECOND_POINT) == EXPECTED_DISTANCE);
}

TEST_CASE("Point diagonal distance", "[Point]") {
  const Point A_POINT{0, 0};
  const Point OTHER_POINT{-3, 4};
  const double EXPECTED_DISTANCE{5.0};
  REQUIRE(A_POINT.distance(OTHER_POINT) == EXPECTED_DISTANCE);
}
