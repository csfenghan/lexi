#pragma

#include <cstdint>
#include <utility>

namespace lexi {

class Rect {
 public:
  Rect() : x1_(0), y1_(0), x2_(0), y2_(0) {}
  Rect(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2) : x1_(x1), y1_(y1), x2_(x2), y2_(y2) {}
  Rect(const Rect& r) : x1_(r.x1_), y1_(r.y1_), x2_(r.x2_), y2_(r.y2_) {}
  Rect(Rect&& r) noexcept
      : x1_(std::exchange(r.x1_, 0)),
        y1_(std::exchange(r.y1_, 0)),
        x2_(std::exchange(r.x2_, 0)),
        y2_(std::exchange(r.y2_, 0)) {}

  Rect& operator=(const Rect& r) {
    if (this != &r) {
      x1_ = r.x1_;
      y1_ = r.y1_;
      x2_ = r.x2_;
      y2_ = r.y2_;
    }

    return *this;
  }

  Rect& operator=(Rect&& r) noexcept {
    if (this != &r) {
      x1_ = std::exchange(r.x1_, 0);
      y1_ = std::exchange(r.y1_, 0);
      x2_ = std::exchange(r.x2_, 0);
      y2_ = std::exchange(r.y2_, 0);
    }

    return *this;
  }

  ~Rect() = default;

  uint32_t& x1() { return x1_; }
  uint32_t& y1() { return y1_; }
  uint32_t& x2() { return x2_; }
  uint32_t& y2() { return y2_; }

 private:
  uint32_t x1_;
  uint32_t y1_;
  uint32_t x2_;
  uint32_t y2_;
};

}  // namespace lexi