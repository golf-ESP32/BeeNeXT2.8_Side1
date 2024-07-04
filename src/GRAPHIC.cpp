#include <BlynkGOv3.h>
// IMG_DECLARE(img_bnt1);
// IMG_DECLARE(img_bnt2);

GGaugeRainbow gauge;
GButton btn_motor(BUTTON_SWITCH, "motor");
// GImageButton btn_motor(BUTTON_SWITCH, img_btn1, img_btn2);

namespace GRAPHIC {
  void design();
  void temp(float temp);
  void sw_motor(bool enable);
}

void GRAPHIC::design(){
  gauge.color(TFT_BLUE, TFT_RED);
  gauge.decimal(2);
  gauge = 0;

  btn_motor.align(ALIGN_TOP_RIGHT,-5,5);
}

void GRAPHIC::temp(float temp){
  gauge = temp;
}

void GRAPHIC::sw_motor(bool enable){
  if(enable){
    btn_motor.ON();
  }else{
    btn_motor.OFF();
  }
}
