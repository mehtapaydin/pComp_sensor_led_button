int potVal = 0;
int potPin = A0;

int led1Pin = 9;
int led2Pin = 10;
int led3Pin = 11;
int ledVal = 0;

int buttonPin = 5;

int state = 0;
unsigned long lastBlinkTime = 0;



void setup() {

  Serial.begin(9600);
  pinMode (buttonPin, INPUT_PULLUP);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);

}

void loop() {

    int oldButtonVal = digitalRead(buttonPin);
    delay(100);
    int newButtonVal = digitalRead(buttonPin);

  if (oldButtonVal != newButtonVal) {

      if (newButtonVal == LOW) {
       state++;
      }
  }
  
  if (state == 0) {
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
  }

  if (state == 1) {
     digitalWrite(led1Pin, HIGH);
     digitalWrite(led2Pin, HIGH);
     digitalWrite(led3Pin, HIGH);
  }

  if (state == 2) {
  
      int blinkWaitTime = 1023 - analogRead (potPin);
    
      if (millis() - lastBlinkTime >= blinkWaitTime) {
        digitalWrite(led1Pin, HIGH);
        digitalWrite(led2Pin, HIGH);
        digitalWrite(led3Pin, HIGH);
        lastBlinkTime = millis();
        
    } else {
        digitalWrite(led1Pin, LOW);
        digitalWrite(led2Pin, LOW);
        digitalWrite(led3Pin, LOW);
     }

  } 

  if (state == 3) {
      potVal = analogRead(potPin);
      ledVal = map(potVal, 0, 1023, 0, 255);
      analogWrite(led1Pin, ledVal);
      analogWrite(led2Pin, ledVal);
      analogWrite(led3Pin, ledVal);
  }

    if (state == 4) {
       potVal= analogRead(potPin);
       if ( potVal>=0 && potVal < 341){
        digitalWrite(led1Pin, HIGH);
        digitalWrite(led2Pin, LOW);
        digitalWrite(led3Pin, LOW);
       }
       if ( potVal>=341 && potVal < 682){
        digitalWrite(led1Pin, LOW);
        digitalWrite(led2Pin, HIGH);
        digitalWrite(led3Pin, LOW);
       }
       if ( potVal>=682 && potVal < 1024){
        digitalWrite(led1Pin, LOW);
        digitalWrite(led2Pin, LOW);
        digitalWrite(led3Pin, HIGH);
       }
  }
  
  if (state >=5) {
    state = 0;
  }
 
}







