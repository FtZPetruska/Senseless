#pragma once

#include "Entity.hpp"

namespace GameLib {

class Player : public Entity {
public:
  int getItemCount(void) const;
  void setItemCount(int item_count);
  bool isAbleToJump(void) const;
  void setJumpStatus(bool can_jump);

private:
  int item_count;
  bool can_jump;
};

} // namespace GameLib
