#pragma once

#include <utility>

#include "EntityType.hpp"
#include "PhysicalObjectDTO.hpp"

namespace GameLib {

using EntitySetting = std::pair<EntityType, PhysicalObjectDTO>;

} // namespace GameLib
