#define LED 2
#define LED_GREEN 4
#define BUZZER 16

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  digitalWrite(LED,HIGH);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(BUZZER, HIGH);
  delay(500);
  digitalWrite(LED,LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(BUZZER, LOW);
}



 