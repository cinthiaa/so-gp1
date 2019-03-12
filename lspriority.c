#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) //arreglo de arreglos de caracteres argumentos
{
	int pid;
	int priority;
	pid = atoi(argv[1]);
	priority = getpriority(pid);
	if(priority== -1){
		printf(1, "Process not found with id %d\n", pid);
	}else{
		printf(1, "Process %d has priority %d\n", pid, priority);
	}
		
	exit();	
}