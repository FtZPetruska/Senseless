#pragma once

#include <optional>
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

  /**
   * @brief Compute the distance between two points
   *
   * @param other The other point
   *
   * @return The distance
   */
  double distance(const Point &other) const;

  int x; /**< Horizontal coordinate */
  int y; /**< Vertical coordinate */
};

/**
 * @brief Define the axis in which the collision happened
 */
enum class CollisionDirection {
  UP,
  RIGHT,
  DOWN,
  LEFT,
  NO_COLLISION
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
  virtual CollisionDirection contains(const std::vector<Point> &other_vertices, const Vec2 &acceleration) const;

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

  CollisionDirection contains(const std::vector<Point> &other_vertices, const Vec2 &acceleration) const override;

private:
  /**
   * @brief Find the orientation of the collision 
   *
   * @param vertex_index The index of the vertex with which the collision occured
   * 
   * @return The direction of the collsion
   */
  CollisionDirection vertexIndexToColisionDirection(std::size_t vertex_index) const;

  void computeVertices(void);
  Point origin;
  int width, height;
};

struct Segment : public Shape {
  Segment(const Point &a, const Point &b);
  std::optional<const Point> intersect(const Segment &other, double epsilon = 0.01) const;
  bool isOnSegment(const Point &p) const;

  Point a;
  Point b;
};

} // namespace GameLib
