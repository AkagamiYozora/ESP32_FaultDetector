#include <pt.h>
#include <NTPClient.h>
#include <WiFi.h> // for WiFi shield
#include <WiFiUdp.h>
#include <Adafruit_GFX.h>
#include <XTronical_ST7735.h>
#include <SPI.h>
#include <driver/adc.h>
#include <EmonLib.h>
#define ADC_BITS    10
#define ADC_COUNTS  (1<<ADC_BITS)
#include <FirebaseESP32.h>
FirebaseData object;

#define FIREBASE_HOST "faultdetector2-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "d372w8XzH6fboaTFn4irpjzFgYuzaqA91DjxDzKz"

static struct pt ntp, ct, fb;

EnergyMonitor emon1;
EnergyMonitor emon2;
EnergyMonitor emon3;

float val1, val2, val3;

const char *ssid     = "VINCE";
const char *password = "1313131313";

const long utcOffsetInSeconds = 25200;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

#define TFT_DC 5
#define TFT_RST 4
#define TFT_CS 2

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  setupLcd();
  setupCt();
  setupFb();
  timeClient.begin();
  delay(2000);
  mainLcd();
  PT_INIT(&ntp);
  PT_INIT(&ct);
  PT_INIT(&fb);
}

void loop() {
  // put your main code here, to run repeatedly:
  updateTime(&ntp);
  updateCT(&ct);
  updateFb(&fb);
}
