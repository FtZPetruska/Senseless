#pragma once

#include "Entity.hpp"
#include "GeometryUtilities.hpp"

namespace GameLib {

/**
 * @brief Specialisation of Entity that charges towards the last position the player used its sonar at
 */
class Luis : public Entity {
public:
  /**
   * @brief Create a Luis with a given position and shape
   */
  Luis(const Point &starting_position, const Shape &shape);

  void updateAcceleration(void) override;
  void checkForCollision(const PhysicalObject &other) override;
  void manageInteraction(const Entity &other) override;

private:
  Point latest_sound_location; /**< Target destination */
  static constexpr double MAX_HORIZONTAL_SPEED{60.0};
};

}; // namespace GameLib
