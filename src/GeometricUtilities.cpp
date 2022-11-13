#include "GeometryUtilities.hpp"

using namespace GameLib;

bool Point::operator==(const Point &other) const {
  return this->x == other.x && this->y == other.y;
}

Vec2 Vec2::operator+(const Vec2 &other) const {
  return {this->dx + other.dx, this->dy + other.dy};
}

Vec2 Vec2::operator-(const Vec2 &other) const {
  return {this->dx - other.dx, this->dy - other.dy};
}

bool Vec2::operator==(const Vec2 &other) const {
  return this->dx == other.dx && this->dy == other.dy;
}

Shape::Shape(const std::vector<Point> &vertices) : vertices(vertices) {}

Shape::Shape() {}

Shape::~Shape() {}

const std::vector<Point> &Shape::getVertices(void) const {
  return vertices;
}

Rectangle::Rectangle(const Point &origin, int width, int height) : origin(origin), width(width), height(height) {
  computeVertices();
}

void Rectangle::computeVertices(void) {
  vertices = {
      {origin}, {origin.x + width, origin.y}, {origin.x + width, origin.y + height}, {origin.x, origin.y + height}};
}
