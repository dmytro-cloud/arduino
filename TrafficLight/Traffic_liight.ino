/*
 * A traffic light implementation. Changes green to red on car traffic light
 * after the button was pressed by a pedastrian. Switches pedastrian light to green.
 */
const int BUTTON = 13;
const int RED_PED = 8;
const int GREEN_PED = 9;
const int GREEN_CAR = 10;
const int YELLOW_CAR = 11;
const int RED_CAR = 12;

// the setup function runs once when you press reset or power the board
void setup() {
  for (int i = 8; i < 13; ++i) {
    pinMode(i, OUTPUT);
  }
  pinMode(BUTTON, INPUT);

  // Make car light green
  digitalWrite(GREEN_CAR, HIGH);
  digitalWrite(RED_PED, HIGH);
}

void letThemGo() {
    if (digitalRead(BUTTON) == HIGH) {
      delay(3000);
      digitalWrite(GREEN_CAR, LOW);
      delay(100);
      digitalWrite(YELLOW_CAR, HIGH);
      delay(1500);
      digitalWrite(YELLOW_CAR, LOW);
      delay(100);
      digitalWrite(RED_CAR, HIGH);
      delay(1000);
      digitalWrite(RED_PED, LOW);
      digitalWrite(GREEN_PED, HIGH);
      delay(5000);
      digitalWrite(GREEN_PED, LOW);
      for (int i = 0; i < 5; ++i) {
        digitalWrite(RED_PED, LOW);
        delay(500);
        digitalWrite(RED_PED, HIGH);
        delay(500);
      }
      digitalWrite(RED_PED, HIGH);
      delay(1000);
      digitalWrite(RED_CAR, LOW);
      digitalWrite(GREEN_CAR, HIGH);
    }
}

// the loop function runs over and over again forever
void loop() {
  letThemGo();
}
