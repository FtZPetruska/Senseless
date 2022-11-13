#include "GeometryUtilities.hpp"

#include <algorithm>
#include <cmath>

using namespace GameLib;

Vec2 Vec2::operator+(const Vec2 &other) const {
  return {this->dx + other.dx, this->dy + other.dy};
}

Vec2 Vec2::operator-(const Vec2 &other) const {
  return {this->dx - other.dx, this->dy - other.dy};
}

bool Vec2::operator==(const Vec2 &other) const {
  return this->dx == other.dx && this->dy == other.dy;
}

void Vec2::horizontalClamp(double limit) {
  limit = std::abs(limit);
  dx = std::clamp(dx, -limit, limit);
}
