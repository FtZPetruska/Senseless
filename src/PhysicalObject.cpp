#include "PhysicalObject.hpp"

using namespace GameLib;

const Point &PhysicalObject::getPosition(void) const {
  return position;
}

void PhysicalObject::setPosition(const Point &new_position) {
  position = new_position;
}
