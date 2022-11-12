#pragma once

#include <vector>

namespace GameLib {

/**
 * @brief Simple 2D point
 */
struct Point {
  int x; /**< Horizontal coordinate */
  int y; /**< Vertical coordinate */
};

/**
 * @brief Simple 2D cartesian Vector
 */
struct Vec2 {
  double dx; /**< Displacement on the x axis */
  double dy; /**< Displacement on the y axis */
};

/**
 * @brief Representation of an arbitrary shape
 */
class Shape {
public:
  /**
   * @brief Get the vertices defining the figure
   *
   * @return A collection of the points
   */
  const std::vector<Point> &getVertices(void) const;

private:
  /**
   * @brief Updates the internal vertices
   */
  virtual void computeVertices(void);

  /**
   * @brief Buffer of the points defining the shape
   */
  std::vector<Point> vertices;
};

struct Rectangle : public Shape {
public:
  Rectangle(const Point &origin, int width, int height, double angle = 0);

private:
  void computeVertices(void) override;
  Point origin;
  double angle;
  int width, height;
};

} // namespace GameLib
