#include <stdio.h>
#include <stdlib.h>

int main(){
    int n1,n2,reg, fault=0, valida=0, fila=0;
    scanf("%d", &n1);
    scanf("%d", &n2);
    int *vetPag = malloc(sizeof(int)*n1);
    for(int i=0; i<n2; i++){
        scanf("%d", &reg);
        for(int x=0; x<n1; x++){
            if(reg == vetPag[x]){
                if(reg == 0 && i < n1){
                   break; 
                }
                valida=1;
                break; 
            }                                          
        }
        if (fila == n1)
            fila=0;

        if (valida == 0){
            vetPag[fila] = reg;
            fila++;
            fault++;
        }           
            
        valida = 0;
        /*for(int x=0; x<n1; x++)
            printf("%d  ", vetPag[x]);  
        printf("\n%d\n", fault);*/
    }

    printf("%d", fault);
    return 0;
}