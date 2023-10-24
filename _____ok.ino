#include "FastLED.h" 
#define trigPin 10
#define echoPin 9
#define NUM_LEDS 30             
#define DATA_PIN 5             
#define LED_TYPE WS2812B         
#define COLOR_ORDER GRB         
int BuzzerPin = 7;
uint8_t max_bright = 120;

CRGB leds[NUM_LEDS];

void setup() {
  
  Serial.begin (9600);
  delay(1000);  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(BuzzerPin, OUTPUT);//蜂鸣器管脚口
 
}

void loop()
{

  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  digitalWrite(BuzzerPin, HIGH); 
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  LEDS.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(max_bright); 
   

  if (distance < 160 )
   {
    digitalWrite(BuzzerPin, LOW);
  delay(20);
   //熄灭光带所有灯珠
   for (int i = 0; i <= NUM_LEDS; i++) {    
    leds[i] = CRGB::Red;
    FastLED.show();
  }
  for (int i = 0; i <= NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
    FastLED.show();  
  }
  delay(10);
   }
    Serial.print("@");
   Serial.print(distance);
   Serial.print("@,");
   delay(20);
}
