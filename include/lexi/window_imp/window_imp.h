#pragma once

namespace lexi {

class WindowImp {
 public:
  virtual void DeviceRaise() = 0;
  virtual void DeviceRect(...) = 0;
};

}  // namespace lexi
