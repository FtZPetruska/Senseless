#pragma once

#include "GeometryUtilities.hpp"
#include <utility>

namespace GameLib {
/**
 * @brief Mother class of all physical objects
 */
class PhysicalObject {
public:
  PhysicalObject(const Point& starting_position, const Shape& shape);

  /**
   * @brief Get the position of the object
   *
   * @return The position of the object
   */
  const Point &getCurrentPosition(void) const;

  /**
   * @brief Set the position of the object
   *
   * @param position The position of the object
   */
  void setCurrentPosition(const Point &new_position);


private:
  Point current_position;                /**< The position of the object*/
  Shape shape;                           /**< The shape of the object */
  static constexpr double GRAVITY{10.0}; /**< The static constant of gravity acceleration */
};

} // namespace GameLib
