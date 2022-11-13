#include "Player.hpp"

#include <chrono>

using namespace GameLib;

int Player::getItemCount(void) const {
  return item_count;
}

void Player::setItemCount(int new_item_count) {
  item_count = new_item_count;
}

void Player::removeItems(int count) {
  item_count -= count;
}

void Player::manageInteraction(const Entity &other) {
  (void)other; /* For now, keep it a no-op */
}

void Player::checkForCollision(const PhysicalObject &other) {
  (void)other;
}

void Player::updateAcceleration(void) {
  while (!commands_backlog.empty()) {
    static constexpr auto COMPUTE_HORIZONTAL_DISPLACEMENT = [](double current_horizontal_speed) {
      static constexpr double INCREMENT_SPEED{MAX_HORIZONTAL_SPEED / 2.0};
      return std::abs(current_horizontal_speed) + INCREMENT_SPEED;
    };
    const Vec2 &current_speed = getSpeed();
    const Vec2 &current_accel = getAcceleration();
    switch (commands_backlog.front()) {
    case Command::MOVE_RIGHT:
      setAcceleration({COMPUTE_HORIZONTAL_DISPLACEMENT(current_speed.dx), current_accel.dy});
      break;
    case Command::MOVE_LEFT:
      setAcceleration({COMPUTE_HORIZONTAL_DISPLACEMENT(current_speed.dx) * -1.0, current_accel.dy});
      break;
    case Command::JUMP:
      tryJump();
      break;
    case Command::SONAR:
      trySonar();
      break;
    case Command::NO_COMMAND:
      setAcceleration({-current_speed.dx, current_accel.dy});
      break;
    default:
      break;
    }
    commands_backlog.pop();
  }
}

void Player::processCommands(const CommandQueue &commands) {
  commands_backlog = commands;
  updateAcceleration();
}

void Player::tryJump(void) {
  static constexpr double JUMP_SPEED{50.0};
  if (!can_jump) {
    return;
  }
  const Vec2 &current_accel = getAcceleration();
  setAcceleration({current_accel.dx, JUMP_SPEED});
  can_jump = false;
}

void Player::trySonar(void) {
  auto current_time_point = std::chrono::high_resolution_clock::now();
  if (current_time_point < last_sonar_time_point + SONAR_COOLDOWN) {
    return;
  }

  last_sonar_position = getPosition();
  last_sonar_time_point = current_time_point;
}
