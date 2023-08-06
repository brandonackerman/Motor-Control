// Motor Control
// Brandon Ackerman, RBT173

// GLOBAL VARIABLES
// Motor Control

// define pins used for right motor control
int rightEn = 3;
int forRight = 4;
int revRight = 5;

// define pins used for left Motor Control
int leftEn = 6;
int forLeft = 7;
int revLeft = 8;

////////////////////////////////////////

// Setup Code
void setup()
{

    // enable right motor pins as output
    pinMode(rightEn, OUTPUT);
    pinMode(forRight, OUTPUT);
    pinMode(revRight, OUTPUT);

    // enable left motor pins as output
    pinMode(leftEn, OUTPUT);
    pinMode(forLeft, OUTPUT);
    pinMode(revLeft, OUTPUT);
}

// Main Code
void loop()
{

    // function commands for driving the motors

    // Set motor speed to maximum
    analogWrite(rightEn, 255); // enable right motor
    analogWrite(leftEn, 255);  // enable left motor

    // Drive
    forward();   // drive forward
    delay(1000); // Wait for 1000 millisecond(s)

    reverse();   // drive backwards
    delay(1000); // Wait for 1000 millisecond(s)

    // Reduce motor speed to half
    analogWrite(rightEn, 128);
    analogWrite(leftEn, 128);

    forward();   // drive forward
    delay(1000); // Wait for 1000 millisecond(s)

    rightTurn(); // turn right
    delay(1000); // Wait for 1000 millisecond(s)

    forward();   // drive forward
    delay(1000); // Wait for 1000 millisecond(s)

    leftTurn();  // turn left
    delay(1000); // Wait for 1000 millisecond(s)

    reverse();   // drive backwards
    delay(1000); // Wait for 1000 millisecond(s)

    // Increase motor speed to 100%
    analogWrite(rightEn, 255);
    analogWrite(leftEn, 255);

    leftSpin();  // spin left
    delay(1000); // Wait for 1000 millisecond(s)

    reverse();   // drive backwards
    delay(1000); // Wait for 1000 millisecond(s)

    rightSpin()      // spin right
        delay(1000); // Wait for 1000 millisecond(s)
}

// SUB-FUNCTIONS
//
// Right Motor Forward
void rightFor()
{
    digitalWrite(revRight, LOW);
    digitalWrite(forRight, HIGH);
}

// Right Motor Reverse
void rightRev()
{
    digitalWrite(revRight, HIGH);
    digitalWrite(forRight, LOW);
}

// Left Motor Forward
void leftFor()
{
    digitalWrite(revLeft, LOW);
    digitalWrite(forLeft, HIGH);
}

// Left Motor Reverse
void leftRev()
{
    digitalWrite(revLeft, HIGH);
    digitalWrite(forLeft, LOW);
}

// MAIN FUNCTIONS
//
//  Drive Forward
void forward()
{
    rightFor();
    leftFor();
}

// Drive Backwards
void reverse()
{
    rightRev();
    leftRev();
}

// Turn Right
void rightTurn()
{
    // rightRev();
    leftFor();
}

// Turn Left
void leftTurn()
{
    rightFor();
    // leftRev();
}

// Spin Left
void leftSpin()
{
    rightFor();
    leftRev();
}

// Spin Right
void rightSpin()
{
    leftFor();
    rightRev();
}