#include "Level.hpp"

#include "Command.hpp"
#include <queue>

using namespace GameLib;

void Level::update(const CommandQueue &commands) {
  player.processCommands(commands);

  for (const auto &obstacle : obstacles) {
    player.checkForCollision(obstacle);
  }

  for (auto &entity : entities) {
    entity->updateAcceleration();
    for (const auto &obstacle : obstacles) {
      entity->checkForCollision(obstacle);
    }
    entity->manageInteraction(player);
    entity->updateSpeed();
  }
  player.updateSpeed();
}
