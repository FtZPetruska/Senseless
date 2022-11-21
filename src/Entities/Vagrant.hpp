#pragma once

#include "Entity.hpp"

namespace GameLib {

/**
 * @brief Specialisation of Entity that moves horizontally and changes direction when hitting obstacles
 */
class Vagrant : public Entity {
public:
  /**
   * @brief Create a Vagrant with a given position and shape
   */
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
