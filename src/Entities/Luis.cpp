#include "Luis.hpp"

#include <cmath>

#include "Player.hpp"

using namespace GameLib;

Luis::Luis(const Point &starting_position, const Shape &shape)
    : Entity(starting_position, shape), latest_sound_location(starting_position) {}

void Luis::updateAcceleration(void) {
  const Point &current_position = getCurrentPosition();
  if (current_position == latest_sound_location) {
    setAcceleration({0.0, 0.0});
    return;
  }
  const Vec2 ACCELERATION = current_position.getCappedTranslationVector(latest_sound_location, MAX_HORIZONTAL_SPEED);
  setAcceleration(ACCELERATION);
}

// TODO: Fill the stub with collision
void Luis::checkForCollision(const PhysicalObject &other) {
  (void)other;
}

void Luis::manageInteraction(const Entity &other) {
  const Player &player = dynamic_cast<const Player &>(other);
  const Point &last_sonar_location = player.getLastSonarPosition();
  if (last_sonar_location != latest_sound_location) {
    latest_sound_location = last_sonar_location;
  }
}
