#include "GeometryUtilities.hpp"

#include <cmath>

using namespace GameLib;

bool Point::operator==(const Point &other) const {
  return this->x == other.x && this->y == other.y;
}

Point Point::translate(const Vec2 &translation) const {
  return {static_cast<int>(std::round(x + translation.dx)), static_cast<int>(std::round(y + translation.dy))};
}

double Point::distance(const Point &other) const {
  return std::sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
}
