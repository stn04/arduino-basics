
## About
Here you will find a bunch of simple, beginner Arduino projects useful for those trying to
work on their very first projects `(just like me!)`. All the code in this repository has been tested on the Arduino UNO and no
other hardware.

## Projects

### [readTemp](https://github.com/stn04/arduino-basics/blob/main/readTemp.ino)
This Arduino project monitors the temperature using an internal sensor and displays the average temperature on the serial 
monitor. It involves reading the temperature sensor and calculating the average temperature over multiple readings. 
The `readTemperature()` function reads the sensor value and converts it to temperature. 
The `averageTemperature()` function calculates the running average temperature. 

### [readAnalog](https://github.com/stn04/arduino-basics/blob/main/readAnalog.ino)
This Arduino project reads an analog input and displays its value in various formats on the serial monitor. 
The `loop()` function reads the analog input from pin 0 using `analogRead()` and prints the value in decimal,
hexadecimal, octal, and binary formats. The LED connected to pin 13 blinks briefly after each reading.

### [RFIDcardCounter](https://github.com/stn04/arduino-basics/blob/main/RFIDcountCard.ino)
This Arduino project reads RFID cards using the MFRC522 module and counts the number of card reads.
The setup() function initializes the serial communication with the PC,
initializes the SPI bus, and initializes the MFRC522 module. It also displays 
the details of the MFRC522 module on the serial monitor.
The loop() function continuously checks for the presence of a new RFID card. If a new card is detected,
its serial number is read, the card count is incremented, and the card's ID and count are printed on the serial monitor.
The card is then halted and encryption is stopped.
