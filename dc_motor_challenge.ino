// Motor A connections
int en1_2 = 9;
int a_1 = 8;
int a_2 = 7;

void setup() {
  // Set all the motor control pins to outputs
  pinMode(en1_2, OUTPUT);
  pinMode(a_1, OUTPUT);
  pinMode(a_2, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(en1_2, HIGH);
  digitalWrite(a_1, LOW);
  digitalWrite(a_2, LOW);
}

void loop() {
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(en1_2, 255);

  // Turn motor on
  digitalWrite(a_1, HIGH);
  digitalWrite(a_2, LOW);
  delay(2000);
  // Fast stop
  digitalWrite(a_1, LOW);
  digitalWrite(a_2, LOW);
  delay(100);
  
  // Change motor direction
  digitalWrite(a_1, LOW);
  digitalWrite(a_2, HIGH);
  delay(2000);
  // Fast stop
  digitalWrite(a_1, HIGH);
  digitalWrite(a_2, HIGH);
  delay(100);
  
  // Accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++) {
    analogWrite(en1_2, i);
    delay(20);
  }

  //free motor stop
  analogWrite(en1_2, 0);
  
  

}
