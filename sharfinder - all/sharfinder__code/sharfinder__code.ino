int BUT1 = D3;
int BUT2 = D4;
int BUT3 = D5;

int LED1 = D0;
int LED2 = D1;
int LED3 = D2;

long but1time; // i want to use these elsewhere for minigameee
long but2time;
long but3time;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BUT1, INPUT_PULLUP);
  pinMode(BUT2, INPUT_PULLUP);
  pinMode(BUT3, INPUT_PULLUP);

//  pinMode(LED1, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT); //desperately testing

  digitalWrite(LED1, LOW); //desperately testing
  delay(100);
  digitalWrite(LED1, HIGH);
  delay(100);

  long startTime = millis();


}

void loop() {
  //flash_userled();
  int status1 = digitalRead(BUT1);
  int status2 = digitalRead(BUT2);
  int status3 = digitalRead(BUT3);

  Serial.println("button1:");
  Serial.println(status1);
  Serial.println("button2:");
  Serial.println(status2);
  Serial.println("button3:");
  Serial.println(status3);
  delay(400);



 //  secret();

  //if (but3time - but2time <= 1000){
    //if (but2time - but1time <= 1000){
      //initialiseGame();



    //}
  //}

}

void secret() {
  if (but1time >10000) {
    for (int runs = 0; runs <= 3; runs +=1){
      digitalWrite(LED1, HIGH);
      delay(500);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      delay(500);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      delay(500);
      digitalWrite(LED3, LOW);

    }

  }

}

// memory gameee whackamole style - in the foreseeable future

void initialiseGame() {
      for (int runs = 0; runs <= 3; runs+=1){
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        delay(1000);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
      }

    }

void testing() {
  digitalWrite(LED1, LOW);
  delay(1000);
  digitalWrite(LED1, HIGH);
  delay(1000);

  digitalWrite(LED2, LOW); //desperately testing
  delay(1000);
  digitalWrite(LED2, HIGH);
  delay(1000);

  digitalWrite(LED3, LOW); //desperately testing
  delay(1000);
  digitalWrite(LED3, HIGH);
  delay(1000);


}

void flash_userled() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second

}

void real() {
  if (digitalRead(BUT1) == LOW) {
    but1time = millis();
    digitalWrite(LED1, HIGH);
    Serial.println("But1 pressed");
  } else {
    digitalWrite(LED1, LOW);
  }

  if (digitalRead(BUT2) == LOW) {
    but2time = millis();
    digitalWrite(LED2, HIGH);
    Serial.println("But2 pressed");
  } else {
    digitalWrite(LED2, LOW);
  }

  if (digitalRead(BUT3) == LOW) {
    digitalWrite(LED3, HIGH);
    Serial.println("But3 pressed");
    but3time = millis();
  } else {
    digitalWrite(LED3, LOW);
    but3time = 0;
  }


}

