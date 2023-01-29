#include <Keypad.h>
#include <Servo.h>


const byte ROWS = 4;


 
const byte COLS = 4; 

int pos = 0;    // variable to store the servo motor 1 position

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {13, 12, 11, 10}; 
byte colPins[COLS] = {9, 8, 7, 6}; 
byte var;

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
Servo servo1;
Servo servo2;

void setup(){
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  pinMode(A0,OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  delay(1000);              
  digitalWrite(4, LOW);
  servo1.attach(2);
  servo1.write(170);
  servo2.attach(3);
  servo2.write(10);
}

void rightArmRotate(){
  for (pos = 0; pos <= 180; pos += 1) 
    { 
    servo1.write(180-pos); 
    delay(5);       
    }
    for (pos = 180; pos >= 0; pos -= 1)
    { 
    servo1.write(180-pos);
    delay(5);                       
    }
  }

void leftArmRotate(){
  for (pos = 0; pos <= 180; pos += 1) 
    { 
    servo2.write(pos); 
    delay(5);
    }
    for (pos = 180; pos >= 0; pos -= 1)
    { 
    servo2.write(pos);
    delay(5);
    }
  
}

void led_blink(){
  digitalWrite(A0, HIGH);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, HIGH);
  delay(1000);
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  delay(1000);
}

void buzzer_sound(){
  digitalWrite(A5, HIGH);
  delay(1000);
  digitalWrite(A5, LOW);
  delay(1000);
}

void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
  }
  if (customKey == '1')
  {
    var = 0;
      while (var < 2) {
    led_blink();
    var++;
  }   
   }
   if (customKey == '2')
  {
    var = 0;
      while (var < 2) {
    rightArmRotate();
    var++;
  }    
   }
   if (customKey == '3')
  {
    for (pos = 0; pos <= 180; pos += 1) 
    { 
    servo2.write(pos); 
    servo1.write(180-pos);
     delay(5);            
    }
    for (pos = 180; pos >= 0; pos -= 1)
    { 
    servo2.write(pos);
    servo1.write(180-pos); 
    delay(5);              
    }
   }
   if (customKey == '4')
  {
    var = 0;
      while (var < 4) {
   
   leftArmRotate();
    var++;
   }
   }
   if (customKey == '5')
  {
    var = 0;
      while (var < 5) {
    rightArmRotate();
    var++;
   }
  }
   if (customKey == '6')
  {
    for (pos = 0; pos <= 180; pos += 1) 
    { 
    servo1.write(180-pos); 
    delay(5);       
    }
    for (pos = 180; pos >= 0; pos -= 1)
    { 
    servo1.write(180-pos);
    delay(5);                       
    }
   }
   if (customKey == '7')
  {
    var = 0;
      while (var < 7) {
    leftArmRotate();
    var++;
   }
   }
   if (customKey == '8')
  {
    var = 0;
      while (var < 8) {
    rightArmRotate();
    var++;
   }
  }
   if (customKey == '9')
  {
    for (pos = 0; pos <= 180; pos += 1) 
    { 
    servo1.write(180-pos); 
    delay(5);       
    }
    for (pos = 180; pos >= 0; pos -= 1)
    { 
    servo1.write(180-pos);
    delay(5);                       
    }
   }
   if (customKey == '0')
  {
    for (pos = 0; pos <= 180; pos += 1) 
    { 
    servo1.write(180-pos); 
    delay(5);       
    }
    for (pos = 180; pos >= 0; pos -= 1)
    { 
    servo1.write(180-pos);
    delay(5);                       
    }
   }
   if (customKey == 'A')
  {
    var = 0;
      while (var < 2) {
    buzzer_sound();
    var++;
  }   
   }
   if (customKey == 'B')
  {
    rightArmRotate();
   }
   if (customKey == 'C')
  {
    leftArmRotate();
   }
   if (customKey == 'D')
  {
    rightArmRotate();
   }
}
