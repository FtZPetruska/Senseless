#include "Entity.hpp"

using namespace GameLib;

Entity::Entity(const Point &starting_position, const Shape &shape) : PhysicalObject(starting_position, shape) {}

void Entity::setAcceleration(const Vec2 &new_acceleration) {
  acceleration = new_acceleration;
}

const Vec2 &Entity::getAcceleration(void) const {
  return acceleration;
}

const Vec2 &Entity::getSpeed(void) const {
  return current_speed;
}

void Entity::updateSpeed(void) {
  current_speed = current_speed + acceleration;
  current_speed.horizontalClamp(MAX_HORIZONTAL_SPEED);
}
