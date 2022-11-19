#pragma once

#include "GeometryUtilities.hpp"
#include "PhysicalObject.hpp"

namespace GameLib {
/**
 * @brief Mother class for all entities
 */
class Entity : public PhysicalObject {
public:
  Entity(const Point &starting_position, const Shape &shape);
  virtual ~Entity();

  /**
   * @brief Set the acceleration vector
   */
  void setAcceleration(const Vec2 &new_acceleration);

  /**
   * @brief Get the acceleration vector
   */
  const Vec2 &getAcceleration(void) const;

  /**
   * @brief Get the current speed
   */
  const Vec2 &getSpeed(void) const;

  /**
   * @brief Make the entity update his speed using his acceleration vector
   */
  void updateSpeed(void);

  /**
   * @brief Make the Entity update its acceleration vector depending on its underlying type
   */
  virtual void updateAcceleration(void) = 0;

  /**
   * @brief Check if the current entity would collide, update its acceleration vector if needed.
   *
   * @param position The physical object to test
   */
  virtual void checkForCollision(const PhysicalObject &other) = 0;

  /**
   * @brief Updates the entity's state according to the other
   *
   * @param other The entity to interact with
   */
  virtual void manageInteraction(const Entity &other) = 0;

private:
  Vec2 acceleration{0.0, 0.0};                     /**< Acceleration vector */
  static constexpr double MAX_HORIZONTAL_SPEED{0}; /**< Maximum speed for horizontals movements */
  Vec2 current_speed{0.0,
                     0.0}; /**< Current vector speed. The projection on x axis must be less than MAX_HORIZONTAL_SPEED */
};

} // namespace GameLib
