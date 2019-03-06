## Objetivo
MOdificar el programa init para imprimir un mensaje de bienvenida
MOdificar el programa sh para ejecutar al programa anterior(flechita)

## Herramientas
Make

GCC ->compilar

GIT

##Conceptos
1) Proceso:
  +Es una instacia del programa en ejecucion, con variables en memoria y un estatus del proceso.
  +Instancia del programa, esta compuesto de 3 partes:
    ++stack: variables y funciones en espacio limitado, tiene un pointer e la siguiente direccion disponible y eventualmente se llena. 
    ++heap: area de memoria dinamica=RAM+SWAP(HD) , la extension limite de las variables es el tama;o del swap y la ram
    ++codigo:segmentado, guarda la parte que se utiliza mas del programa. 
  +Tiene estados (run, wait, sleep)
  +Se crean mediante dos llamadas
    ++fork: clon
    ++exec:cambia codigo
   
   +Hay un proceso padre
   ++init
 
 ## Que aprendi
 La funcion fork crea un proceso copia sobre el cual trabaja para llevar a cabo el proceso, este proceso tiene un procesos padre que se encarga de limpiar cuanod el proceso hijo ha terminado.
 
 Es necesario agregar un wait despues de que se parseo el comando para que se espere a que termine.
 
 
 ## URL commit
 Pte1: https://github.com/cinthiaa/so-gp1/commit/7c44b48fc135da37ffed6e8f4c0ae546e16da94
 pte2: https://github.com/cinthiaa/so-gp1/commit/8774a2a6803ff64aa02f6ceaf3bf509f573afa86
 
 
