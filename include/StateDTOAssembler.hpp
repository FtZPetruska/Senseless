#pragma once

#include "Level.hpp"
#include "StateDTO.hpp"

namespace GameLib {
/**
 * @brief Assemble the DTO from a Level object
 *
 * @param level The level used to make de DTO
 *
 * @return The DTO of the state of the level
 */
const StateDTO makeDTO(const Level &level);

} // namespace GameLib
