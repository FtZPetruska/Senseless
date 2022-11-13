#pragma once

#include "GeometryUtilities.hpp"

namespace GameLib {
/**
 * @brief DTO of any physical object
 */
struct PhysicalObjectDTO {
  const Point position; /**< The snapshoted position of the object  */
  const Shape shape;    /**< The snapshoted shape of the object */
};

} // namespace GameLib
