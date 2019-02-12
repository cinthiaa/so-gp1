## Objetivo

Crear dos llamadas al sistema con sus respectivos comandos para apagar y reiniciar.

## Herramientas
Make

GCC ->compilar

GIT

##Conceptos
1) Llamadas al sistema: 
*se usan para acceder al hw, 
*desde el comando son una interrupcio
*desde el kernel utilizan el codigo del hw esecifico.

2)Modo kernel
*BIt que se activa para acceder al hw
*se prende cuando se ejecuta el kernel

3)Interrupciones
*Como el HW interactua con el CPU

4)Interrupciones via SW (trap)
 *Software comunicar con el kernel, SF->CPU->KERNEL
 
 ## Que aprendi?
 
 En x86 la interrupcion que corresponde al kernel es la 64, esta es necesaria agregarla al ensamblador de cualquier codigo de llamada al sistema. Fue necesario agregar el ensamblador de las funiconnes de reboot yy shutdown ppara que el kernel las tenga disponibles, y ademas agregarlas a USERPROGS para que se puedan llamar desde la terminal. Los coreanos borran contenedores.
