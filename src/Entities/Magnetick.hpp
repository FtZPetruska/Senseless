#pragma once

#include "Entity.hpp"

#include <chrono>

#include "GeometryUtilities.hpp"

namespace GameLib {

/**
 * @brief Specialisation of Entity that flies towards the player and attaches itself on contact
 */
class Magnetick : public Entity {
public:
  /**
   * @brief Create the Magnetick with a given position and shape
   */
  Magnetick(const Point &starting_position, const Shape &shape);

  void updateAcceleration(void) override;
  void checkForCollision(const PhysicalObject &other) override;
  void manageInteraction(const Entity &other) override;

  /**
   * @brief Checks if the Magnetick is attached to the player
   */
  bool isAttached(void) const;

  /**
   * @brief Checks if the Magnetick should detach from the player
   */
  bool shouldDetatch(void) const;

private:
  std::chrono::time_point<std::chrono::high_resolution_clock>
      attached_time{}; /**< Time point where the Magnetick attached itself onto the Player */
  static constexpr std::chrono::seconds ATTACHMENT_DURATION{10}; /**< How long should the Magnetick stay attached */
  Point target_position;                                         /**< Position the Magnetick is trying to move to */
  bool is_attached{false};                                       /**< Attached status */
  static constexpr double MAX_HORIZONTAL_SPEED{100.0};
};

}; // namespace GameLib
