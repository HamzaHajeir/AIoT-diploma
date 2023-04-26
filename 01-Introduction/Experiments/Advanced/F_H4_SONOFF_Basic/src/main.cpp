#include <Arduino.h>
#include<H4Plugins.h>
H4_USE_PLUGINS(115200,20,false) // Serial baud rate, Q size, SerialCmd autostop

#define SSID    "WIFI_SSID"
#define PASS    "WIFI_PASS"

H4P_WiFi h4wifi(SSID,PASS,"H4-Test");
H4P_AsyncMQTT h4mqtt("http://broker.emqx.io:1883");
H4P_BinarySwitch h4onof(25,ACTIVE_HIGH,OFF);
H4P_UPNPServer h4upnp("Test SONOFF");
h4pMultifunctionButton h43fb(26,INPUT_PULLUP,ACTIVE_LOW,15);
