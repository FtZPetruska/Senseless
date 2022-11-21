#include <catch2/catch_test_macros.hpp>

#include "GeometryUtilities.hpp"

#include <optional>
#include <stdexcept>

using namespace GameLib;

TEST_CASE("Segment constructor precondition failure", "[Segment]") {
  const Point A_POINT{1, 1};
  REQUIRE_THROWS_AS(Segment(A_POINT, A_POINT), std::logic_error);
}

TEST_CASE("Segment has intersection with perpendicular", "[Segment]") {
  const Segment HORIZONTAL_SEGMENT{{-1, 0}, {1, 0}};
  const Segment VERTICAL_SEGMENT{{0, -1}, {0, 1}};
  const Point EXPECTED_INTERSECTION{0, 0};
  const auto INTERSECTION = VERTICAL_SEGMENT.intersect(HORIZONTAL_SEGMENT);
  REQUIRE(INTERSECTION.has_value());
  REQUIRE(INTERSECTION.value() == EXPECTED_INTERSECTION);
}

TEST_CASE("Segment has intersection with rounding", "[Segment]") {
  // Intersects in (0.8, 0.4), truncated from integer math
  const Segment HORIZONTAL_SEGMENT{{-1, 1}, {2, 0}};
  const Segment VERTICAL_SEGMENT{{0, -2}, {1, 1}};
  const Point EXPECTED_INTERSECTION{0, 0};
  const auto INTERSECTION = VERTICAL_SEGMENT.intersect(HORIZONTAL_SEGMENT);
  REQUIRE(INTERSECTION.has_value());
  REQUIRE(INTERSECTION.value() == EXPECTED_INTERSECTION);
}

TEST_CASE("Segment has intersection on its end", "[Segment]") {
  const Segment HORIZONTAL_SEGMENT{{0, 0}, {1, 0}};
  const Segment VERTICAL_SEGMENT{{0, -1}, {0, 1}};
  const Point EXPECTED_INTERSECTION{0, 0};
  const auto INTERSECTION = VERTICAL_SEGMENT.intersect(HORIZONTAL_SEGMENT);
  REQUIRE(INTERSECTION.has_value());
  REQUIRE(INTERSECTION.value() == EXPECTED_INTERSECTION);
}

TEST_CASE("Segment has intersection on both ends", "[Segment]") {
  const Segment HORIZONTAL_SEGMENT{{0, 0}, {1, 0}};
  const Segment VERTICAL_SEGMENT{{0, 0}, {0, 1}};
  const Point EXPECTED_INTERSECTION{0, 0};
  const auto INTERSECTION = VERTICAL_SEGMENT.intersect(HORIZONTAL_SEGMENT);
  REQUIRE(INTERSECTION.has_value());
  REQUIRE(INTERSECTION.value() == EXPECTED_INTERSECTION);
}

TEST_CASE("Segment does not intersect", "[Segment]") {
  const Segment FIRST_SEGMENT{{0, 0}, {1, 0}};
  const Segment SECOND_SEGMENT{{0, 1}, {0, 2}};
  const auto INTERSECTION = SECOND_SEGMENT.intersect(FIRST_SEGMENT);
  REQUIRE_FALSE(INTERSECTION.has_value());
}

TEST_CASE("Segment is parallel", "[Segment]") {
  const Segment FIRST_SEGMENT{{0, 0}, {1, 0}};
  const Segment SECOND_SEGMENT{{0, 1}, {1, 1}};
  const auto INTERSECTION = SECOND_SEGMENT.intersect(FIRST_SEGMENT);
  REQUIRE_FALSE(INTERSECTION.has_value());
}

TEST_CASE("Segment contains point", "[Segment]") {
  const Segment SEGMENT{{-1, 1}, {1, -1}};
  const Point POINT_ON_SEGMENT{0, 0};
  REQUIRE(SEGMENT.isOnSegment(POINT_ON_SEGMENT));
}

TEST_CASE("Segment does not contain point", "[Segment]") {
  const Segment SEGMENT{{-1, 1}, {1, -1}};
  const Point POINT_ON_SEGMENT{2, 2};
  REQUIRE_FALSE(SEGMENT.isOnSegment(POINT_ON_SEGMENT));
}
