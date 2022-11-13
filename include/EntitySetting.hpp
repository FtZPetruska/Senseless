#pragma once

#include <utility>

#include "EntityType.hpp"
#include "PhysicalObjectDTO.hpp"

namespace GameLib {
/**
 * @brief Mandatory setting to instantiate an entity
 */
using EntitySetting = std::pair<EntityType, PhysicalObjectDTO>;

} // namespace GameLib
