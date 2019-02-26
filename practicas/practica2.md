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
 
 ## URL commit
 
