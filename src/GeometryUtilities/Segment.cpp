#include "GeometryUtilities.hpp"
#include <optional>
#include <stdexcept>

using namespace GameLib;

Segment::Segment(const Point &first, const Point &second) : Shape({first, second}) {
  if (first == second) {
    throw std::logic_error("Cannot make a segment from the same two points");
  }
}

std::optional<const Point> Segment::intersect(const Segment &other) const {
  int local_delta_y = vertices[1].y - vertices[0].y;
  int local_delta_x = vertices[0].x - vertices[1].x;
  int local_coefficient = local_delta_y * vertices[0].x + local_delta_x * vertices[0].y;

  int other_delta_y = other.vertices[1].y - other.vertices[0].y;
  int other_delta_x = other.vertices[0].x - other.vertices[1].x;
  int other_coefficient = other_delta_y * other.vertices[0].x + other_delta_x * other.vertices[0].y;

  int determinant = local_delta_y * other_delta_x - other_delta_y * local_delta_x;

  if (determinant == 0) {
    return std::nullopt;
  }

  int intersection_x = (other_delta_x * local_coefficient - local_delta_x * other_coefficient) / determinant;
  int intersection_y = (local_delta_y * other_coefficient - other_delta_y * local_coefficient) / determinant;
  Point intersection = Point{intersection_x, intersection_y};
  if (!isOnSegment(intersection) || !other.isOnSegment(intersection)) {
    return std::nullopt;
  }
  return Point{intersection_x, intersection_y};
}

bool Segment::isOnSegment(const Point &candidate) const {
  return candidate.x <= std::max(vertices[0].x, vertices[1].x) &&
         candidate.x >= std::min(vertices[0].x, vertices[1].x) &&
         candidate.y <= std::max(vertices[0].y, vertices[1].y) && candidate.y >= std::min(vertices[0].y, vertices[1].y);
}