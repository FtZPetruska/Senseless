#include "GeometryUtilities.hpp"

using namespace GameLib;

Rectangle::Rectangle(const Point &origin, int width, int height) : origin(origin), width(width), height(height) {
  computeVertices();
}

void Rectangle::computeVertices(void) {
  vertices = {
      {origin}, {origin.x + width, origin.y}, {origin.x + width, origin.y + height}, {origin.x, origin.y + height}};
}
