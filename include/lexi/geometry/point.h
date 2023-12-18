#pragma once

#include <cstdint>
#include <utility>

namespace lexi {

class Point {
 public:
  Point() : x_(0), y_(0) {}
  Point(uint32_t x, uint32_t y) : x_(x), y_(y) {}
  Point(const Point& p) : x_(p.x_), y_(p.y_) {}
  Point(Point&& p) noexcept : x_(std::exchange(p.x_, 0)), y_(std::exchange(p.y_, 0)) {}

  Point& operator=(const Point& p) {
    if (this != &p) {
      x_ = p.x_;
      y_ = p.y_;
    }

    return *this;
  }

  Point& operator=(Point&& p) noexcept {
    if (this != &p) {
      x_ = std::exchange(p.x_, 0);
      y_ = std::exchange(p.y_, 0);
    }

    return *this;
  }

  ~Point() = default;

  uint32_t& x() { return x_; }
  uint32_t& y() { return y_; }

 private:
  uint32_t x_{0};
  uint32_t y_{0};
};

}  // namespace lexi