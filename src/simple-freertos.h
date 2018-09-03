#include "Arduino_FreeRTOS.h"

#ifndef simple-freertos_h
#define simple-freertos_h

/**
 * Funcion para la tarea
 */
#define tarea(nombre) void nombre(void *p)

/**
 * Inicia el planificador
 */
#define iniciarPlanificador() vTaskStartScheduler();

/**
 * Crea tarea
 */
#define crearTarea(funcion, prioridad) creaTarea(funcion, prioridad, 0)
#define crearTareaPeriodica(funcion, prioridad, periodo) creaTarea(funcion, prioridad, periodo)

/**
 * Crea una tarea
 */
void creaTarea( void (*task) (void*), int prio, int periodo);

/**
 * Invoca la función vTaskDelay
 */
void esperar(TickType_t ms);

/**
 * Invoca la función vTaskDelayUntil
 */
void esperarPeriodo(void);

/**
 * Datos de la tarea
 */
struct task_info {
  TickType_t awake;
  TickType_t period;
};

#endif
