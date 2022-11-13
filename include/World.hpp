#pragma once

#include <queue>
#include <string>

#include "Command.hpp"
#include "Level.hpp"
#include "LevelFactory.hpp"
#include "StateDTO.hpp"

namespace GameLib {

/**
 * @brief Level container
 */
class World {
public:
  /**
   * @brief Update the elements in the current level
   *
   * @param commands The queue of commands to be executed
   */
  void update(std::queue<Command> commands);

  /**
   * @brief Get the state of the level
   *
   * @return The state of the world
   */
  const StateDTO &getStateDTO(void) const;

private:
  /**
   * @brief Make the world pass to the next level
   */
  void nextLevel(void);

  LevelFactory level_factory;                     /**< The factory for making the levels */
  Level current_level;                            /**< The current level */
  std::queue<const std::string> level_name_order; /**< The order in which the levels will be executed */
};

} // namespace GameLib
