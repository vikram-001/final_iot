#include <SPI.h>
#include <MFRC522.h>
#include "SoftwareSerial.h"
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
SoftwareSerial ser(2,3); // RX, TX 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  ser.begin (115200);
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Put RFID Card to Scan...");
  Serial.println();
 
}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    Serial.println("Card not found");
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("User No./Name:    ");
  content.toUpperCase();
  if (content.substring(1) == "3C C1 A0 91" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("1-Vikram");
    ser.write(1);
    Serial.println();
    
    delay(3000);
  }
   if (content.substring(1) ==  "AC D6 99 91" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("2-Narasimha");
    ser.write(2);
    Serial.println();
    
    delay(3000);
  }
   if (content.substring(1) == "0C 7F A5 91" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("3-Satya");
    ser.write(3);
    Serial.println();
    
    delay(3000);
  }
   if (content.substring(1) == "5C 40 9C 91" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("4-Rakesh");
    ser.write(4);
    Serial.println();
    
    delay(3000);
  }
   if (content.substring(1) == "14 B1 5B 2B" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("5-user5");
    ser.write(5);
    Serial.println();
    
    delay(3000);
  }
    if (content.substring(1) ==  "9C 40 9E 91" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("6-user6");
    ser.write(6);
    Serial.println();
    
    delay(3000);
  }
      if (content.substring(1) ==  "F9 06 22 E5" ) //change here the UID of the card/cards that you want to give access
  {
    Serial.println("7-user7");
    ser.write(6);
    Serial.println();
    
    delay(3000);
  }
  }
