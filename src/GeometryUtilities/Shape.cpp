#include "GeometryUtilities.hpp"

#include <stdexcept>
#include <string>

using namespace GameLib;

Shape::Shape(const std::vector<Point> &shape_vertices) : vertices(shape_vertices) {
  static constexpr std::size_t MIN_VERTICES_COUNT{2};
  if (vertices.size() < MIN_VERTICES_COUNT) {
    static const std::string ERROR_MESSAGE =
        "You cannot create a Shape with less than " + std::to_string(MIN_VERTICES_COUNT) + " vertices";
    throw std::logic_error(ERROR_MESSAGE);
  }
}

Shape::~Shape() {}

const std::vector<Point> &Shape::getVertices(void) const {
  return vertices;
}

CollisionDirection Shape::wouldShapeCollideAfterMovement(const Shape &moving_shape, const Vec2 &movement) const {
  return Rectangle::narrowShapeToRectangle(*this).wouldShapeCollideAfterMovement(moving_shape, movement);
}

bool Shape::operator==(const Shape &other) const {
  return getNormalisedVertices() == other.getNormalisedVertices();
}

std::vector<Point> Shape::getNormalisedVertices(void) const {
  const Point &origin = vertices.front();
  const Vec2 TRANSLATION_VECTOR = {origin.x * -1.0, origin.y * -1.0};
  std::vector<Point> translated_vertices{};
  translated_vertices.reserve(vertices.size());
  for (const auto &point : vertices) {
    translated_vertices.emplace_back(point.translate(TRANSLATION_VECTOR));
  }
  return translated_vertices;
}

void Shape::move(const Vec2 &translation) {
  for (auto &point : vertices) {
    point = point.translate(translation);
  }
}
