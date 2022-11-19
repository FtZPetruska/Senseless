#include "Vagrant.hpp"

using namespace GameLib;

Vagrant::Vagrant(const Point &starting_position, const Shape &shape) : Entity(starting_position, shape) {}

// Vagrant doesn't accelerate, it's at full speed at all time
void Vagrant::updateAcceleration(void) {}

void Vagrant::checkForCollision(const PhysicalObject &other) {
  (void)other; // TODO: Check collision when available
  /* if(collision) */ {
    static constexpr auto GET_OPPOSITE_DIRECTION = [](Direction direction) {
      return (direction == Direction::LEFT) ? Direction::RIGHT : Direction::LEFT;
    };

    current_direction = GET_OPPOSITE_DIRECTION(current_direction);
  }
}

void Vagrant::manageInteraction(const Entity &other) {
  (void)other; // TODO: hitting the player
}