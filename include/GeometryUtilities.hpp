#pragma once

#include <optional>
#include <vector>

namespace GameLib {

/**
 * @brief Simple 2D cartesian Vector
 */
struct Vec2 {
  /**
   * @brief Add each components
   */
  Vec2 operator+(const Vec2 &other) const;

  /**
   * @brief Substract each components
   */
  Vec2 operator-(const Vec2 &other) const;

  /**
   * @brief Check that each component are equal
   */
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
 * @note The Y axis is inverted (increases by going down)
 */
struct Point {
  /**
   * @brief Compares two points
   */
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

  /**
   * @brief Get a translation towards the destination with a max length
   *
   * @param destination The point to go toward
   * @param max_distance How far from the origin the result may be
   * @return The next point toward the destination, or the destination itself if closer than max_distance.
   */
  Vec2 getCappedTranslationVector(const Point &destination, double max_distance) const;

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
  /**
   * @brief Create an arbitrary shape from the vertices
   *
   * @pre vertices should be of size two or more, a std::logic_error is thrown otherwise
   */
  Shape(const std::vector<Point> &vertices);
  virtual ~Shape();

  /**
   * @brief Get the vertices defining the figure
   *
   * @return A collection of the points
   */
  const std::vector<Point> &getVertices(void) const;

  /**
   * @brief Get the normalised representation of the vertices
   *
   * @return The vertices uniformly translated so the first point is (0,0)
   */
  std::vector<Point> getNormalisedVertices(void) const;

  /**
   * @brief Check if a moving shape would collide with the current object
   *
   * @param moving_shape The shape moving
   * @param movement The vector describing the shape's movement
   * @return The type of collision that occured
   */
  virtual CollisionDirection wouldShapeCollideAfterMovement(const Shape &moving_shape, const Vec2 &movement) const;

  /**
   * @brief Verify if two shapes are the same once normalised
   */
  bool operator==(const Shape &other) const;

  /**
   * @brief Move a shape by a translation vector
   */
  void move(const Vec2 &translation);

private:
  std::vector<Point> vertices{}; /**< Buffer of the points defining the shape */
};

/**
 * @brief Specialisation of a Shape with only four distinct vertices in a rectangle shape
 */
class Rectangle : public Shape {
public:
  /**
   * @brief Construct a rectangle from the top-left vertex.
   *
   * @param origin top left vertex of the rectangle
   * @param width width of the rectangle
   * @param height height of the rectangle
   *
   * @note The vertices are computed clock-wise
   */
  Rectangle(const Point &origin, int width, int height);

  CollisionDirection wouldShapeCollideAfterMovement(const Shape &moving_shape, const Vec2 &movement) const override;

  /**
   * @brief Reduce a shape to a Rectangle
   *
   * @param shape Arbitrary shape
   * @return A rectangle shape based on the min/max positions of vertices
   *
   * @pre The shape should have three vertices, a std::logic_error is thrown otherwise
   */
  static Rectangle narrowShapeToRectangle(const Shape &shape);
};

/**
 * @brief Specialisation of a Shape made of only two distinct points.
 */
struct Segment : public Shape {
  /**
   * @brief Create a segment from two points
   *
   * @pre first and second must compare not equal, a std::logic_error is thrown otherwise
   */
  Segment(const Point &first, const Point &second);

  /**
   * @brief Searches for the intersection between two segments
   *
   * @param other The segment to check for an intersection with
   * @return An optional containing the intersection point if any
   */
  std::optional<const Point> intersect(const Segment &other) const;

  /**
   * @brief Checks if a point belongs to the segment
   *
   * @param candidate Candidate point to check
   * @return Whether the point is on the segment or not
   */
  bool isOnSegment(const Point &candidate) const;
};

} // namespace GameLib
