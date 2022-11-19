#include "Doorman.hpp"

using namespace GameLib;

Doorman::Doorman(const Point &starting_position, const Shape &entity_shape) : Entity(starting_position, entity_shape) {}

void Doorman::updateAcceleration(void) {}

void Doorman::checkForCollision(const PhysicalObject &other) {
  (void)other;
}

void Doorman::manageInteraction(const Entity &other) {
  (void)other;
}