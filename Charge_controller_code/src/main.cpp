#include <Arduino.h>

#include <Wire.h>
#include "MCP3X21.h"

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
const uint8_t address_02 = 0b1001010;
const uint8_t address_05 = 0b1001101;
MCP3021 battery_ADC(address_02);
MCP3021 current_ADC(address_05);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello World!");
  Wire.begin();
  battery_ADC.init();
  current_ADC.init();

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

    uint16_t raw_battery_voltage = battery_ADC.read();
    uint16_t raw_current_voltage = current_ADC.read();
    uint16_t battery_voltage = battery_ADC.toVoltage(raw_battery_voltage, ADC_ref_voltage);
    uint16_t current_voltage = current_ADC.toVoltage(raw_current_voltage, ADC_ref_voltage);

    Serial.print("Battery ADC: " + String(raw_battery_voltage) + ", mV: " + String(battery_voltage));
    Serial.print("  \t");
    Serial.println("Current ADC: " + String(raw_current_voltage) + ", mV: " + String(current_voltage));
    Serial.println();

    delay(500);
}