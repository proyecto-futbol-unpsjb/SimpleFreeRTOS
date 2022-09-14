#include "Arduino.h"
#include <Arduino_FreeRTOS.h>
#include <SimpleFreeRTOS.h>

// Prende y apaga el led.
tarea(mi_tarea)
{
  int flag = 0;
  porSiempre {
    digitalWrite(LED_BUILTIN, flag = !flag ? HIGH : LOW);
    esperarPeriodo();
  }
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  // Crea una tarea periodica con periodo de 1000 ms.
  crearTareaPeriodica(mi_tarea, 1, 1000);
}

void loop() {
  // No se utiliza.
}
