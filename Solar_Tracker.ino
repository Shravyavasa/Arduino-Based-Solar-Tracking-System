#include <Servo.h>

// Pin definitions
#define LDR_LEFT A0
#define LDR_RIGHT A1
#define SERVO_PIN 11

// Constants
#define ERROR_MARGIN 10
#define STEP_SIZE 1
#define DELAY_MS 100

// Variables
int servoPosition = 90; // Start from center
Servo solarServo;

void setup()
{
    solarServo.attach(SERVO_PIN);
    solarServo.write(servoPosition);
    delay(1000);
}

void loop()
{
    int ldrLeft = analogRead(LDR_LEFT);
    int ldrRight = analogRead(LDR_RIGHT);

    int difference = abs(ldrLeft - ldrRight);

    if (difference > ERROR_MARGIN)
    {
        if (ldrLeft > ldrRight)
        {
            servoPosition -= STEP_SIZE;
        }
        else
        {
            servoPosition += STEP_SIZE;
        }

        // Limit servo range between 0 and 180
        servoPosition = constrain(servoPosition, 0, 180);
        solarServo.write(servoPosition);
    }

    delay(DELAY_MS);
}