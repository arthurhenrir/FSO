#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int compara(const void *a, const void *b){
    if (*(int*)a == *(int*)b)
        return 0;
    else
        if (*(int*)a < *(int*)b)
            return -1;
        else
            return 1;
}

int main(){
    int tam;
    int igual=0;
    scanf("%d", &tam);    
    int *v1 = malloc(sizeof(int)*tam);
    int *v2 = malloc(sizeof(int)*tam);
    for(int i=0; i<tam; i++)
        scanf("%d", &v1[i]);
    for(int i=0; i<tam; i++)
        scanf("%d", &v2[i]);
 
    #pragma omp parallel sections //Chamado da função para criar threads paralelas
    {
        #pragma omp section
            qsort(v1, tam, sizeof(int), compara);
        #pragma omp section
            qsort(v2, tam, sizeof(int), compara);
    }

    for(int i=0; i<tam; i++)
        if(v1[i] == v2[i])
            igual++;
    
    if(igual == tam)
        printf("Mesmos elementos");
    else
        printf("Diferentes");
    return 0;
}