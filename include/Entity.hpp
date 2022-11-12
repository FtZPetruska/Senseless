#pragma once

#include "GeometryUtilities.hpp"
#include "PhysicalObject.hpp"

namespace GameLib {

class Entity : public PhysicalObject {
public:
  void setAcceleration(const Vec2 &acceleration);
  const Vec2 &getAcceleration(void) const;
  void updateSpeed(void);

private:
  Vec2 acceleration{0.0, 0.0};
  static constexpr double MAX_HORIZONTAL_SPEED{0};
  Vec2 current_speed{0.0, 0.0};
};

} // namespace GameLib
