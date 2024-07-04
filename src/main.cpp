#include <BlynkGOv3.h>
#include "project.h"

// GButton btn(BUTTON_SWITCH, "รีเลย์");

void setup() {
  Serial.begin(9600); Serial.println();
  BlynkGO.begin();
  beenext::init([](String key, String value){
    if(key == "TEMP"){
      float temp = value.toFloat();
      // Serial.println(temp);
      GRAPHIC::temp(temp);
    }
    // else
    // if(key == "MOTOR_SPEED55"){
    //   // int speed = value.toInt();
    //   // GRAPHIC::speed(speed);
    //   // IOT::speed(speed);
    // }else
    // if(key == "UNO_BTN"){
    //   bool uno_btn_state = value.toInt();
    //   GRAPHIC::sw_motor(uno_btn_state);
    // }
  });

  GRAPHIC::design();

  // btn.onValueChanged([](GWIDGET){
  //   beenext::send("RELAY1", String(btn.isON()));
  // });
}

void loop() {
  BlynkGO.update();
}
