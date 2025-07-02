int BUT1 = D4;
int BUT2 = D5;
int BUT3 = D6;

int LED1 = D1;
int LED2 = D2;
int LED3 = D3;


void setup() {
  // put your setup code here, to run once:
  pinMode(BUT1, INPUT);
  pinMode(BUT2, INPUT);
  pinMode(BUT3, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  long startTime = millis();


}

void loop() {
  // put your main code here, to run repeatedly:
  long but1time;
  long but2time;
  long but3time;
  
  if (digitalRead(BUT1) == HIGH) {
    but1time = millisec();
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }

  if (digitalRead(BUT2) == HIGH) {
    but2time = millisec();
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }

  if (digitalRead(BUT3) == HIGH) {
    digitalWrite(LED3, HIGH);
    but3time++;
  } else {
    digitalWrite(LED3, LOW);
  }

}
