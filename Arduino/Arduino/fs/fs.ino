/*
  Cagri Erdem, 2020
  RITMO, University of Oslo
*/

//pin numbers
int expPedal = A0; //expression pedal analog in
const int fSwitch[] = {2, 3, 4, 5, 6}; //foot switches' digital ins
const int ledPin[] = {7, 8, 9, 10, 11}; //foot switches' led outs

//global variables for switches' (past and current) states
int fs_pre[] = {0, 0, 0, 0, 0};
int fs_now[] = {0, 0, 0, 0, 0};
int pre_expState, expState;
int togs[] = {0, 0, 0, 0};
String fs[] = {"Fs1: ", "Fs2: ", "Fs3: ", "Fs4: ", "Fs5: "};

/**********************************/

void setup()
{
  Serial.begin(9600);

  for (int i = 0; i < 5; i++) {
    pinMode(fSwitch[i], INPUT);
    pinMode(ledPin[i], OUTPUT);
  }

}

/**********************************/

void loop() {

  if (Serial.available()) {
    for (int t = 0; t < 4; t++) {
      togs[t] = Serial.read();
      if (togs[t] == 1) {
        digitalWrite(ledPin[t], HIGH);
      } else if (togs[t] == 0) {
        digitalWrite(ledPin[t], LOW);
      }
    }
    delay(1);
  }

  for (int i = 0; i < 5; i++) {
    fs_now[i] = digitalRead(fSwitch[i]);
    if (fs_now[i] != fs_pre[i]) {
      if (fs_now[i] == HIGH) {
        Serial.print(fs[i]);
        Serial.println("0");
        fs_pre[i] = fs_now[i];
      } else {
        Serial.print(fs[i]);
        Serial.println("1");
        fs_pre[i] = fs_now[i];
      }
      delay(20);
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
