int leftspeed = 2; // Needs to be a PWM pin to be able to control motor speed
int leftoutput1 = 3;
int leftoutput2 = 4;

// Motor 2
int rightoutput1 = 5;
int rightoutput2 = 6;
int rightspeed = 7; // Needs to be a PWM pin to be able to control motor speed

void setup() {  // Setup runs once per reset
// initialize serial communication @ 9600 baud:
Serial.begin(9600);

//Define L298N Dual H-Bridge Motor Controller Pins

pinMode(leftoutput1,OUTPUT);
pinMode(leftoutput2,OUTPUT);
pinMode(leftspeed,OUTPUT);
pinMode(rightoutput1,OUTPUT);
pinMode(rightoutput2,OUTPUT);
pinMode(rightspeed,OUTPUT);

}

void loop() {

// Initialize the Serial interface:

if (Serial.available() > 0) {
char data = Serial.read();
//int speed; // Local variable

if (data=='2') {


//case '2': // Forward
analogWrite(leftspeed, 255);//Sets speed variable via PWM 
digitalWrite(leftoutput1, LOW);
digitalWrite(leftoutput2, HIGH);
analogWrite(rightspeed, 255);
digitalWrite(rightoutput1, LOW);
digitalWrite(rightoutput2, HIGH);
Serial.println("Motor 1 Forward"); // Prints out “Motor 1 Forward” on the serial monitor
//break;
}
else if (data=='0') {

//case '0': // stop
analogWrite(leftspeed, 0);
digitalWrite(leftoutput1, LOW);
digitalWrite(leftoutput2, HIGH);
analogWrite(rightspeed, 0);
digitalWrite(rightoutput1, LOW);
digitalWrite(rightoutput2, HIGH);
Serial.println("Motor 1 Stop");
//break;
}
else if (data=='1') {
//case '1': // Reverse
analogWrite(leftspeed, 255);
digitalWrite(leftoutput1, HIGH);
digitalWrite(leftoutput2, LOW);
analogWrite(rightspeed, 255);
digitalWrite(rightoutput1, HIGH);
digitalWrite(rightoutput2, LOW);
Serial.println("Motor 1 Reverse");
//break;
}
else if (data=='3') {
//left
  analogWrite(leftspeed, 255);//Sets speed variable via PWM 
digitalWrite(leftoutput1, LOW);
digitalWrite(leftoutput2, HIGH);
analogWrite(rightspeed, 0);
digitalWrite(rightoutput1, HIGH);
digitalWrite(rightoutput2, LOW);
Serial.println("Motor 1 left");
//break;
}

else if (data=='4') {
//case '4': // Right
analogWrite(leftspeed, 0);
digitalWrite(leftoutput1, HIGH);
digitalWrite(leftoutput2, LOW);
analogWrite(rightspeed, 255);
digitalWrite(rightoutput1, LOW);
digitalWrite(rightoutput2, HIGH);
Serial.println("Motor 1 Right");
//break;
}    }
      }
