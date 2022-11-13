#pragma once

#include "Entity.hpp"

namespace GameLib {
/**
 * @brief Main playable charactere
 */
class Player : public Entity {
public:
  /**
   * @brief Get the remaining count of player's item
   *
   * @return The player count
   */
  int getItemCount(void) const;

  /**
   * @brief Set the item count
   */
  void setItemCount(int item_count);

  /**
   * @brief Remove n items from the player inventory
   */
  void removeItems(int number);

  /**
   * @brief Tell if the player is able to jump
   *
   * @return True if the player can jump, false otherwise
   */
  bool isAbleToJump(void) const;

  /**
   * @brief Set the player ability to jump
   */
  void setJumpStatus(bool can_jump);

private:
  int item_count; /**< The remaining item count in player inventory */
  bool can_jump;  /**< True if the player is able to jump, false otherwise */
};

} // namespace GameLib
