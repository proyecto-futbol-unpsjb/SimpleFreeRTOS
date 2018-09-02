#ifndef simple-freertos_h
#define simple-freertos_h

#define crearTarea(funcion, nombre, prio) xTaskCreate(funcion, nombre, 256, NULL, prio, NULL)

#endif
