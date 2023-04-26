#include <Arduino.h>
#include<H4Plugins.h>
H4_USE_PLUGINS(115200,20,false) // Serial baud rate, Q size, SerialCmd autostop

#define RELAY_BUILTIN 5
#define BUTTON_BUILTIN 18

#define SSID    "XXXXXXXX"
#define PASS    "XXXXXXXX"

void onChange(const std::string& name,const std::string& value){
    Serial.printf("ITEM %s changed to %s\n",CSTR(name),CSTR(value));
}
#define USER_BTN 0
#define UB_ACTIVE ACTIVE_LOW
#define UB_MS   20

H4P_Signaller sig;

h4pOutput builtinLED(LED_BUILTIN, H4P_ASSUMED_SENSE,OFF);

H4P_WiFi h4wifi(SSID, PASS, "H4-Test");
H4P_AsyncMQTT h4mqtt("http://192.168.1.34:1883"); // Server IP
H4P_UPNPServer h4upnp("My Light");
H4P_BinarySwitch h4onof(RELAY_BUILTIN, ACTIVE_LOW, H4P_UILED_BLUE, OFF, 2000);
h4pMultifunctionButton h43fb(BUTTON_BUILTIN, INPUT_PULLUP, ACTIVE_LOW, 15);

void h4setup() {
    h4p.info();

    h4p.gvSetstring("secret","life, the universe and everything");
    h4p["peasy"]="easy"; //can also set string values like this
    std::string easy=h4p["peasy"]; // or get them like this
    easy=h4p.gvGetstring("peasy"); // and this
    Serial.printf("Using H4P_PersistentStorage is %s\n",CSTR(h4p["peasy"]));

    if(!h4p.gvExists("answer")){
        Serial.printf("What is the secret of %s?\n",CSTR(h4p["secret"]));
        h4p.gvSetInt("answer",42);
        Serial.println("send h4/reboot to find out");
    }
    else {
        Serial.printf("Apparently the secret of %s is %d\n",CSTR(h4p["secret"]),h4p.gvGetInt("answer"));
        h4p.gvInc("answer"); // increments the value: can also dec it
        Serial.println("send h4/reboot repeatedly to see increasingly WRONG answer");
    }
}

H4P_EventListener gpio(H4PE_GPIO,[](const std::string& pin,H4PE_TYPE t,const std::string& msg){
    int p=atoi(pin.c_str());
    int v=atoi(msg.c_str());
    switch(p){
      case USER_BTN:
//        Serial.printf("P%d V = %d\n",p,v);
        switch(v){
            case -2:
                Serial.printf("Entering 3nd stage!\n"); // over 5 sec
                break;
            case -1:
                Serial.printf("Entering 2nd stage!\n"); // 2sec - 5 sec
                break;
            case 0:
                Serial.printf("SHORT Press\n"); // < 2 sec
                builtinLED.toggle();
                h4onof.turnOn();
                break;
            case 1:
                Serial.printf("MEDIUM Press\n"); // 2 -5 sec
                h4.nTimes(3,250,[=]{ sig.pulsePin(125,LED_BUILTIN); });
                builtinLED.turnOff();                
                break;
            case 2:
                Serial.printf("LONG Press\n"); // over 5 sec
                h4.nTimes(5,150,[=]{ sig.pulsePin(75,LED_BUILTIN); });
                builtinLED.turnOff();                
                break;
        }
        break;
    }
});

H4P_EventListener stateListener (H4PE_GVCHANGE,[](const std::string& svc,H4PE_TYPE t,const std::string& msg){
    Serial.printf("GVChange %s is %s\n",CSTR(svc),CSTR(msg));
    if (svc == "state") {
        if (msg == "1")
        {
            h4p.gvInc("starts");

        }
    }
});