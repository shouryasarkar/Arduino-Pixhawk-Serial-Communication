#include<SoftwareSerial.h>  //It is going to include the serial library for connection

#define RX_PIN 0  //This arduino digital pin is for receiving (connected to PixHawk Transmitter)
#define TX_PIN 1  //This arduino digital pin is for transmitting (connected to PixHawk Receiver)
#define BAUD_RATE 9600 

SoftwareSerial serial(RX_PIN, TX_PIN);

void setup(){ 
  serial.begin(BAUD_RATE); //Going to start the SoftwareSerial object
}

//here the message is a pointer to a constant character which cannot be changed
void transmitterArduino(const char* message){
  serial.println(message); //This is going to send the message to the PixHawk
}

void receiverArduino(){
  //Going to check when the connection is available with the PixHawk or not 
  while(serial.available() == 0){}
    String rec_character = serial.readString();  //It is going to read the received message from the PixHawk and store in a variable 
   // Serial.println(rec_character);  //Going to print the message received from the PixHawk on the serial monitor 
    if (rec_character.indexOf("Hi")>0){
      serial.println("Bye");
    }
}

void loop(){
  transmitterArduino("Hello"); //Goint to send a text message to PixHwk
  receiverArduino();  //Going to receive and print the text from the PixHawk 
  delay(1000); //Going to delay for 1sec before sending the next text 
}