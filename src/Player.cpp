#include "Player.hpp"

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

bool Player::isAbleToJump(void) const {
  return can_jump;
}

void Player::setJumpStatus(bool jump_status) {
  can_jump = jump_status;
}

// TODO: Implement these stubs
void Player::manageInteraction(const Entity &other) {
  (void)other;
  (void)last_sonar_position;
  (void)SONAR_COOLDOWN;
}

void Player::checkForCollision(const PhysicalObject &other) {
  (void)other;
}

void Player::updateAcceleration(void) {}

void Player::processCommands(CommandQueue &commands) {
  (void)commands;
}