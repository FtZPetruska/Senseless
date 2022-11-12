#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "EntitySetting.hpp"
#include "Level.hpp"
#include "PhysicalObjectDTO.hpp"

namespace GameLib {

using EntitiesSettings = std::vector<EntitySetting>;
using ObstaclesSettings = std::vector<PhysicalObjectDTO>;
using LevelsSettings = std::unordered_map<std::string, std::pair<EntitiesSettings, ObstaclesSettings>>;

class LevelFactory {
public:
  Level makeLevel(const std::string &level_name);

private:
  LevelsSettings levels_settings;
};

} // namespace GameLib
