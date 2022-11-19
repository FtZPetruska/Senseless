#pragma once

#include "Entity.hpp"

namespace GameLib {

class Doorman : public Entity {
public:
  Doorman(const Point &starting_position, const Shape &shape);

  void updateAcceleration(void) override;
  void checkForCollision(const PhysicalObject &other) override;
  void manageInteraction(const Entity &other) override;

private:
  static constexpr int PRICE_TO_PASS{1};
};

}; // namespace GameLib
