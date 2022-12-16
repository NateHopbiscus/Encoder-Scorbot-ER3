/*

*/


#include <Encoder.h>
#include <Keypad.h>

#define MOTORSELECT 0
#define DIRECTION 1
#define HUNDREDS 2
#define TENS 3
#define ONES 4
#define EXECUTE 5

#define BASE 10
#define LOWERARM 11
#define UPPERARM 12
#define WRISTONE 13
#define WRISTTWO 14
#define HAND 15

int eVal1;
int eVal2;

int Motor1a = 14;
int Motor1b = 15;
int Motor2a = 4;
int Motor2b = 5;
int Motor3a = 6;
int Motor3b = 7;
int Motor4a = 8;
int Motor4b = 9;
int Motor5a = 10;
int Motor5b = 11;

const byte ROWS = 4;
const byte COLS = 4;
int x;

char hexaKeys[COLS][ROWS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'0', 'F', 'E', 'D'}
};

byte colPins[COLS] = {37, 36, 35, 34};
byte rowPins[ROWS] = {33, 32, 31, 30};

int currentCount = 0;
int previousCount = 0;

int dVal;
int hVal;
int tVal;
int oVal;

int motorvar1;
int motorvar2;

int playedMessage = 0;

int selection = 0;

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
int g;

  

int motor;

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(3, 38);
long newPosition = myEnc.read();
//   avoid using pins with LEDs attached

