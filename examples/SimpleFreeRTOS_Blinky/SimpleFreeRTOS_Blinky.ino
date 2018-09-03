#include "Arduino.h"
#include <simple-freertos.h>

// prende y apaga el led
tarea(mi_tarea)
{
  int flag = 0;
  while(true) {
    if (flag == 0) {
      digitalWrite(LED_BUILTIN, HIGH);
      flag = 1;
    } else {
      digitalWrite(LED_BUILTIN, LOW);
      flag = 0;      
    }       
    esperarPeriodo();
  } 
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  // crea una tarea periodica, con periodo de 1000 ms
  crearTareaPeriodica(mi_tarea, 1, 1000);
  iniciarPlanificador();
}

void loop() {
  // No se hace nada
}

