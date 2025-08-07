#include <Arduino.h>
#include <GxEPD2_BW.h>
#include "GxEPD2_display_selection_new_style.h"

#define EPD_PWR   22

void setup() {
  Serial.begin(115200);
  Serial.println("Starting display test...");
  delay(100);

  // Enable display power (required for newer revisions)
  pinMode(EPD_PWR, OUTPUT);
  digitalWrite(EPD_PWR, HIGH);
  delay(100);

  // Initialize display
  display.init(115200, true, 2, false);
  display.setRotation(1);  // Landscape orientation

  // Test 1: Full screen refresh with text
  Serial.println("Test 1: Full screen refresh");
  display.setFullWindow();
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.setTextColor(GxEPD_BLACK);
    display.setTextSize(5);
    display.setCursor(200, 240);
    display.print("Display Test");
    
    // Add some test patterns
    display.drawRect(50, 50, 100, 100, GxEPD_BLACK);
    display.fillRect(200, 50, 100, 100, GxEPD_BLACK);
    display.drawCircle(400, 100, 50, GxEPD_BLACK);
    
    // Show display info
    display.setTextSize(2);
    display.setCursor(50, 300);
    display.printf("Resolution: %dx%d", display.width(), display.height());
    display.setCursor(50, 330);
    display.print("Controller: GxEPD2_426_GDEQ0426T82");
    
  } while (display.nextPage());

  delay(3000);

  // Test 2: Partial refresh demo
  Serial.println("Test 2: Partial refresh");
  int partialY = 360;
  int partialH = 40;
  display.setPartialWindow(0, partialY, display.width(), partialH);
  
  for (int i = 0; i < 5; i++) {
    display.firstPage();
    do {
      display.fillScreen(GxEPD_WHITE);
      display.setTextColor(GxEPD_BLACK);
      display.setTextSize(3);
      display.setCursor(10, partialY + 24);
      display.printf("Partial refresh: %d/5", i + 1);
    } while (display.nextPage());
    delay(1000);
  }

  // Test 3: Graphics test
  Serial.println("Test 3: Graphics patterns");
  display.setFullWindow();
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    
    // Grid pattern
    for (int x = 0; x < display.width(); x += 40) {
      display.drawLine(x, 0, x, display.height(), GxEPD_BLACK);
    }
    for (int y = 0; y < display.height(); y += 40) {
      display.drawLine(0, y, display.width(), y, GxEPD_BLACK);
    }
    
    // Center text
    display.setTextSize(4);
    display.setTextColor(GxEPD_BLACK);
    display.setCursor(250, 220);
    display.print("Grid Test");
    
  } while (display.nextPage());

  delay(3000);

  // Put display to sleep to save power
  display.hibernate();
  Serial.println("Display test complete!");
}

void loop() {
  // Nothing to do in loop
}