void setup() {
  Serial.begin(9600);

  pinMode(Motor1a, OUTPUT);
  pinMode(Motor1b, OUTPUT);
  pinMode(Motor2a, OUTPUT);
  pinMode(Motor2b, OUTPUT);
  pinMode(Motor3a, OUTPUT);
  pinMode(Motor3b, OUTPUT);
  pinMode(Motor4a, OUTPUT);
  pinMode(Motor4b, OUTPUT);
  pinMode(Motor5a, OUTPUT);
  pinMode(Motor5b, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  // Serial.println("Basic Encoder Test:");
}

long oldPosition  = -999;

void loop() {
  char customKey = customKeypad.getKey();
  g = customKey;
  int key = map(g, 48, 70, 0, 22);

  switch (selection) {


    case MOTORSELECT:
      if (playedMessage == 0) {
        Serial.println("===================");
        Serial.println("BEGIN SELECTION.");
        Serial.println("===================");
        Serial.println("        ");
        Serial.println("SELECTION PHASE: MOTOR.");
        playedMessage = 1;
      }
      if (key == 17) {
        motor = BASE;
        motorvar1 = 14;
        motorvar2 = 15;
        eVal1 = 3;
        eVal2 = 38;

        Serial.println("===================");
        Serial.println("MOTOR SELECTED: BASE.");
        Serial.println("===================");

        playedMessage = 0;
        selection = 1;
      }
      if (key == 18) {
        motor = LOWERARM;
        motorvar1 = 4;
        motorvar2 = 5;
        eVal1 = 2;
        eVal2 = 39;

        Serial.println("===================");
        Serial.println("MOTOR SELECTED: LOWER ARM.");
        Serial.println("===================");

        playedMessage = 0;
        selection = 1;
      }
      if (key == 19) {
        motor = UPPERARM;
        motorvar1 = 6;
        motorvar2 = 7;
        eVal1 = 21;
        eVal2 = 40;

        Serial.println("===================");
        Serial.println("MOTOR SELECTED: UPPER ARM.");
        Serial.println("===================");

        playedMessage = 0;
        selection = 1;
      }
      if (key == 20) {
        motor = WRISTONE;
        motorvar1 = 8;
        motorvar2 = 9;
        eVal1 = 20;
        eVal2 = 41;

        Serial.println("===================");
        Serial.println("MOTOR SELECTED: WRIST ONE.");
        Serial.println("===================");

        playedMessage = 0;
        selection = 1;
      }
      if (key == 21) {
        motor = WRISTTWO;
        motorvar1 = 10;
        motorvar2 = 11;
        eVal1 = 19;
        eVal2 = 42;

        Serial.println("===================");
        Serial.println("MOTOR SELECTED: WRIST TWO.");
        Serial.println("===================");

        playedMessage = 0;
        selection = 1;
      }
      if (key == 22) {
        motor = HAND;
        motorvar1 = 12;
        motorvar2 = 13;
        eVal1 = 18;
        eVal2 = 43;

        Serial.println("===================");
        Serial.println("MOTOR SELECTED: HAND.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 1;
      }


      break;

    case DIRECTION:
      if (playedMessage == 0) {
        Serial.println("SELECTION PHASE: DIRECTION.");
        playedMessage = 1;
      }
      if (key == 0) {
        dVal = 1;
        Serial.println("===================");
        Serial.println("DIRECTION SELECTED: FORWARD.");
        Serial.println("===================");

        playedMessage = 0;
        selection = 2;

      }
      if (key == 1) {
        dVal = -1;
        Serial.println("===================");
        Serial.println("DIRECTION SELECTED: REVERSE.");
        Serial.println("===================");

        playedMessage = 0;
        selection = 2;

      }

      break;

    case HUNDREDS:
      if (playedMessage == 0) {
        Serial.println("SELECTION PHASE: HUNDREDS PLACE.");
        playedMessage = 1;
      }
      if (key == 0) {
        hVal = 0;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 0.");
        Serial.println("===================");

        playedMessage = 0;
        selection = 3;
      }
      if (key == 1) {
        hVal = 100;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 100.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 3;
      }
      if (key == 2) {
        hVal = 200;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 200.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 3;
      }
      if (key == 3) {
        hVal = 300;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 300.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 3;
      }
      if (key == 4) {
        hVal = 400;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 400.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 3;
      }
      if (key == 5) {
        hVal = 500;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 500.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 3;
      }
      if (key == 6) {
        hVal = 600;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 600.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 3;
      }
      if (key == 7) {
        hVal = 700;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 700.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 3;
      }
      if (key == 8) {
        hVal = 800;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 800.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 3;

      }
      if (key == 9) {
        hVal = 900;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 900.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 3;

      }

      break;

    case TENS:

      if (playedMessage == 0) {
        Serial.println("SELECTION PHASE: TENS PLACE.");
        playedMessage = 1;
      }
      if (key == 0) {
        tVal = 0;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 0.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 4;

      }
      if (key == 1) {
        tVal = 10;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 10.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 4;

      }
      if (key == 2) {
        tVal = 20;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 20.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 4;

      }
      if (key == 3) {
        tVal = 30;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 30.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 4;

      }
      if (key == 4) {
        tVal = 40;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 40.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 4;

      }
      if (key == 5) {
        tVal = 50;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 50.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 4;

      }
      if (key == 6) {
        tVal = 60;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 60.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 4;

      }
      if (key == 7) {
        tVal = 70;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 70.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 4;

      }
      if (key == 8) {
        tVal = 80;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 80.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 4;

      }
      if (key == 9) {
        tVal = 90;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 90.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 4;
      }

      break;

    case ONES:
      if (playedMessage == 0) {
        Serial.println("SELECTION PHASE: ONES PLACE.");
        playedMessage = 1;
      }
      if (key == 0) {
        oVal = 0;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 0.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 5;

      }
      if (key == 1) {
        oVal = 1;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 1.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 5;

      }
      if (key == 2) {
        oVal = 2;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 2.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 5;

      }
      if (key == 3) {
        oVal = 3;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 3.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 5;

      }
      if (key == 4) {
        oVal = 4;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 4.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 5;
      }
      if (key == 5) {
        oVal = 5;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 5.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 5;
      }
      if (key == 6) {
        oVal = 6;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 6.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 5;
      }
      if (key == 7) {
        oVal = 7;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 7.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 5;
      }
      if (key == 8) {
        oVal = 8;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 8.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 5;
      }
      if (key == 9) {
        oVal = 9;
        Serial.println("===================");
        Serial.println("VALUE SELECTED: 9.");
        Serial.println("===================");
        playedMessage = 0;
        selection = 5;
      }

      break;

    case EXECUTE:
      Serial.println("SELECTION PHASE: CONCLUDED.");
      Serial.println("COMMAND EXECUTING...");
      previousCount = currentCount;
      currentCount = currentCount + (hVal + tVal + oVal) * dVal;
      if (currentCount < previousCount) {
        Serial.println("space");
        for (currentCount; newPosition > currentCount; newPosition) {
          newPosition = myEnc.read();
          digitalWrite(motorvar1, HIGH);
          digitalWrite(motorvar2, LOW);
           newPosition = myEnc.read();
          Serial.println("===================");
          Serial.print("Encoder Count: ");
          Serial.println(newPosition);
          Serial.print("Current Count: ");
          Serial.println(currentCount);
          newPosition = myEnc.read();
        }
      }
      if (currentCount > previousCount) {
        Serial.println("time");
        for (currentCount; newPosition < currentCount; newPosition) {
          newPosition = myEnc.read();
          digitalWrite(motorvar1, LOW);
          digitalWrite(motorvar2, HIGH);
           newPosition = myEnc.read();
          Serial.println("===================");
          Serial.print("Encoder Count: ");
          Serial.println(newPosition);
          Serial.print("Current Count: ");
          Serial.println(currentCount);
          newPosition = myEnc.read();
        }
      }
      if (newPosition != oldPosition) {
        oldPosition = newPosition;
      }
      digitalWrite(motorvar1, LOW);
      digitalWrite(motorvar2, LOW);
      Serial.println("COMMAND EXECUTED.");
      Serial.println("===================");
      Serial.print("Current Value: ");
      Serial.println(currentCount);
      Serial.print("Previous Value: ");
      Serial.println(previousCount);
      Serial.println("===================");
      Serial.print("Encoder Count: ");
      Serial.println(newPosition);
      selection = 0;
      break;
  }



}
