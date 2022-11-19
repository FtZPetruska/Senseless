#include "PhysicalObject.hpp"

using namespace GameLib;

PhysicalObject::PhysicalObject(const Point &starting_position, const Shape &object_shape)
    : current_position(starting_position), shape(object_shape) {}

const Point &PhysicalObject::getCurrentPosition(void) const {
  return current_position;
}

void PhysicalObject::setCurrentPosition(const Point &new_position) {
  current_position = new_position;
}
