#include <stdio.h>
#include <dlfcn.h>


int main(int argc, char* argv[]){

    // declarando as funções que serão usadas
    int (*imprime)(void); // essa variável vai receber o endereço da função imprime do arquivo .so que será carregado dinamicamente 
    int (*calcula)(int,int);
    int (*trigo)(double);
    void* dlCarregada = (int(*)(void))dlopen(argv[1], RTLD_LAZY); // Carrega a biblioteca dinâmica
    
    // Verifica se a biblioteca foi carregada
    if (dlCarregada == NULL) {
        printf("nao disponivel\n");
        return 0;
    }
    else {
        
        
        // carrega a função imprime
        imprime = (int(*)(void))dlsym(dlCarregada, "imprime");
        // Verifica se a função imprime foi implementada
        if (dlsym(dlCarregada, "imprime") == NULL) {
            printf("nao implementado\n");
        }
        else {
            printf("%d\n", imprime());
        }
        

        // carrega a função calcula
        calcula = (int(*)(int,int))dlsym(dlCarregada, "calcula");
        // Verifica se a função calcula foi implementada
        if (dlsym(dlCarregada, "calcula") == NULL) {
            printf("nao implementado\n");
        }
        else {
            printf("%d\n", calcula(atoi(argv[2]), atoi(argv[3])));
        }
        
        // carrega a função trigo
        trigo = (int(*)(double))dlsym(dlCarregada, "trigo");
        // Verifica se a função trigo foi implementada
        if (dlsym(dlCarregada, "trigo") == NULL) {
            printf("nao implementado\n");
        }
        else {
            printf("%d\n", trigo(atoi(argv[4])));
        }
    }
}