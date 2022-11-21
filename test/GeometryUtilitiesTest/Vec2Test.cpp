#include <catch2/catch_test_macros.hpp>

#include "GeometryUtilities.hpp"

using namespace GameLib;

TEST_CASE("Vector comparison against itself", "[Vec2]") {
  const Vec2 UNIT_VECTOR{1.0, 1.0};
  REQUIRE(UNIT_VECTOR == UNIT_VECTOR);
}

TEST_CASE("Vector comparison against identical vector", "[Vec2]") {
  const Vec2 UNIT_VECTOR{1.0, 1.0};
  const Vec2 OTHER_UNIT_VECTOR{1.0, 1.0};
  REQUIRE(UNIT_VECTOR == OTHER_UNIT_VECTOR);
}

TEST_CASE("Vector comparison against different vector", "[Vec2]") {
  const Vec2 UNIT_VECTOR{1.0, 1.0};
  const Vec2 OTHER_VECTOR{420.0, 69.0};
  REQUIRE(UNIT_VECTOR != OTHER_VECTOR);
}

TEST_CASE("Vector additions", "[Vec2]") {
  const Vec2 FIRST_VECTOR{12.0, -50.0};
  const Vec2 SECOND_VECTOR{-64.0, 14.0};
  const Vec2 EXPECTED_RESULT{-52.0, -36.0};
  REQUIRE(FIRST_VECTOR + SECOND_VECTOR == EXPECTED_RESULT);
}

TEST_CASE("Vector substraction", "[Vec2]") {
  const Vec2 FIRST_VECTOR{12.0, -50.0};
  const Vec2 SECOND_VECTOR{-64.0, 14.0};
  const Vec2 EXPECTED_RESULT{76.0, -64.0};
  REQUIRE(FIRST_VECTOR - SECOND_VECTOR == EXPECTED_RESULT);
}

TEST_CASE("Vector addition with an empty vector", "[Vec2]") {
  const Vec2 UNIT_VECTOR{1.0, 1.0};
  const Vec2 EMPTY_VECTOR{0.0, 0.0};
  REQUIRE(UNIT_VECTOR + EMPTY_VECTOR == UNIT_VECTOR);
  REQUIRE(EMPTY_VECTOR + UNIT_VECTOR == UNIT_VECTOR);
}

TEST_CASE("Vector substraction with an empty vector", "[Vec2]") {
  const Vec2 UNIT_VECTOR{1.0, 1.0};
  const Vec2 EMPTY_VECTOR{0.0, 0.0};
  const Vec2 NEGATIVE_UNIT_VECTOR{-1.0, -1.0};
  REQUIRE(UNIT_VECTOR - EMPTY_VECTOR == UNIT_VECTOR);
  REQUIRE(EMPTY_VECTOR - UNIT_VECTOR == NEGATIVE_UNIT_VECTOR);
}

TEST_CASE("Vector neutralisation by additionr", "[Vec2]") {
  const Vec2 EMPTY_VECTOR{0.0, 0.0};
  const Vec2 FIRST_VECTOR{10.0, -25.0};
  const Vec2 SECOND_VECTOR{-10.0, 25.0};
  REQUIRE(FIRST_VECTOR + SECOND_VECTOR == EMPTY_VECTOR);
}

TEST_CASE("Vector neutralisation by substraction", "[Vec2]") {
  const Vec2 EMPTY_VECTOR{0.0, 0.0};
  const Vec2 TEST_VECTOR{-32.0, 76.0};
  REQUIRE(TEST_VECTOR - TEST_VECTOR == EMPTY_VECTOR);
}

TEST_CASE("Vector horizontal clamp within limit", "[Vec2]") {
  static constexpr double LIMIT{2.0};
  Vec2 test_vector{1.0, -1.0};
  const Vec2 EXPECTED_RESULT{test_vector};
  test_vector.horizontalClamp(LIMIT);
  REQUIRE(test_vector == EXPECTED_RESULT);
}

TEST_CASE("Vector horizontal clamp with overflow", "[Vec2]") {
  static constexpr double LIMIT{2.0};
  static constexpr double OVER_THE_LIMIT{LIMIT + 1.0};
  Vec2 test_vector{OVER_THE_LIMIT, 1.0};
  const Vec2 EXPECTED_RESULT{LIMIT, test_vector.dy};
  test_vector.horizontalClamp(LIMIT);
  REQUIRE(test_vector == EXPECTED_RESULT);
}

TEST_CASE("Vector horizontal clamp with underflow", "[Vec2]") {
  static constexpr double LIMIT{2.0};
  static constexpr double OVER_THE_LIMIT{LIMIT + 1.0};
  Vec2 test_vector{-OVER_THE_LIMIT, 1.0};
  const Vec2 EXPECTED_RESULT{-LIMIT, test_vector.dy};
  test_vector.horizontalClamp(LIMIT);
  REQUIRE(test_vector == EXPECTED_RESULT);
}
