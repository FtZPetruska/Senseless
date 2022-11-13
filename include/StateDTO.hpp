#pragma once

#include <vector>

#include "PhysicalObjectDTO.hpp"

namespace GameLib {
/**
 * @brief DTO of the state of a level
 */
struct StateDTO {
  const std::vector<PhysicalObjectDTO>
      physical_object_dtos; /**< Collection of physical object state contain in the level */
};

} // namespace GameLib
