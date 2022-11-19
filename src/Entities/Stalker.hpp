#pragma once

#include "Entity.hpp"

#include <queue>

namespace GameLib {

class Stalker : public Entity {
public:
  Stalker(const Point &starting_position, const Shape &shape);

  void updateAcceleration(void) override;
  void checkForCollision(const PhysicalObject &other) override;
  void manageInteraction(const Entity &other) override;

private:
  std::queue<Point> path{}; /**< Path towards the player */
  static constexpr double MAX_HORIZONTAL_SPEED{20.0};
};

}; // namespace GameLib
