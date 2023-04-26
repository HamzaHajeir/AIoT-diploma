#include <Arduino.h>
#include <H4Plugins.h>
#include "H4P_PinMachine.h"
#include "platform.h"

H4_USE_PLUGINS(115200,20,false) // Serial baud rate, Q size, SerialCmd autostop

h4pEncoderAuto rotary(ENCODER_A, ENCODER_B, INPUT, UB_ACTIVE, 0, 1023, 0, 50, false);
h4pDebounced centerbutton(BUTTON_PIN,INPUT,H4P_ASSUMED_SENSE,15); // 15 ms debounce time

H4P_EventListener gpio(H4PE_GPIO,[](const std::string& pin,H4PE_TYPE t,const std::string& msg){
    int p=atoi(pin.c_str());
    int v=atoi(msg.c_str());
    switch(p){
      case BUTTON_PIN:
        rotary.center();
        Serial.printf("CENTERED: value is %d\n",rotary.getValue());
        break;
      case ENCODER_A:
        Serial.printf("P%d V = %d\n",p,v);
        _HAL_analogWrite(LED_PIN, v);
        break;
    }
});

void h4setup() {
    Serial.println("H4P_GPIOManager EncodeAuto Example v"H4P_VERSION);
    Serial.print("GPIO ");Serial.print(BUTTON_PIN);Serial.print(" ACTIVE ");Serial.println(UB_ACTIVE ? "HIGH":"LOW");

    _HAL_attachAnalogPin(LED_PIN);
}