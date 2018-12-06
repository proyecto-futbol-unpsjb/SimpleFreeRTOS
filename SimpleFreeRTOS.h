#ifndef SimpleFreeRTOS_h
#define SimpleFreeRTOS_h

/**
 * Funcion para la tarea
 */
#define tarea(nombre) void nombre(void *p)

/**
 * Inicia el planificador
 */
#define iniciarPlanificador() vTaskStartScheduler()

/**
 * Crear semaforo
 */
#define creaSemaforoMutex() xSemaphoreCreateMutex()
#define creaSemaforoBinario() xSemaphoreCreateBinary()
#define creaSemaforoContador(max, init) xSemaphoreCreateCounting((UBaseType_t) max, (UBaseType_t) init)

/**
 * Utilizar semaforo
 */
#define tomarSemaforo(semaforo) xSemaphoreTake(semaforo, portMAX_DELAY)
#define liberarSemaforo(semaforo) xSemaphoreGive(semaforo)

/**
 * Crea tarea
 */
#define crearTarea(funcion, prioridad) creaTarea(funcion, prioridad, 0)

/**
 * Crea una tarea periodica
 */
#define crearTareaPeriodica(funcion, prioridad, periodo) creaTarea(funcion, prioridad, periodo)

/**
 * Crea una tarea
 */
void creaTarea( void (*task) (void*), UBaseType_t prio, int periodo);

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

/**
 * Semáforo
 */
typedef SemaphoreHandle_t semaforo;

#endif
