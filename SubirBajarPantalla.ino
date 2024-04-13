const int SALIDA_1 = 5;
const int SALIDA_2 = 6;
const int ENTRADA = 4;
int TOGGLE_SALIDA = SALIDA_1;

void setup() {
  // put your setup code here, to run once:
  pinMode(SALIDA_1, OUTPUT);
  pinMode(SALIDA_2, OUTPUT);
  pinMode(ENTRADA, INPUT);

  digitalWrite(SALIDA_1, LOW);
  digitalWrite(SALIDA_2, LOW);
  hacerRutina(SALIDA_1);
}

void hacerRutina(int salida) {
  digitalWrite(salida, HIGH);
  delay(15000);
  digitalWrite(salida, LOW);
}

void loop() {
  if(digitalRead(ENTRADA) == LOW) {
    if (TOGGLE_SALIDA == SALIDA_1) {
      TOGGLE_SALIDA = SALIDA_2;
    } else {
      TOGGLE_SALIDA = SALIDA_1;
    }

    hacerRutina(TOGGLE_SALIDA);
  }
}
