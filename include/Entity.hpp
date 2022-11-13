#pragma once

#include "GeometryUtilities.hpp"
#include "PhysicalObject.hpp"

namespace GameLib {
/**
 * @brief Mother class for all entities
 */
class Entity : public PhysicalObject {
public:
  /**
   * @brief Set the acceleration vector
   */
  void setAcceleration(const Vec2 &acceleration);

  /**
   * @brief Get the acceleration vector
   */
  const Vec2 &getAcceleration(void) const;

  /**
   * @brief Make the entity update his speed using his acceleration vector
   */
  void updateSpeed(void);

  /**
   * @brief Check if the current entity would collide
   *
   * @param position The physical object to test
   *
   * @return <true, ...> if the entity is colliding in the x axis, <..., true> if the entity is colliding in the y axis,
   * <false, false> otherwise
   */
  std::pair<bool, bool> wouldCollideWithPhysicalObject(const PhysicalObject &other, const Vec2 &acceleration) const;

private:
  Vec2 acceleration{0.0, 0.0};                     /**< Acceleration vector */
  static constexpr double MAX_HORIZONTAL_SPEED{0}; /**< Maximum speed for horizontals movements */
  Vec2 current_speed{0.0,
                     0.0}; /**< Current vector speed. The projection on x axis must be less than MAX_HORIZONTAL_SPEED */
};

} // namespace GameLib
