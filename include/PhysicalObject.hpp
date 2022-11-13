#pragma once

#include "GeometryUtilities.hpp"
#include <utility>

namespace GameLib {
/**
 * @brief Mother class of all physical objects
 */
class PhysicalObject {
public:
  /**
   * @brief Get the position of the object
   *
   * @return The position of the object
   */
  const Point &getPosition(void) const;

  /**
   * @brief Set the position of the object
   *
   * @param position The position of the object
   */
  void setPosition(const Point &position);

private:
  Point position;                        /**< The position of the object*/
  Shape shape;                           /**< The shape of the object */
  static constexpr double GRAVITY{10.0}; /**< The static constant of gravity acceleration */
};

} // namespace GameLib
