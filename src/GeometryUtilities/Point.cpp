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

Vec2 Point::getCappedTranslationVector(const Point &destination, double max_distance) const {
  double delta_x = destination.x - x;
  double delta_y = destination.y - y;

  double distance = std::hypot(delta_x, delta_y);
  double capped_distance = std::min(distance, max_distance);
  double angle = std::atan2(delta_y, delta_x);
  return {std::cos(angle) * capped_distance, std::sin(angle) * capped_distance};
}
