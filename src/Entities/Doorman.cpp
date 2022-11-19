#include "Doorman.hpp"

using namespace GameLib;

Doorman::Doorman(const Point &starting_position, const Shape &shape) : Entity(starting_position, shape) {}

void Doorman::updateAcceleration(void) {}

void Doorman::checkForCollision(const PhysicalObject &other) {
  (void)other;
}

void Doorman::manageInteraction(const Entity &other) {
  (void)other;
}