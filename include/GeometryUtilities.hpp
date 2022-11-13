#pragma once

#include <vector>

namespace GameLib {

/**
 * @brief Simple 2D cartesian Vector
 */
struct Vec2 {
  Vec2 operator+(const Vec2 &other) const;
  Vec2 operator-(const Vec2 &other) const;
  bool operator==(const Vec2 &other) const;

  /**
   * @brief Clamp the vector's displacement on the x axis
   *
   * @param limit The absolute value to clamp the vector with
   */
  void horizontalClamp(double limit);

  double dx; /**< Displacement on the x axis */
  double dy; /**< Displacement on the y axis */
};

/**
 * @brief Simple 2D point in a cartesian plane
 *
 * @Note The Y axis is inverted (increases by going down)
 */
struct Point {
  bool operator==(const Point &other) const;

  /**
   * @brief Translate a point with a vector
   *
   * @param translation The vector to translate with
   * @return The translated point
   */
  Point translate(const Vec2 &translation) const;

  int x; /**< Horizontal coordinate */
  int y; /**< Vertical coordinate */
};

/**
 * @brief Define the axis in which the collision happened
 */
enum class CollisionDirection {
  NO_COLLISION,
  HORIZONTAL,
  VERTICAL
};

/**
 * @brief Representation of an arbitrary shape
 */
class Shape {
public:
  Shape(const std::vector<Point> &vertices);
  virtual ~Shape();

  /**
   * @brief Get the vertices defining the figure
   *
   * @return A collection of the points
   */
  const std::vector<Point> &getVertices(void) const;

  /**
   * @brief Test if the given position is contained within the shape
   *
   * @param position The position to test
   * @return The type of collision that occured
   */
  virtual CollisionDirection contains(const Point &position);

protected:
  Shape();

  /**
   * @brief Buffer of the points defining the shape
   */
  std::vector<Point> vertices{};
};

class Rectangle : public Shape {
public:
  /**
   * @brief Construct a rectangle from the top-left vertex.
   *
   * @param origin, top left vertex of the rectangle
   * @param width, width of the rectangle
   * @param height, height of the rectangle
   *
   * @note The vertices are computed clock-wise
   */
  Rectangle(const Point &origin, int width, int height);

private:
  void computeVertices(void);
  Point origin;
  int width, height;
};

} // namespace GameLib
