#include "GeometryUtilities.hpp"

using namespace GameLib;

Rectangle::Rectangle(const Point &origin, int width, int height) : origin(origin), width(width), height(height) {
  computeVertices();
}

CollisionDirection Rectangle::contains(const std::vector<Point> &other_vertices, const Vec2 &acceleration) const {
  CollisionDirection closest_collision_direction = CollisionDirection::NO_COLLISION;
  double closest_distance_from_collision = std::numeric_limits<double>::max();
  for (const auto &vertex : other_vertices) {
    Point translated_vertex = vertex.translate(acceleration);
    Segment movement_trace(vertex, translated_vertex);
    for (int vertex_index = 0; vertex_index < vertices.size(); vertex_index++) {
      Segment edge(vertices[vertex_index], vertices[(vertex_index + 1) % vertices.size()]);
      std::optional<Point> intersection = movement_trace.intersect(edge);
      if (intersection.has_value()) {
        CollisionDirection current_collision_direction = vertexIndexToColisionDirection(vertex_index);
        double current_distance_from_collision = vertex.distance(intersection.value());
        if (current_distance_from_collision < closest_distance_from_collision) {
          closest_distance_from_collision = current_distance_from_collision;
          closest_collision_direction = current_collision_direction;
        }
      }
    }
  }
  return closest_collision_direction;
}

CollisionDirection Rectangle::vertexIndexToColisionDirection(int vertex_index) const {
  switch (vertex_index) {
  case 0:
    return CollisionDirection::UP;
    break;
  case 1:
    return CollisionDirection::RIGHT;
    break;
  case 2:
    return CollisionDirection::DOWN;
    break;
  case 3:
    return CollisionDirection::LEFT;
    break;
  default:
    throw std::bad_exception();
    break;
  }
}

void Rectangle::computeVertices(void) {
  vertices = {
      {origin}, {origin.x + width, origin.y}, {origin.x + width, origin.y + height}, {origin.x, origin.y + height}};
}
