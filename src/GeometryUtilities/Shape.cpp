#include "GeometryUtilities.hpp"

using namespace GameLib;

Shape::Shape(const std::vector<Point> &vertices) : vertices(vertices) {}

Shape::Shape() {}

Shape::~Shape() {}

const std::vector<Point> &Shape::getVertices(void) const {
  return vertices;
}

CollisionDirection Shape::contains(const std::vector<Point> &other_vertices, const Vec2 &acceleration) const {
  (void)other_vertices[0].translate(acceleration);
  throw std::bad_exception();
}