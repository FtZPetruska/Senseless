#pragma once

#include "Entity.hpp"
#include "EntitySetting.hpp"

namespace GameLib {
/**
 * @brief Factory for Entity class
 *
 * @param entity_setting Entity setting used to instantiate the object
 *
 * @return the instantiated object
 */
Entity makeEntity(const EntitySetting &entity_setting);

} // namespace GameLib
