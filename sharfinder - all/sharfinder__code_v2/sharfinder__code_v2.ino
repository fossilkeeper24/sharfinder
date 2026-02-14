int BUT1 = D3;
int BUT2 = D4;
int BUT3 = D5;

int LED1 = D0;  // can't quite use these because i messed up somewhere in maybe the soldering
int LED2 = D1;
int LED3 = D2;

long but1time;  // i want to use these elsewhere for minigameee. give 1-20 ms buffer
long but2time;
long but3time;

int pattern1[3] = { 1, 2, 3 };
int pattern1_size = 3;
int pattern2[5] = { 3, 3, 2, 1, 2 };
int pattern2_size = 5;
int wee[10];


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

  pinMode(LED_BUILTIN, OUTPUT);  //desperately testing

  //digitalWrite(LED1, LOW); //desperately testing
  //delay(100);
  //digitalWrite(LED1, HIGH);
  //delay(100);

  long startTime = millis();
}

void loop() {  // input array

  game(pattern1, pattern1_size);
  game(pattern2, pattern2_size);
}

void game(int *pattern, int pattern_size){
  while (true) {
    for (int i = 0; i < pattern_size; i++) {
      Serial.print(pattern[i]);
    }

    Serial.println();

    for (int j = 0; j < pattern_size; j++) {
      wee[j] = get_button();
      delay(300);  // this should be the amount of time it takes to press and release a key
    }
    bool same = is_same(pattern, pattern_size, wee);
    //Serial.println(same);
    if (same == 1) {
      Serial.println("yayyy!! :D");
      for (int j = 0; j <= pattern_size; j++) {
        wee[j] = 0;
      }
      break;
    } else {
      Serial.print("try again :(");
    }
    Serial.println();
  }
}
// func to check if pattern is same as inputs, pass pattern and inputs as parameters
// for i in range 0, len(pattern)-1 check index is same
// return true of false then reset input array

bool is_same(int *pattern, int pattern_size, int *play) {
  for (int i = 0; i < pattern_size; i++) {
    //Serial.print("what i got:");
    //Serial.println(play[i]);
    //Serial.print("checking against:");
    //Serial.println(pattern[i]);
    if (play[i] != pattern[i]) { return false; }
  }
  return true;
}

int get_button() {
  while (true) {
    int status1 = digitalRead(BUT1);
    if (status1 == 0) { return 1; }
    int status2 = digitalRead(BUT2);
    if (status2 == 0) { return 2; }
    int status3 = digitalRead(BUT3);
    if (status3 == 0) { return 3; }
  }
}

void test() {
  but2time = 0;
  but3time = 50;  // reset
  int status1 = digitalRead(BUT1);
  if (status1 == 0) { but1time = millis(); }
  int status2 = digitalRead(BUT2);
  if (status2 == 0) { but2time = millis(); }
  int status3 = digitalRead(BUT3);
  if (status3 == 0) { but3time = millis(); }
  // 1 means not pressed, 0 means pressed

  Serial.println("button1:");
  Serial.println(status1);
  Serial.println("button2:");
  Serial.println(status2);
  Serial.println("button3:");
  Serial.println(status3);
  delay(400);

  //Serial.println(but3time - but2time);
  //Serial.println(but2time - but1time);
  //Serial.println();

  if (abs(but3time - but2time) <= 20) {
    if (abs(but2time - but1time) <= 20) {
      Serial.println("All three pressed simultaneously!");
      //initialiseGame();
    }
  }
}

// memory gameee whackamole style - in the foreseeable future


void flash_userled() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
