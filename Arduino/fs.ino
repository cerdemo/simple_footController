/*
Cagri Erdem, 2020
RITMO, University of Oslo
 */

//pin numbers
int expPedal = A0; //expression pedal analog in

const int fSwitch1 = 2; //foot switches' digital ins
const int fSwitch2 = 3;
const int fSwitch3 = 4;
const int fSwitch4 = 5;
const int fSwitch5 = 6;

const int ledPin1 = 7; //foot switches' led outs
const int ledPin2 = 8;
const int ledPin3 = 9;
const int ledPin4 = 10;
const int ledPin5 = 11;

//global variables for switches' (past and current) states
int fsState1 = 0;
int pre_fsState1 = 0;
int fsState2 = 0;
int pre_fsState2 = 0;
int fsState3 = 0;
int pre_fsState3 = 0;
int fsState4 = 0;
int pre_fsState4 = 0;
int fsState5 = 0;
int pre_fsState5 = 0;
int expState = 0;
int pre_expState = 0;

/**********************************/

void setup()
{
  Serial.begin(9600);
  pinMode(fSwitch1, INPUT);
  pinMode(fSwitch2, INPUT);
  pinMode(fSwitch3, INPUT);
  pinMode(fSwitch4, INPUT);
  pinMode(fSwitch5, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
}

/**********************************/

void loop() {

  fsState1 = digitalRead(fSwitch1);
  if (fsState1 != pre_fsState1) {
    if (fsState1 == HIGH) {
      digitalWrite(ledPin1, LOW);
      Serial.print("Fs1: ");
      Serial.println("0");
      pre_fsState1 = fsState1;
    } else {
      Serial.print("Fs1: ");
      Serial.println("1");
      digitalWrite(ledPin1, HIGH);
      pre_fsState1 = fsState1;
    }
    delay(20);
  }


  fsState2 = digitalRead(fSwitch2);
  if (fsState2 != pre_fsState2) {
    if (fsState2 == HIGH) {
      digitalWrite(ledPin2, LOW);
      Serial.print("Fs2: ");
      Serial.println("0");
      pre_fsState2 = fsState2;
    } else {
      Serial.print("Fs2: ");
      Serial.println("1");
      digitalWrite(ledPin2, HIGH);
      pre_fsState2 = fsState2;
    }
    delay(20);
  }


  fsState3 = digitalRead(fSwitch3);
  if (fsState3 != pre_fsState3) {
    if (fsState3 == HIGH) {
      digitalWrite(ledPin3, LOW);
      Serial.print("Fs3: ");
      Serial.println("0");
      pre_fsState3 = fsState3;
    } else {
      Serial.print("Fs3: ");
      Serial.println("1");
      digitalWrite(ledPin3, HIGH);
      pre_fsState3 = fsState3;
    }
    delay(20);
  }


  fsState4 = digitalRead(fSwitch4);
  if (fsState4 != pre_fsState4) {
    if (fsState4 == HIGH) {
      digitalWrite(ledPin4, LOW);
      Serial.print("Fs4: ");
      Serial.println("0");
      pre_fsState4 = fsState4;
    } else {
      Serial.print("Fs4: ");
      Serial.println("1");
      digitalWrite(ledPin4, HIGH);
      pre_fsState4 = fsState4;
    }
    delay(20);
  }


  fsState5 = digitalRead(fSwitch5);
  if (fsState5 != pre_fsState5) {
    if (fsState5 == HIGH) {
      digitalWrite(ledPin5, LOW);
      Serial.print("Fs5: ");
      Serial.println("0");
      pre_fsState5 = fsState5;
    } else {
      Serial.print("Fs5: ");
      Serial.println("1");
      digitalWrite(ledPin5, HIGH);
      delay(40);
      pre_fsState5 = fsState5;
    }
  }


  expState = analogRead(expPedal);
  int expression = map(expState, 0, 900, 0, 255);
  expression = constrain(expression, 0, 255);
  if (expState != pre_expState) {
    Serial.print("Expression: ");
    Serial.println(expression);
    pre_expState = expState;
  }
  delay(20);
}