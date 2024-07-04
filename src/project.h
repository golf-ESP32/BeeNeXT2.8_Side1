#pragma once

#include <BlynkGOv3.h>

namespace GRAPHIC {
  void design();
  void temp(float temp);
  void sw_motor(bool enable);
}

namespace beenext {
  void init(void (*fn_cb)(String key, String value));
  void send(String key, String value);
}