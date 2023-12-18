#pragma once

#include "lexi/window_imp/window_imp.h"

namespace lexi {

class Window {
 public:
  virtual void Redraw() = 0;
  virtual void Raise() = 0;
  virtual void Lower() = 0;
  virtual void Iconify() = 0;
  virtual void Deiconify() = 0;

  virtual void DrawLine(...) = 0;
  virtual void DrawRect(...) = 0;
  virtual void DrawPolygont(...) = 0;
  virtual void DrawText(...) = 0;

 private:
  WindowImp* imp_{nullptr};
};

}  // namespace lexi
