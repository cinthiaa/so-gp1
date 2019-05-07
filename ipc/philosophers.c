#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_PHILOSOPHERS 10
#define NUM_FORK 5

sem_t forks[NUM_FORK];

long randomInRange(int start, int final){
	return start + random()%(final-start);
}

void * life(void *td){
	long id = (long) td;
	srandom((id+1) * time(NULL));
	printf("Soy el filosofo %ld\n",id);
	while(1){
		//pensar (esto es alguna operacion real que no requiera recursos)
		printf(" %ld>, VOy a pensar\n",id);
		sleep(randomInRange(5,10));
		printf(" %ld>, Tengo hambre\n",id);
		if(id % 2 == 0){ //si id es par
			sem_wait(&forks[id]); //sem_wait es decrementar el semaforo
			sem_wait(&forks[(id+1)%NUM_PHILOSOPHERS]);
		}else{
			sem_wait(&forks[(id+1)%NUM_PHILOSOPHERS]);
			sem_wait(&forks[id]); 
		}
		//comer (operacion que requiere recursos)
		printf(" %ld>, VOy a comer\n",id);
		sleep(randomInRange(2,10));
		sem_post(&forks[id]);
		sem_post(&forks[(id + 1)%NUM_PHILOSOPHERS]);
	}	
}

int main(){
	pthread_t philosophers[NUM_PHILOSOPHERS]; //metainformacion que guardas del hilo
	long t;
	
	for(t =0 ; t<NUM_FORK; t++){
		sem_init(&forks[t],0,1); //Referencia al sempaforo, tipo de semaforos (entre hilos o procesos) , cantidad de semaforos 
	}
	for(t = 0 ; t < NUM_PHILOSOPHERS ; t++){
		pthread_create(&philosophers[t],NULL,life,(void *)t); //En realidad necesitas la direcci贸n, por eso el &
	}
	
	pthread_exit(NULL); //Asegura que todos los hilos terminen antes de salir, solo lo puedes ejecutar en un main
	
}