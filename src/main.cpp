#include <Arduino.h>
#include <TSIC.h> // include the library

TSIC Sensor1(21); // only Signalpin, VCCpin unused by default

uint16_t temperature = 0;
float Temperatur_C = 0;

#include <U8x8lib.h>
// the OLED used
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/15, /* data=*/4, /* reset=*/16);

void setup()
{
  Serial.begin(9600); // set up the serial port

  u8x8.begin();
  u8x8.setFont(u8x8_font_8x13B_1x2_r);
}

void loop()
{
  //u8x8.clear();
  if (Sensor1.getTemperature(&temperature))
  {
    Serial.print("uint_16: ");
    Serial.println(temperature);
    Temperatur_C = Sensor1.calc_Celsius(&temperature);
    Serial.print("Temperature: ");
    Serial.print(Temperatur_C);
    Serial.println(" °C");
    u8x8.setCursor(0, 0);
    u8x8.print("Temperature:  ");
    u8x8.setCursor(0, 4);
    u8x8.print(Temperatur_C);
  }
  else
  {
    Serial.print("Not able to read temperature!!!");
    u8x8.print("Not able to read temperature!!!");
  }
  delay(1000); // wait 1 seconds
}