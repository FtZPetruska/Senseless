#pragma once

#include <queue>
#include <string>
#include <vector>

#include "Command.hpp"
#include "Entity.hpp"
#include "PhysicalObject.hpp"
#include "Player.hpp"
#include "StateDTO.hpp"
#include "StateDTOAssembler.hpp"

namespace GameLib {

/**
 * @brief Manage entities, obstacle and the player in the level
 */
class Level {
public:
  /**
   * @brief Update the elements in the level
   *
   * @param commands The queue of commands to be executed
   */
  void update(const std::queue<Command> &commands);

  /**
   * @brief Get the state of the level
   *
   * @return The state of the level
   */
  const StateDTO getStateDTO(void) const;

private:
  const std::string level_name;          /**< Level name */
  std::vector<Entity> entities;          /**< Collection of all the entities */
  std::vector<PhysicalObject> obstacles; /**< Collection of the physical object use as obstacles*/
  Player player;                         /**< The playable charactere */
};

} // namespace GameLib
