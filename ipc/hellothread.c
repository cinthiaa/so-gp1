#include <stdio.h>
#include <pthread.h>
#define NUM_THREAD 10

long saldo = 1000;
pthread_mutex_t lock;
pthread_mutex_t lock2;

void * printHello(void *td){
	long lsaldo = saldo;
	printf("Hello World desde el hilo %ld \n",(long)td);
	pthread_mutex_lock(&lock);
	//pthread_mutex_lock(&lock); esto sería un deadlock, doble asegurar no tiene sentido
	lsaldo = saldo;
	printf("El saldo actual es %ld \n", lsaldo);
	saldo = lsaldo + 100;
	pthread_mutex_unlock(&lock);
}

int main(){
	pthread_t threads[NUM_THREAD]; //metainformacion que guardas del hilo
	long t;
	
	for(t = 0 ; t < NUM_THREAD ; t++){
		pthread_create(&threads[t],NULL,printHello,(void *)t); //En realidad necesitas la dirección, por eso el &
	}
	
	for(t = 0 ; t < NUM_THREAD ; t++){
		pthread_join(threads[t],NULL); //Join es como un wait por el hilo
	}
	
	printf("Saldo final %ld \n", saldo); //Si este va después del exit, no hace nada
	
	
	pthread_exit(NULL); //Asegura que todos los hilos terminen antes de salir, solo lo puedes ejecutar en un main
	
}