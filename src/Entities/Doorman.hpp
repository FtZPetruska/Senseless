#pragma once

#include "Entity.hpp"

namespace GameLib {

/**
 * @brief Specialisation of Entity that blocks the player's path with a price to pass
 */
class Doorman : public Entity {
public:
  /**
   * @brief Create a Doorman with a given position and shape
   */
  Doorman(const Point &starting_position, const Shape &shape);

  void updateAcceleration(void) override;
  void checkForCollision(const PhysicalObject &other) override;
  void manageInteraction(const Entity &other) override;

private:
  static constexpr int PRICE_TO_PASS{1};
};

}; // namespace GameLib
