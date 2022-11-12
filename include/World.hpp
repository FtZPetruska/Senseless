#pragma once

#include <queue>
#include <string>

#include "Command.hpp"
#include "Level.hpp"
#include "LevelFactory.hpp"
#include "StateDTO.hpp"


namespace GameLib {

class World {
public:
  void update(std::queue<Command> commands);
  const StateDTO &getStateDTO(void) const;

private:
  void nextLevel(void);

  LevelFactory level_factory;
  Level current_level;
  std::queue<const std::string> level_name_order;
};

} // namespace GameLib
