#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          
#define SS_PIN          10         

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
int cardCount = 0;                 // Counter variable for card reads

void setup() {
	Serial.begin(9600);		// Initialize serial communications with the PC
	while (!Serial);		// Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
	SPI.begin();			// Init SPI bus
	mfrc522.PCD_Init();		// Init MFRC522
	delay(4);				// Optional delay. Some boards need more time after initialization, see Readme
	mfrc522.PCD_DumpVersionToSerial();	// Show details of PCD - MFRC522 Card Reader details

	Serial.println(F("Scan RFID card to start the counter..."));
}

void loop() {
	if (!mfrc522.PICC_IsNewCardPresent()) {
		return;
	}

	if (!mfrc522.PICC_ReadCardSerial()) {
		return;
	}

	cardCount++;  // Increment the card count

	// Print the RFID card ID and the card count
	String rfidCardID = "";
	for (byte i = 0; i < mfrc522.uid.size; i++) {
		rfidCardID += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
		rfidCardID += String(mfrc522.uid.uidByte[i], HEX);
	}
	Serial.print("RFID Card ID: " + rfidCardID);
	Serial.println(" - Card Count: " + String(cardCount));

	mfrc522.PICC_HaltA();
	mfrc522.PCD_StopCrypto1();
}
