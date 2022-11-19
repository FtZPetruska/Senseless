#pragma once

#include "Entity.hpp"
#include "GeometryUtilities.hpp"

namespace GameLib {

class Luis : public Entity {
public:
  Luis(const Point &starting_position, const Shape &shape);

  void updateAcceleration(void) override;
  void checkForCollision(const PhysicalObject &other) override;
  void manageInteraction(const Entity &other) override;

private:
  Point latest_sound_location; /**< Target destination */
  static constexpr double MAX_HORIZONTAL_SPEED{60.0};
};

}; // namespace GameLib
