#include "Magnetick.hpp"

#include "Player.hpp"

using namespace GameLib;

Magnetick::Magnetick(const Point &starting_position, const Shape &shape)
    : Entity(starting_position, shape), target_position(starting_position) {}

void Magnetick::updateAcceleration(void) {
  const Point &current_position = getCurrentPosition();
  if (current_position == target_position) {
    setAcceleration({0.0, 0.0});
    return;
  }
  const Vec2 ACCELERATION = current_position.getCappedTranslationVector(target_position, MAX_HORIZONTAL_SPEED);
  setAcceleration(ACCELERATION);
}

// TODO: Confirm that there does not need to be collision check
void Magnetick::checkForCollision(const PhysicalObject &other) {
  (void)other;
}

void Magnetick::manageInteraction(const Entity &other) {
  if (isAttached()) {
    return;
  }

  const Player &player = dynamic_cast<const Player &>(other);
  target_position = player.getCurrentPosition();
  if (getCurrentPosition() == target_position) {
    is_attached = true;
    attached_time = std::chrono::high_resolution_clock::now();
    // FIXME: Notify the player that a Magnetic is attached (const cast?)
  }
}

bool Magnetick::isAttached(void) const {
  return is_attached;
}

bool Magnetick::shouldDetatch(void) const {
  return std::chrono::high_resolution_clock::now() > attached_time + ATTACHMENT_DURATION;
}
