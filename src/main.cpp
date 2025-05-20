#include <Arduino.h>

#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
 
int RECV_PIN = 21;
 
IRrecv irrecv(RECV_PIN);
 
decode_results results;

String button;

unsigned int ir_data[25] = {0x00FF906F, 0x00FFC03F, 0x00FF38C7, 0x00FFA05F, 0x00FF708F, 0x00FF58A7, 0x00FF50AF, 0x00FF7887, 0x00FF40BF, 0x00FF30CF, 0x00FF2AD5, 0x00FF32CD, 0x00FF3AC5, 0x00FF8A75, 0x00FFB04F, 0x00FF9867, 0x00FFD827, 0x00FF807F, 0x00FF8877, 0x00FFA857, 0x00FFE817, 0x00FF609F, 0x00FF48B7, 0x00FF6897, 0xFFFFFFFF};

String ir_value[25] = {"Power On/Off", "Mute", "Menu", "Ok", "Up", "Down", "Left", "Right", "Volume +", "Volume -", "Pause", "Signal", "View", "Audio", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", " "};

String key(unsigned int value) {
  for (int i = 0; i < 25; i++){
    if (value == ir_data[i]){
      return ir_value[i];
      break;
    }
  }
  return "\0";
}
 
void setup()
{
  Serial.begin(115200);
  irrecv.enableIRIn();
  Serial.println("DD Free Dish Remote Button Test :-");
}
void loop() {
  if (irrecv.decode(&results)) {
    button = key(results.value);
    if (button == " "){
      
    } else if (button == "\0"){
      Serial.print("Invalid Code - ");
      Serial.println(results.value, HEX);
    } else {
      Serial.println(button);
    }
    irrecv.resume();
  }
}