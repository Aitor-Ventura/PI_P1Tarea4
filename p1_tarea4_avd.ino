/* Pulsadores. Programa que utiliza los pulsadores pright
 *  y pleft para rotar a la derecha o a la izquierda el
 *  parpadeo de un digito
 */
int num = 1;

void setup() {
  DDRA = B11111111;
  DDRC = B00000001;
  PORTC = B11111000;
  PORTA = 0x3F;
  // Activamos los pines
  pinMode(49, OUTPUT);
  pinMode(48, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(46, OUTPUT);
  // Encendidos inicialmente
  digitalWrite(49, HIGH);
  digitalWrite(48, HIGH);
  digitalWrite(47, HIGH);
  digitalWrite(46, HIGH);
  // Monitor serie
  Serial.begin(9600);
}

void loop() {
  // pright
  if (digitalRead(30)==0) {
    Serial.println("Derecho");
    delay(250);
    // Rotamos hacia la derecha (switch)
    if (num != 1) {
      num--;
      // Si acabamos en un extremo, que pase al otro extremo
    } else if (num == 1) {
      num = 4;
    }
  }

  //pleft
  if (digitalRead(32)==0) {
    Serial.println("Izquierdo");
    delay(250);
    // Rotamos hacia la izquierda (switch)
    if (num != 4) {
      num++;
      // Si acabamos en un extremo, que pase al otro extremo
    } else if (num == 4) {
      num = 1;
    }
  }
  
  switch (num) {
    case 1:
      digitalWrite(49, LOW);
      delay(250);
      digitalWrite(49, HIGH);
      delay(250);
      break;
    case 2:
      digitalWrite(48, LOW);
      delay(250);
      digitalWrite(48, HIGH);
      delay(250);
      break;
    case 3:
      digitalWrite(47, LOW);
      delay(250);
      digitalWrite(47, HIGH);
      delay(250);
      break;
    case 4:
      digitalWrite(46, LOW);
      delay(250);
      digitalWrite(46, HIGH);
      delay(250);
      break;
  }
}
