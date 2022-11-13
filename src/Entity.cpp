#include "Entity.hpp"

using namespace GameLib;

void Entity::setAcceleration(const Vec2 &new_acceleration) {
  acceleration = new_acceleration;
}

const Vec2 &Entity::getAcceleration(void) const {
  return acceleration;
}

void Entity::updateSpeed(void) {
  current_speed = current_speed + acceleration;
  current_speed.horizontalClamp(MAX_HORIZONTAL_SPEED);
}
