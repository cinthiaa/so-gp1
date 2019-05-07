# objetivo
Hacer un spike sobre hilos, semaforos, y locks.

#Herramientas
git
+gcc

#Conceptos:
+Hilos: 
   +proceso ligero que solo consta de su propio stack, y pointers a codigo y heap, los cuales son del proceso principal y se comparten entre hilos.
   +dado que tienen pointers a codigo, cada uno puede apuntar a una parte diferente del codigo, es decir ejecutar funciones diferentes
+Semaforos:
   +variable global (entre hilos)
   +soporta dos operaciones
   ++Incrementar cant de semaforo(sem_post)
   ++Decrementar cant de semaforo(sem_wait), si el hilo decrementa un semaforo igual a 0 se suspende
   +Se utilizan para controlar acceso a recursos
   
+Lock
  +ES una variable global
  +Soporta dos operaciones
    ++lock (bloqueo)adquirir el lock, cuando un hilo adquiere el lock se quede con el candado y el us del recurso, si alguien mas hace lock del recurso se bloquea
    ++unlock(liberar) liberar el lock, 
   +Secciones criticas. (pedazos de codigo que se debe ejecutar un hilo a la vez)
   
# Que aprendi?
+Los semaforos y locks son mecanismos que se utilizan cuando hay problemas de sincronizacion, los semaforos indican la disponibilidad de los recursos y los locks se utilizan cuando hay secciones criticas

#URL del commit
   
