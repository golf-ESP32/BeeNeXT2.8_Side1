#include <BeeNeXT.h>
#include "project.h"


namespace beenext {
  void init(void (*fn_cb)(String key, String value));
  void send(String key, String value);
}

void (*_fn_cb)(String key, String value) =NULL;

void beenext::init(void (*fn_cb)(String key, String value)){
  _fn_cb =  fn_cb;
  static SoftTimer timer;
  timer.setInterval(1,[](){
    if( Serial.available()){
      String raw = Serial.readStringUntil('\n'); raw.trim();
      // Serial.println(raw);
      if(raw.startsWith("[BN]")){
        raw.replace("[BN]", "");
        int idx = raw.indexOf(":");
        String key = raw.substring(0, idx);
        String value = raw.substring(idx+1);
        // Serial.println(key);
        // Serial.println(value);
        if( _fn_cb !=NULL) _fn_cb(key, value);
      }
    }
  });
}

void beenext::send(String key, String value){
  String data = String("[BN]")+key+String(":")+value;
  Serial.println(data);
}