#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int compara(const void *a, const void *b){
    if (*(int*)a == *(int*)b)
        return 0;
    else
        if (*(int*)a < *(int*)b)
            return -1;
        else
            return 1;
}

int tam;
int igual=0;

void * function (void * parm){   
    int *vet = (int *)parm;        
    qsort(vet, tam, sizeof(int), compara);
    
}

int main(){
    pthread_t t1, t2;
    scanf("%d", &tam);
    int *v1 = malloc(sizeof(int)*tam);
    int *v2 = malloc(sizeof(int)*tam);
    for(int i=0; i<tam; i++)
        scanf("%d", &v1[i]);
    for(int i=0; i<tam; i++)
        scanf("%d", &v2[i]);
    pthread_create(&t1, NULL, function , v1);
    pthread_create(&t2, NULL, function , v2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    for(int i=0; i<tam; i++)
        if(v1[i] == v2[i])
            igual++;
    
    if(igual == tam)
        printf("Mesmos elementos");
    else
        printf("Diferentes");
    return 0;
}