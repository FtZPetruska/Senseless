#include "GeometryUtilities.hpp"
#include <optional>

using namespace GameLib;

Segment::Segment(const Point &a, const Point &b) : a(a), b(b) {
  vertices = {a, b};
}

std::optional<const Point> Segment::intersect(const Segment &other, double epsilon) const {
  int a1 = b.y - a.y;
  int b1 = a.x - b.x;
  int c1 = a1 * (a.x) + b1 * (a.y);

  int a2 = other.b.y - other.a.y;
  int b2 = other.a.x - other.b.x;
  int c2 = a2 * (other.a.x) + b2 * (other.a.y);

  int determinant = a1 * b2 - a2 * b1;

  if (determinant < epsilon && determinant > -epsilon) {
    // The lines are parallel. This is simplified
    // by returning a pair of FLT_MAX
    return std::nullopt;
  } else {
    int x = (b2 * c1 - b1 * c2) / determinant;
    int y = (a1 * c2 - a2 * c1) / determinant;
    Point intersection = Point{x, y};
    if (!isOnSegment(intersection) || !other.isOnSegment(intersection)) {
      return std::nullopt;
    }
    return Point{x, y};
  }
}

bool Segment::isOnSegment(const Point &p) const {
  return p.x <= std::max(a.x, b.x) && p.x >= std::min(a.x, b.x) && p.y <= std::max(a.y, b.y) &&
         p.y >= std::min(a.y, b.y);
}