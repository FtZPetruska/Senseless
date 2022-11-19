#pragma once

#include "Entity.hpp"

namespace GameLib {

class Vagrant : public Entity {
public:
  Vagrant(const Point &starting_position, const Shape &shape);

  void updateAcceleration(void) override;
  void checkForCollision(const PhysicalObject &other) override;
  void manageInteraction(const Entity &other) override;

private:
  enum class Direction {
    LEFT,
    RIGHT
  } current_direction{Direction::LEFT};

  static constexpr double MAX_HORIZONTAL_SPEED{40.0};
};

}; // namespace GameLib
