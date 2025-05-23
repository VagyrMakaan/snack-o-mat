#define LED 2
#define LED_GREEN 4
#define BUZZER 16
#define BUTTON_GREEN 27

int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  pinMode(BUTTON_GREEN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  delay(1000);
  digitalWrite(LED, LOW);
  digitalWrite(LED_GREEN, LOW);
  delay(1000);
  digitalWrite(LED, HIGH);
  digitalWrite(LED_GREEN, HIGH);

  //buttonState = digitalRead(BUTTON_GREEN);
  //Serial.println(buttonState);
  //if (buttonState == HIGH)
  //{
  //  digitalWrite(LED_GREEN, HIGH);
  //} 
  //else
  //{
  //  digitalWrite(LED_GREEN, LOW);
  //}

  //delay(3000);
  //digitalWrite(LED,LOW);
  //digitalWrite(LED_GREEN, LOW);
  //digitalWrite(BUZZER, LOW);
  //delay(3000);
  //digitalWrite(LED,HIGH);
  //digitalWrite(LED_GREEN, HIGH);
  //digitalWrite(BUZZER, HIGH);
}



 