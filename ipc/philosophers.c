#include <stdio.h>
#include <pthread.h>
#define NUM_PHILOSOPHERS 10
#define NUM_FORK 5

semaphore_t forks[NUM_FORK];

void * life(void *td){
	long id = (long) td;
	while(1){
		//pensar (esto es alguna operacion real que no requiera recursos)
		if(id % 2 == 0){
			sem_wait(&forks[id]); //sem_wait es decrementar el semaforo
			sem_wait(&forks[(id+1)%NUM_PHILOSOPHERS]);
		}else{
			sem_wait(&forks[(id+1)%NUM_PHILOSOPHERS]);
			sem_wait(&forks[id]); 
		}
		//comer (operacion que requiere recursos)
	}	
}

int main(){
	pthread_t threads[NUM_THREAD]; //metainformacion que guardas del hilo
	long t;
	
	for(t = 0 ; t < NUM_THREAD ; t++){
		pthread_create(&threads[t],NULL,printHello,(void *)t); //En realidad necesitas la direcci贸n, por eso el &
	}
	
	for(t = 0 ; t < NUM_THREAD ; t++){
		pthread_join(threads[t],NULL); //Join es como un wait por el hilo
	}
	
	printf("Saldo final %ld \n", saldo); //Si este va despu茅s del exit, no hace nada
	
	
	pthread_exit(NULL); //Asegura que todos los hilos terminen antes de salir, solo lo puedes ejecutar en un main
	
}