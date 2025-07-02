// memory gameee whackamole style

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

