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

class Level {
public:
  void update(const std::queue<Command> &commands);
  const StateDTO getStateDTO(void) const;

private:
  const std::string level_name;
  std::vector<Entity> entities;
  std::vector<PhysicalObject> obstacles;
  Player player;
};

} // namespace GameLib
