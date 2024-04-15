// Instrucciones
// Crear el siguiente codigo para arduino.
// Todas las esperas de tiempo dentro del loop no pueden sea bloqueadas (no se puede usar delay a menos que sea especificado), solo en el bloque de setup se puede usar delay.
// En el bloque de loop no se puede usar la funcion hacerRutina
// La SALIDA_1 y la SALIDA_2 nunca pueden estar en HIGH a la vez.
// En el setup la SALIDA_1 va a estar en HIGH por 15 segundos (usar funcion delay) y despues va ir a LOW.

// En el loop

// Si la ENTRADA_2 se pone en LOW de forma fija, la SALIDA_1 y SALIDA_2 deberian ponerse en LOW por 2 segundos (usar funcion delay para los 2 segundos), despues la SALIDA_2 debe ponerse en HIGH por 15 segundos (no usar funcion delay) y despues pasar a LOW.
// Si la ENTRADA_2 se pone en HIGH entonces se empieza a leer la ENTRADA_1


// Si la ENTRADA_1 se va a LOW por un momento, la SALIDA_2 tiene que estar en HIGH por 15 segundos y despues ir a LOW.
// Si la ENTRADA_1 vuelve de nuevo a LOW por un momento, esta vez la SALIDA_1 se pone en HIGH, se espera 15 segundos y se pone en LOW.
// Si en medio de la espera se presiona la ENTRADA_1 vuelve a LOW, entonces las 2 salidas se ponen en LOW por 2 segundos (usar funcion delay para los 2 segundos) y la SALIDA diferente a la anterior se pone en HIGH se esperan 15 segundos (no usar funcion delay) y despues se pone en LOW.

// La ENTRADA_2 tiene prioridad sobre la ENTRADA_1.

// Usar como base el siguiente codigo
const int SALIDA_1 = 5;
const int SALIDA_2 = 6;
const int ENTRADA_1 = 4;
const int ENTRADA_2 = 3;
int TOGGLE_SALIDA = SALIDA_2;

unsigned long previousMillisEntrada2 = 0;  // Store the last time the LED was updated
const long interval = 20000;       // Interval at which to wait (in milliseconds)

void setup() {
  // put your setup code here, to run once:
  pinMode(SALIDA_1, OUTPUT);
  pinMode(SALIDA_2, OUTPUT);
  pinMode(ENTRADA_1, INPUT);
  pinMode(ENTRADA_2, INPUT);

  digitalWrite(SALIDA_1, LOW);
  digitalWrite(SALIDA_2, LOW);
  hacerRutina(SALIDA_1);
}

void hacerRutina(int salida) {
  digitalWrite(salida, HIGH);
  delay(interval);
  digitalWrite(salida, LOW);
}

bool entrada2Low = false;
bool highSalida1 = false;

void loop() {
  unsigned long currentMillis = millis();  // Get the current time


  if(digitalRead(ENTRADA_2) == LOW && entrada2Low) {
    digitalWrite(SALIDA_1, LOW);
    digitalWrite(SALIDA_2, LOW);
    delay(2000);
    digitalWrite(SALIDA_2, HIGH);
    delay(interval);
    digitalWrite(SALIDA_2, LOW);
    entrada2Low = false;
    highSalida1 = true;
  } else if(digitalRead(ENTRADA_2) == HIGH) {
    entrada2Low = true;

    if (highSalida1) {
      digitalWrite(SALIDA_1, HIGH);
      delay(interval);
      digitalWrite(SALIDA_1, LOW);
      highSalida1 = false;
    }

    if (digitalRead(ENTRADA_1) == LOW) {
      digitalWrite(SALIDA_1, LOW);
      digitalWrite(SALIDA_2, LOW);
      delay(2000);
      digitalWrite(TOGGLE_SALIDA, HIGH);
      delay(interval);
      digitalWrite(TOGGLE_SALIDA, LOW);

      if (TOGGLE_SALIDA == SALIDA_1) {
        TOGGLE_SALIDA = SALIDA_2;
      } else {
        TOGGLE_SALIDA = SALIDA_1;
      }
    }
  }
}