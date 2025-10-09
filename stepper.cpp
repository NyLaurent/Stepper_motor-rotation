#include <Stepper.h>

// Number of steps per revolution for 28BYJ-48 stepper motor (with ULN2003 driver)
const int stepsPerRevolution = 2048;  

// Define ULN2003 input pins connected to Arduino
const int IN1 = 8;
const int IN2 = 9;
const int IN3 = 10;
const int IN4 = 11;

// Initialize the stepper with the above pins
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void setup() {
  myStepper.setSpeed(10); // RPM
  Serial.begin(9600);
  Serial.println("Stepper motor ready...");
  Serial.println("Enter angle (positive = clockwise, negative = counterclockwise):");
}

void loop() {
  if (Serial.available() > 0) {
    // Read the angle from Serial Monitor
    int angle = Serial.parseInt();  

    if (angle != 0) {
      // Convert angle to steps
      long stepsToMove = (long)angle * stepsPerRevolution / 360;

      Serial.print("Rotating ");
      Serial.print(angle);
      Serial.println(" degrees...");

      myStepper.step(stepsToMove);

      Serial.println("Done. Enter another angle:");
    }
  }
}
