#include "GeometryUtilities.hpp"

#include <array>
#include <limits>
#include <stdexcept>
#include <string>

using namespace GameLib;

static CollisionDirection vertexIndexToColisionDirection(std::size_t vertex_index);

Rectangle::Rectangle(const Point &origin, int width, int height)
    : Shape({{origin},
             {origin.x + width, origin.y},
             {origin.x + width, origin.y + height},
             {origin.x, origin.y + height}}) {
  if (width == 0) {
    throw std::logic_error("Cannot construct a Rectangle with width 0");
  }
  if (height == 0) {
    throw std::logic_error("Cannot construct a Rectangle with width 0");
  }
}

CollisionDirection Rectangle::wouldShapeCollideAfterMovement(const Shape &moving_shape, const Vec2 &movement) const {
  CollisionDirection closest_collision_direction = CollisionDirection::NO_COLLISION;
  double closest_distance_from_collision = std::numeric_limits<double>::max();
  const Rectangle NARROWED_SHAPE = narrowShapeToRectangle(moving_shape);
  const auto &local_vertices = getVertices();
  for (const auto &vertex : NARROWED_SHAPE.getVertices()) {
    Point translated_vertex = vertex.translate(movement);
    Segment movement_trace(vertex, translated_vertex);
    for (std::size_t vertex_index = 0; vertex_index < local_vertices.size(); vertex_index++) {
      Segment edge(local_vertices[vertex_index], local_vertices[(vertex_index + 1) % local_vertices.size()]);
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

static CollisionDirection vertexIndexToColisionDirection(std::size_t vertex_index) {
  static constexpr std::array<CollisionDirection, 4> INDEX_TO_COLLISION_TYPE{
      CollisionDirection::UP, CollisionDirection::RIGHT, CollisionDirection::DOWN, CollisionDirection::LEFT};
  return INDEX_TO_COLLISION_TYPE.at(vertex_index);
}

Rectangle Rectangle::narrowShapeToRectangle(const Shape &shape) {
  static constexpr std::size_t MIN_VERTICES_COUNT{3};
  if (shape.getVertices().size() < MIN_VERTICES_COUNT) {
    static const std::string ERROR_MESSAGE =
        "Cannot reduce a shape made from less than " + std::to_string(MIN_VERTICES_COUNT) + " local_vertices";
    throw std::logic_error(ERROR_MESSAGE);
  }

  Point origin{std::numeric_limits<int>::max(), std::numeric_limits<int>::max()};
  int max_x = std::numeric_limits<int>::min();
  int max_y = std::numeric_limits<int>::min();

  for (const auto &vertex : shape.getVertices()) {
    origin.x = std::min(origin.x, vertex.x);
    origin.y = std::min(origin.y, vertex.y);
    max_x = std::max(max_x, vertex.x);
    max_y = std::max(max_y, vertex.y);
  }
  return Rectangle(origin, max_x - origin.x, max_y - origin.y);
}
