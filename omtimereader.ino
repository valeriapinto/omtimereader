
// digital pin 2 has a pushbutton attached to it. Give it a name:
int pushButton = 9; // yellow wire
int redPin = 4; // red wire
int buzzPin = 8; // orange wire
int StartTime = 0;
int CurrentTime = 0;
int totalLapse = 0;

//notes: all positive wires are red unlike noted otherwise above
// all negative wires (ground) are black

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
  pinMode(redPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  int StartTime = 0;
  int CurrentTime = 0;
  int totalLapse = 0;
  // read the input pin:
  int buttonState = digitalRead(pushButton);

  // print out the state of the button: either 0 (pressed switch) or 1 (unpressed switch):
  Serial.println(buttonState);

  // when switch is pressed (= 0), initiate the original/start time and turn red LED light on to indicate that its "recording" the time
  if (buttonState == 0) {
    digitalWrite(redPin, HIGH);
    StartTime = millis();
  }

  // one the switch is unpressed (= 1), mark the current time and calculate the current time minus the start time to create the total lapse time int
  if (buttonState == 1) {
    digitalWrite(redPin, LOW);
    CurrentTime = millis();
    totalLapse = CurrentTime - StartTime;

    // if timelapse is less than 6 seconds (6000 millis), show  red LED light for timeplase amount of milliseconds
    if (totalLapse < 6000) {
      delay(1000);
      digitalWrite(redPin, HIGH);
      delay (totalLapse);

    } else {
      // else, turn buzzer on for the time lapse
      delay(1000);
      digitalWrite(redPin, LOW);
      tone(buzzPin , 3000, totalLapse);
      delay (totalLapse);

    }
  }
}


//    Serial.println (totalLapse);

