#pragma once

#include <queue>

namespace GameLib {

/**
 * @brief Player movement commands.
 */
enum class Command {
  MOVE_RIGHT,
  MOVE_LEFT,
  JUMP,
  NO_COMMAND
};

using CommandQueue = std::queue<Command>;

} // namespace GameLib
