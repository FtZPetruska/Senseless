#pragma once

#include <vector>

#include "PhysicalObjectDTO.hpp"

namespace GameLib {

struct StateDTO {
  const std::vector<PhysicalObjectDTO> physical_object_dtos;
};

} // namespace GameLib
