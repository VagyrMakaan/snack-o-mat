// Example from https://randomnerdtutorials.com/esp32-mfrc522-rfid-reader-arduino/
// See page for actual circuit plan!

#include <MFRC522v2.h>
#include <MFRC522DriverSPI.h>
//#include <MFRC522DriverI2C.h>
#include <MFRC522DriverPinSimple.h>
#include <MFRC522Debug.h>

// Learn more about using SPI/I2C or check the pin assigment for your board: https://github.com/OSSLibraries/Arduino_MFRC522v2#pin-layout
MFRC522DriverPinSimple ss_pin(5);

MFRC522DriverSPI driver{ss_pin}; // Create SPI driver
//MFRC522DriverI2C driver{};     // Create I2C driver
MFRC522 mfrc522{driver};         // Create MFRC522 instance

void setup() {
  Serial.begin(115200);  // Initialize serial communication
  while (!Serial);       // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4).
  
  mfrc522.PCD_Init();    // Init MFRC522 board.
  MFRC522Debug::PCD_DumpVersionToSerial(mfrc522, Serial);	// Show details of PCD - MFRC522 Card Reader details.
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop() {
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards.
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Dump debug info about the card; PICC_HaltA() is automatically called.
  //MFRC522Debug::PICC_DumpToSerial(mfrc522, Serial, &(mfrc522.uid));
  //delay(2000);

  
  Serial.print("Card UID: ");
  MFRC522Debug::PrintUID(Serial, (mfrc522.uid));
  Serial.println();

  // Save the UID on a String variable
  String uidString = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) {
      uidString += "0"; 
    }
    uidString += String(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println(uidString);

  delay(2000);
}