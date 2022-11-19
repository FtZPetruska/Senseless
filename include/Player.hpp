#pragma once

#include <chrono>
#include <queue>

#include "Command.hpp"
#include "Entity.hpp"
#include "GeometryUtilities.hpp"

namespace GameLib {
/**
 * @brief Main playable charactere
 */
class Player : public Entity {
public:
  Player(const Point &starting_position, const Shape &shape);

  void updateAcceleration(void) override;
  void checkForCollision(const PhysicalObject &other) override;
  void manageInteraction(const Entity &other) override;

  /**
   * @brief Consummes the commands in the queue and update the internal state
   */
  void processCommands(const CommandQueue &commands);

  /**
   * @brief Get the remaining count of player's item
   *
   * @return The player count
   */
  int getItemCount(void) const;

  /**
   * @brief Set the item count
   */
  void setItemCount(int new_item_count);

  /**
   * @brief Remove n items from the player inventory
   */
  void removeItems(int count);

  /**
   * @brief Get the position from which the sonar was last used
   */
  const Point &getLastSonarPosition(void) const;

  /**
   * @brief Get whether a Magnetick is currently attached
   */
  bool hasMagnetickAttached(void) const;

  /**
   * @brief Attach a Magnetick
   */
  void attachMagnetick(void);

  /**
   * @brief Pop a Magnetick
   */
  void popMagnetick(void);

private:
  void tryJump(void);
  void trySonar(void);

  int item_count{3};      /**< The remaining item count in player inventory */
  bool can_jump{false};   /**< True if the player is able to jump, false otherwise */
  int magnetick_count{0}; /**< Count of how many magnetick are currently attached */
  std::chrono::time_point<std::chrono::high_resolution_clock>
      last_sonar_time_point{};                             /**< Time point of the last sonar */
  Point last_sonar_position;                               /**< Position from which the last sonar was executed */
  static constexpr std::chrono::seconds SONAR_COOLDOWN{1}; /**< Cooldown between two sonar usage */
  CommandQueue commands_backlog{};                         /**< Queue of all the commands to be processed */
  static constexpr double MAX_HORIZONTAL_SPEED{50.0};
};

} // namespace GameLib
