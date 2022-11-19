#include "PhysicalObject.hpp"

using namespace GameLib;

PhysicalObject::PhysicalObject(const Point &starting_position, const Shape &shape)
    : current_position(starting_position), shape(shape) {}

const Point &PhysicalObject::getCurrentPosition(void) const {
  return current_position;
}

void PhysicalObject::setCurrentPosition(const Point &new_position) {
  current_position = new_position;
}
