#pragma once

#include "Entity.hpp"

#include <chrono>

#include "GeometryUtilities.hpp"

namespace GameLib {

class Magnetick : public Entity {
public:
  Magnetick(const Point &starting_position, const Shape &shape);

  void updateAcceleration(void) override;
  void checkForCollision(const PhysicalObject &other) override;
  void manageInteraction(const Entity &other) override;

  bool isAttached(void) const;
  bool shouldDetatch(void) const;

private:
  Point target_position;
  bool is_attached{false};
  static constexpr double MAX_HORIZONTAL_SPEED{100.0};
  std::chrono::time_point<std::chrono::high_resolution_clock> attached_time{};
  static constexpr std::chrono::seconds ATTACHMENT_DURATION{10};
};

}; // namespace GameLib
