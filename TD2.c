  //exercice 1
 

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

float tabt[1000];

void *ma_fonction_thread(void* arg)
{ 
  int n = (int) arg;
  int i;
  for(i=0;i < a; i++){
  tab[i]=(rand()%100)+1;
  pthread_exit(0);
  }
;
}

void *ma_fonction2 (void *arg){
	int tab = (int*)arg;
	int i;
	int verif=0;   
	
	for(i=0; i < tab[0] ; i++)
	{
    if (tabt[i]==val)
    verif=1;
	}
	pthread_exit(verif);
}
	


int main(void){

int i;
int verif=0;
int ret,ret2;
pthread_t my_thread;
int tab[2];
printf("Entrez la taille du tableau");
scanf(%d,&tab[0]);

ret = pthread_create(&my_thread, NULL ,ma_fonction_thread, (void *) tab);

if (ret !=0)
{ printf("erreur");
  exit(1);
}

float val;
printf("Entrez votre valeur");
scanf(%f,&tab[1]);

pthread_join(my_thread,NULL);

ret2 = pthread_create(&my_thread, NULL ,ma_fonction2, (void *) tab);
pthread_join(my_thread,&verif);
return(0);


}