#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "EntitySetting.hpp"
#include "Level.hpp"
#include "PhysicalObjectDTO.hpp"

namespace GameLib {
/**
 * @brief Collection of entity setting
 */
using EntitiesSettings = std::vector<EntitySetting>;

/**
 * @brief Collection of obstacle setting
 */
using ObstaclesSettings = std::vector<PhysicalObjectDTO>;

/**
 * @brief Map linking the level name to the level settings
 */
using LevelsSettings = std::unordered_map<std::string, std::pair<EntitiesSettings, ObstaclesSettings>>;

/**
 * @brief The factory of the levels
 */
class LevelFactory {
public:
  /**
   * @brief Instantiate a level using the settings in the level settings map
   *
   * @param level_name The name of the level to instantiate
   *
   * @return The instantiated level
   */
  Level makeLevel(const std::string &level_name);

private:
  LevelsSettings levels_settings; /**< The map linking the level name to the level settings */
};

} // namespace GameLib
