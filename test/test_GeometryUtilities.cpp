#include <catch2/catch_test_macros.hpp>

#include "GeometryUtilities.hpp"

using namespace GameLib;

TEST_CASE("Point comparison tests", "[Point]") {
  const Point A_POINT{1, 1};

  SECTION("Compare against itself") {
    REQUIRE(A_POINT == A_POINT);
  }

  SECTION("Compare against an identical object") {
    const Point SAME_POINT{A_POINT};
    REQUIRE(A_POINT == SAME_POINT);
  }

  SECTION("Compare against a different point") {
    const Point OTHER_POINT{42, 69};
    REQUIRE(A_POINT != OTHER_POINT);
  }
}

TEST_CASE("Point translation on one axis", "[Point]") {
  const Point STARTING_POINT{0, 0};

  SECTION("Translate right") {
    const Vec2 TRANSLATION{1.0, 0.0};
    const Point EXPECTED_RESULT{1, 0};
    REQUIRE(STARTING_POINT.translate(TRANSLATION) == EXPECTED_RESULT);
  }

  SECTION("Translate left") {
    const Vec2 TRANSLATION{-1.0, 0.0};
    const Point EXPECTED_RESULT{-1, 0};
    REQUIRE(STARTING_POINT.translate(TRANSLATION) == EXPECTED_RESULT);
  }

  SECTION("Translate down") {
    const Vec2 TRANSLATION{0.0, 1.0};
    const Point EXPECTED_RESULT{0, 1};
    REQUIRE(STARTING_POINT.translate(TRANSLATION) == EXPECTED_RESULT);
  }

  SECTION("Translate up") {
    const Vec2 TRANSLATION{0.0, -1.0};
    const Point EXPECTED_RESULT{0, -1};
    REQUIRE(STARTING_POINT.translate(TRANSLATION) == EXPECTED_RESULT);
  }
}

TEST_CASE("Point translation on two axis", "[Point]") {
  const Point STARTING_POINT{0, 0};

  SECTION("Translate right-down") {
    const Vec2 TRANSLATION{1.0, 1.0};
    const Point EXPECTED_RESULT{1, 1};
    REQUIRE(STARTING_POINT.translate(TRANSLATION) == EXPECTED_RESULT);
  }

  SECTION("Translate left-down") {
    const Vec2 TRANSLATION{-1.0, 1.0};
    const Point EXPECTED_RESULT{-1, 1};
    REQUIRE(STARTING_POINT.translate(TRANSLATION) == EXPECTED_RESULT);
  }

  SECTION("Translate right-up") {
    const Vec2 TRANSLATION{1.0, -1.0};
    const Point EXPECTED_RESULT{1, -1};
    REQUIRE(STARTING_POINT.translate(TRANSLATION) == EXPECTED_RESULT);
  }

  SECTION("Translate left-up") {
    const Vec2 TRANSLATION{-1.0, -1.0};
    const Point EXPECTED_RESULT{-1, -1};
    REQUIRE(STARTING_POINT.translate(TRANSLATION) == EXPECTED_RESULT);
  }
}

TEST_CASE("Point distance", "[Point]") {
  SECTION("Distance between two points") {
    const Point A_POINT{0, 0};
    const Point OTHER_POINT{1, 1};
    const double EXPECTED_DISTANCE{std::sqrt(2.0)};
    REQUIRE(A_POINT.distance(OTHER_POINT) == EXPECTED_DISTANCE);
  }

  SECTION("Distance between two negative points") {
    const Point A_POINT{-1, -1};
    const Point OTHER_POINT{-2, -2};
    const double EXPECTED_DISTANCE{std::sqrt(2.0)};
    REQUIRE(A_POINT.distance(OTHER_POINT) == EXPECTED_DISTANCE);
  }
}

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

TEST_CASE("Vector horizontal clamp", "[Vec2]") {
  static constexpr double LIMIT{2.0};
  static constexpr double OVER_THE_LIMIT{LIMIT + 1.0};

  SECTION("Within limit") {
    Vec2 test_vector{1.0, -1.0};
    const Vec2 EXPECTED_RESULT{test_vector};
    test_vector.horizontalClamp(LIMIT);
    REQUIRE(test_vector == EXPECTED_RESULT);
  }

  SECTION("Limit overflow") {
    Vec2 test_vector{OVER_THE_LIMIT, 1.0};
    const Vec2 EXPECTED_RESULT{LIMIT, test_vector.dy};
    test_vector.horizontalClamp(LIMIT);
    REQUIRE(test_vector == EXPECTED_RESULT);
  }

  SECTION("Limit underflow") {
    Vec2 test_vector{-OVER_THE_LIMIT, 1.0};
    const Vec2 EXPECTED_RESULT{-LIMIT, test_vector.dy};
    test_vector.horizontalClamp(LIMIT);
    REQUIRE(test_vector == EXPECTED_RESULT);
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

  SECTION("Rectangle overlapping all quadrants", "[Rectangle]") {
    const Rectangle TEST_RECT{{-2, -4}, 4, 6};
    const std::vector<Point> EXPECTED_RESULT{{-2, -4}, {2, -4}, {2, 2}, {-2, 2}};
    REQUIRE(TEST_RECT.getVertices() == EXPECTED_RESULT);
  }
}

TEST_CASE("Segment sanity checks", "[Segment]") {
  SECTION("Segment with a non-zero origin") {
    const Segment TEST_SEGMENT{{69, 96}, {489, 120}};
    const std::vector<Point> EXPECTED_RESULT{{69, 96}, {489, 120}};
    REQUIRE(TEST_SEGMENT.getVertices() == EXPECTED_RESULT);
  }

  SECTION("Segment overlapping all quadrants") {
    const Segment TEST_SEGMENT{{-2, -4}, {2, 2}};
    const std::vector<Point> EXPECTED_RESULT{{-2, -4}, {2, 2}};
    REQUIRE(TEST_SEGMENT.getVertices() == EXPECTED_RESULT);
  }
}

TEST_CASE("Segment intersection", "[Segment]") {
  const Segment FIRST_SEGMENT{{0, 0}, {10, 10}};
  const Segment SECOND_SEGMENT{{0, 10}, {10, 0}};

  SECTION("Intersecting segments") {
    const Point EXPECTED_RESULT{5, 5};
    std::optional<Point> actual_result = FIRST_SEGMENT.intersect(SECOND_SEGMENT);
    REQUIRE(actual_result.has_value());
    REQUIRE(actual_result == EXPECTED_RESULT);
  }

  SECTION("Parallel segments") {
    const Segment PARALLEL_SEGMENT{{10, 10}, {20, 20}};
    REQUIRE(FIRST_SEGMENT.intersect(PARALLEL_SEGMENT).has_value() == false);
  }

  SECTION("Non-intersecting segments") {
    const Segment NON_INTERSECTING_SEGMENT{{10, 0}, {15, 15}};
    REQUIRE(FIRST_SEGMENT.intersect(NON_INTERSECTING_SEGMENT).has_value() == false);
  }
}
