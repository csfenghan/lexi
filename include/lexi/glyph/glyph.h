#pragma once

#include "lexi/geometry/point.h"
#include "lexi/geometry/rect.h"
#include "lexi/window/window.h"

namespace lexi {

class Glyph {
 public:
  virtual void Draw(Window*) = 0;
  virtual void Bounds(Rect&) = 0;

  virtual bool Intersects(const Point&) = 0;

  virtual void Insert(Glyph*, int) = 0;
  virtual void Remove(Glyph*) = 0;
  virtual Glyph* Child(int) = 0;
  virtual Glyph* Parent() = 0;
};

}  // namespace lexi
