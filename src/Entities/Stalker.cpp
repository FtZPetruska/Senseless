#include "Stalker.hpp"

#include <queue>

#include "GeometryUtilities.hpp"
#include "Player.hpp"

using namespace GameLib;

Stalker::Stalker(const Point &starting_position, const Shape &entity_shape) : Entity(starting_position, entity_shape) {}

void Stalker::updateAcceleration(void) {
  if (path.empty()) {
    return;
  }

  const Point &position = getCurrentPosition();
  const Point &destination = path.front();
  const Vec2 ACCELERATION = position.getCappedTranslationVector(destination, MAX_HORIZONTAL_SPEED);
  setAcceleration(ACCELERATION);

  if (path.front() == position) {
    path.pop();
  }
}

// FIXME: Since it follows the Player's path, are there any checks needed ?
void Stalker::checkForCollision(const PhysicalObject &other) {
  (void)other;
}

void Stalker::manageInteraction(const Entity &other) {
  const Player &player = dynamic_cast<const Player &>(other);
  const Point &current_player_position = player.getCurrentPosition();
  if (path.back() != current_player_position) {
    path.push(current_player_position);
  }
}
