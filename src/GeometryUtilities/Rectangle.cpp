#include "GeometryUtilities.hpp"

using namespace GameLib;

Rectangle::Rectangle(const Point &origin, int width, int height) : origin(origin), width(width), height(height) {
  computeVertices();
}

/** TODO */
CollisionDirection Rectangle::contains(const std::vector<Point> &other_vertices, const Vec2 &acceleration) {
  CollisionDirection collision_direction = CollisionDirection::NO_COLLISION;
  for (const auto &vertex : other_vertices) {
    Point translated_vertex = vertex.translate(acceleration); 
    if (translated_vertex.x >= origin.x && translated_vertex.x <= origin.x + width && translated_vertex.y >= origin.y ||
        translated_vertex.y <= origin.y + height) {
      return CollisionDirection::NO_COLLISION;
    }
  }
  return CollisionDirection::NO_COLLISION;
}

std::pair<double, CollisionDirection> Rectangle::caracterizeCollision(const Point &other_vertex,
                                                                      const Point &other_translated_vertex) const {
  Segment other{other_vertex, other_translated_vertex};
  for (int i = 1; i < vertices.size(); i++) {
    Segment current_segment{vertices[i - 1], vertices[i]};
    std::optional<Point> intersection = current_segment.intersect(other);
    if (intersection.has_value()) {
      if (i % 2 == 1) {
        return std::pair<double, CollisionDirection>{other_vertex.distance(intersection.value()),
                                                     CollisionDirection::HORIZONTAL};
      } else {
        return std::pair<double, CollisionDirection>{other_vertex.distance(intersection.value()),
                                                     CollisionDirection::VERTICAL};
      }
    }
  }
  return std::pair<double, CollisionDirection>{-1, CollisionDirection::NO_COLLISION};
}

void Rectangle::computeVertices(void) {
  vertices = {
      {origin}, {origin.x + width, origin.y}, {origin.x + width, origin.y + height}, {origin.x, origin.y + height}};
}
