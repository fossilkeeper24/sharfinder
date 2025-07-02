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