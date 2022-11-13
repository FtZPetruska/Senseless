#include "GeometryUtilities.hpp"

using namespace GameLib;

Shape::Shape(const std::vector<Point> &vertices) : vertices(vertices) {}

Shape::Shape() {}

Shape::~Shape() {}

CollisionDirection Shape::contains(const Point &position) {
  (void)position;
  return CollisionDirection::NO_COLLISION;
}

const std::vector<Point> &Shape::getVertices(void) const {
  return vertices;
}
