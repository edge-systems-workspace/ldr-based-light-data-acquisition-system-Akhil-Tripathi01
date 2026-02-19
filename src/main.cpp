#include <Arduino.h>
/**
 * @file main.ino
 * @brief Embedded Light Intensity Monitoring using LDR
 * @author akhil
 * @date 2026-02-19
 *
 * @details
 * Reads analog brightness data from LDR sensor
 * and displays structured output via Serial Monitor.
 */

const int LDR_PIN = A0;
int sensorReading = 0;
const int BRIGHTNESS_THRESHOLD = 512;

void setup() {
    Serial.begin(9600);
    Serial.println("LDR Light Intensity Monitoring System Initialized");
}

void loop() {
    sensorReading = analogRead(LDR_PIN);
    Serial.print("Raw ADC Value: ");
    Serial.println(sensorReading);

    if (sensorReading > BRIGHTNESS_THRESHOLD) {
        Serial.println("Status: BRIGHT");
    } else {
        Serial.println("Status: DARK");
    }

    delay(1000);
}
