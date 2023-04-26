#include <Arduino.h>
#include<H4Plugins.h>
H4_USE_PLUGINS(115200,H4_Q_CAPACITY,false) // Serial baud rate, Q size, SerialCmd autostop


uint32_t myCallback(std::vector<std::string> vs);
void onMQTTConnect();
void onMQTTDisconnect();
h4pOutput myOut(5,ACTIVE_LOW,OFF);


H4P_WiFi h4wifi("XXXXXXXX","XXXXXXXX","testbed");
H4P_AsyncMQTT h4mqtt("http://192.168.1.34:1883"); // no username / pword


void h4pGlobalEventHandler(const std::string& svc,H4PE_TYPE t,const std::string& msg){
    switch(t){
        H4P_DEFAULT_SYSTEM_HANDLER
        case H4PE_SERVICE:
            H4P_SERVICE_ADAPTER(MQTT);
            break;
    }
}

H4P_BinaryThing h4bt([](bool b){ 
    Serial.print("I am now ");      Serial.println(b ? "ON":"OFF");
    myOut.logicalWrite(b ? ON : OFF);
 });



void onMQTTConnect(){
    Serial.print("USER: MQTT connected\n");
    h4mqtt.subscribeDevice("mytopic",myCallback);       //Topic: IoTServo/mytopic
}

void onMQTTDisconnect(){
    Serial.print("USER: MQTT Disconnected\n");
    h4mqtt.unsubscribeDevice("mytopic");
}

uint32_t myCallback(std::vector<std::string> vs){
  Serial.printf("USER: Msg received with %d parts and payload=%s\n",vs.size(),H4PAYLOAD.c_str()); // convert payload to C-style string
  if(H4PAYLOAD=="good") {
      h4mqtt.publishDevice("goodpayload","Thank You!");
      return H4_CMD_OK;
  }
  else {
      h4mqtt.publishDevice("badpayload",H4PAYLOAD);
      return H4_CMD_PAYLOAD_FORMAT;
  }
}

void h4setup()
{
}
