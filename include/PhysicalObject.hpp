#pragma once

#include "GeometryUtilities.hpp"
#include <utility>

namespace GameLib {

class PhysicalObject {
public:
  const Point &getPosition(void) const;
  void setPosition(const Point &position);
  std::pair<bool, bool> wouldCollideWithPhysicalObject(const PhysicalObject &other, const Vec2 &acceleration) const;

private:
  Point position;
  Shape shape;
  static constexpr double GRAVITY{10.0};
};

} // namespace GameLib
