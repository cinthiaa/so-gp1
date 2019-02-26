// init: The initial user-level program

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char *argv[] = { "sh", 0 }; 

int
main(void)
{
  int pid, wpid;

  if(open("console", O_RDWR) < 0){ //manda abrir console, emula la terminal de xv6, 
    mknod("console", 1, 1);
    open("console", O_RDWR);
  }
  dup(0);  // stdout
  dup(0);  // stderr

  for(;;){
    printf(1, "init: Hola Cinthia, sh\n"); //el 1 es el id de la consola creada 
    pid = fork();
    if(pid < 0){
      printf(1, "init: fork failed\n"); //si no hay memoria no se clna el programa
      exit();
    }
    if(pid == 0){ //proceso hijo
      exec("sh", argv); //se eejcuta sh, si no se ejecuta el sh sigue el programa y se imprime exec sh failed y se sale
      printf(1, "init: exec sh failed\n");
      exit();
    }
    while((wpid=wait()) >= 0 && wpid != pid)
      printf(1, "zombie!\n");
  }
}
