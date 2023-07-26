#include <Arduino.h>

#include <Wire.h>
#include "MCP3X21.h"
#include "MCP4716.hpp"

#define RELAY 5
#define LED_1 6
#define LED_2 9
#define LED_3 10
#define LED_ONBOARD_1 13
#define LED_ONBOARD_2 8

// initialize ADC
// according to the datasheet, the device address is given by
// 1001 followed by the custom device address, either 2 or 5
// in binary, this is 1001 010 and 1001 101
const uint16_t ADC_ref_voltage = 5 * 1000;  // in mV
const uint8_t ADC_address_02 = 0b1001010;
const uint8_t ADC_address_05 = 0b1001101;
const uint8_t DAC_address = 0b1100001; // 0x60;
MCP3021 battery_ADC(ADC_address_02);
MCP3021 current_ADC(ADC_address_05);
MCP4716 current_DAC(DAC_address);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello World!");
  Wire.begin();
  battery_ADC.init();
  current_ADC.init();
  current_DAC.setGain(1);
  current_DAC.setVref(1);

  // set pin modes
  pinMode(RELAY, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_ONBOARD_1, OUTPUT);
  pinMode(LED_ONBOARD_2, OUTPUT);
  pinMode(A0, OUTPUT);

  // initialize all pins to low
  // digitalWrite(RELAY, HIGH);
  digitalWrite(RELAY, LOW);
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
  digitalWrite(LED_3, LOW);
  digitalWrite(LED_ONBOARD_1, LOW);
  digitalWrite(LED_ONBOARD_2, LOW);
}

void loop() {
  // Serial.println("Restarting Loop...");
  // digitalWrite(RELAY, HIGH);
  // delay(200);
  // digitalWrite(LED_1, HIGH);
  // delay(200);
  // digitalWrite(LED_2, HIGH);
  // delay(200);
  // digitalWrite(LED_3, HIGH);
  // delay(200);
  // digitalWrite(LED_ONBOARD_1, HIGH);
  // delay(200);
  // digitalWrite(LED_ONBOARD_2, HIGH);
  // delay(200);
  // digitalWrite(RELAY, LOW);
  // digitalWrite(LED_1, LOW);
  // digitalWrite(LED_2, LOW);
  // digitalWrite(LED_3, LOW);
  // digitalWrite(LED_ONBOARD_1, LOW);
  // digitalWrite(LED_ONBOARD_2, LOW);
  // delay(1000);

    current_DAC.setVout(int(1.25 * 1024 / 5));
    uint16_t raw_battery_voltage = battery_ADC.read();
    uint16_t raw_current_voltage = current_ADC.read();
    uint16_t battery_voltage = battery_ADC.toVoltage(raw_battery_voltage, ADC_ref_voltage);
    uint16_t current_voltage = current_ADC.toVoltage(raw_current_voltage, ADC_ref_voltage);
    uint16_t current = current_voltage / 0.010 / 20 / 5; // delta V / R / 20 gain / 5 gain

    Serial.print("Battery ADC: " + String(raw_battery_voltage) + ", voltage: " + String(battery_voltage) + "mV");
    Serial.print("  \t");
    Serial.println("Current ADC: " + String(raw_current_voltage) + ", voltage: " + String(current_voltage) + "mV, current = " + String(current) + "mA");
    // Serial.println();

    // current_DAC.setVout(int(0 * 1024 / 5));
    delay(500);

}