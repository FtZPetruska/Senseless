#include <catch2/catch_test_macros.hpp>

#include "GeometryUtilities.hpp"

using namespace GameLib;

TEST_CASE("Comparing two vectors", "[Vec2]") {
  const Vec2 UNIT_VECTOR{1.0, 1.0};

  SECTION("Compare against itself") {
    REQUIRE(UNIT_VECTOR == UNIT_VECTOR);
  }

  SECTION("Compare against an identical object") {
    const Vec2 OTHER_UNIT_VECTOR{1.0, 1.0};
    REQUIRE(UNIT_VECTOR == OTHER_UNIT_VECTOR);
  }

  SECTION("Compare against a different vector") {
    const Vec2 OTHER_VECTOR{420.0, 69.0};
    REQUIRE(UNIT_VECTOR != OTHER_VECTOR);
  }
}

TEST_CASE("Operation with empty vectors", "[Vec2]") {
  const Vec2 UNIT_VECTOR{1.0, 1.0};
  const Vec2 EMPTY_VECTOR{0.0, 0.0};

  SECTION("Adding an empty vector") {
    REQUIRE(UNIT_VECTOR + EMPTY_VECTOR == UNIT_VECTOR);
    REQUIRE(EMPTY_VECTOR + UNIT_VECTOR == UNIT_VECTOR);
  }

  SECTION("Substracting an empty vector") {
    const Vec2 NEGATIVE_UNIT_VECTOR{-1.0, -1.0};
    REQUIRE(UNIT_VECTOR - EMPTY_VECTOR == UNIT_VECTOR);
    REQUIRE(EMPTY_VECTOR - UNIT_VECTOR == NEGATIVE_UNIT_VECTOR);
  }
}

TEST_CASE("Nulling a vector", "[Vec2]") {
  const Vec2 EMPTY_VECTOR{0.0, 0.0};

  SECTION("Add two opposite vectors") {
    const Vec2 FIRST_VECTOR{10.0, -25.0};
    const Vec2 SECOND_VECTOR{-10.0, 25.0};
    REQUIRE(FIRST_VECTOR + SECOND_VECTOR == EMPTY_VECTOR);
  }

  SECTION("Substract the vector to itself") {
    const Vec2 TEST_VECTOR{-32.0, 76.0};
    REQUIRE(TEST_VECTOR - TEST_VECTOR == EMPTY_VECTOR);
  }
}

TEST_CASE("Regular vector operations", "[Vec2]") {
  const Vec2 FIRST_VECTOR{12.0, -50.0};
  const Vec2 SECOND_VECTOR{-64.0, 14.0};

  SECTION("Adding vectors") {
    const Vec2 EXPECTED_RESULT{-52.0, -36.0};
    REQUIRE(FIRST_VECTOR + SECOND_VECTOR == EXPECTED_RESULT);
  }

  SECTION("Substracting vectors") {
    const Vec2 EXPECTED_RESULT{76.0, -64.0};
    REQUIRE(FIRST_VECTOR - SECOND_VECTOR == EXPECTED_RESULT);
  }
}

TEST_CASE("Shape immutazbility test", "[Shape]") {
  const std::vector<Point> VERTICES{{0, 0}, {1, 0}, {1, 1}, {0, 1}};
  const Shape TEST_SHAPE(VERTICES);
  REQUIRE(TEST_SHAPE.getVertices() == VERTICES);
}

TEST_CASE("Basic Rectangle", "[Rectangle]") {
  const Rectangle TEST_RECT{{0, 0}, 1, 1};
  const std::vector<Point> EXPECTED_RESULT{{0, 0}, {1, 0}, {1, 1}, {0, 1}};
  REQUIRE(TEST_RECT.getVertices() == EXPECTED_RESULT);
}

TEST_CASE("Rectangle sanity checks", "[Rectangle]") {
  SECTION("Rectangle with a non-zero origin") {
    const Rectangle TEST_RECT{{69, 96}, 420, 24};
    const std::vector<Point> EXPECTED_RESULT{{69, 96}, {489, 96}, {489, 120}, {69, 120}};
    REQUIRE(TEST_RECT.getVertices() == EXPECTED_RESULT);
  }

  SECTION("Rectangle overlapping all quadrants") {
    const Rectangle TEST_RECT{{-2, -4}, 4, 6};
    const std::vector<Point> EXPECTED_RESULT{{-2, -4}, {2, -4}, {2, 2}, {-2, 2}};
    REQUIRE(TEST_RECT.getVertices() == EXPECTED_RESULT);
  }
}
