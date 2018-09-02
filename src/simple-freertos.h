#ifndef simple-freertos_h
#define simple-freertos_h

/**
 * Funcion para la tarea
 */
#define tarea(nombre) void nombre(void *p)

/**
 * Crea tarea
 */
#define crearTarea(funcion, nombre, prio) xTaskCreate(funcion, nombre, 256, NULL, prio, NULL)

/**
 * Invoca la función vTaskDelay
 */
#define esperar(ms) vTaskDelay( ms / portTICK_PERIOD_MS )

/**
 * Invoca la función vTaskDelayUntil
 */
#define esperarPeriodo(ms) vTaskDelayUntil( ms / portTICK_PERIOD_MS )

#endif
