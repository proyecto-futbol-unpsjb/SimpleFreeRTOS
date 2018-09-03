#include "Arduino_FreeRTOS.h"
#include "simple-freertos.h"

/**
 * Crea tarea
 */
void creaTarea( void (*task) (void*), int prio, int periodo) {
  TaskHandle_t t;
  struct task_info *ti;

  /* Create a structure for use by this task. */
  ti = pvPortMalloc( sizeof( struct task_info ) );

  /* Set the structure members. */
  ti->awake = 0;
  ti->period = periodo;

  /* Create the task. */
  xTaskCreate(task,NULL, 128,  NULL,  1,  &t);

  /* Set the TLS */
  vTaskSetThreadLocalStoragePointer( t, 0, ( void * ) ti );
}

/**
 * Espera t ms.
 */
void esperar(TickType_t ms) {
  vTaskDelay(ms / portTICK_PERIOD_MS );
}

/**
 * Espera hasta el proximo periodo.
 */
void esperarPeriodo() {
  struct task_info *ti = ( struct task_info* ) pvTaskGetThreadLocalStoragePointer( NULL, 0 );
  vTaskDelayUntil(&(ti->awake), ti->period / portTICK_PERIOD_MS );
}
