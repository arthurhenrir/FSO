#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

    unsigned int saida1, saida2;
    FILE *arquivo1, *arquivo2;
    char *cont1, *cont2;
    int valida = 0;
    cont1 = malloc(sizeof(char) * 314572800);
    cont2 = malloc(sizeof(char) * 314572800);
    for (int i = 1; i < argc; i++)
    {
        arquivo1 = fopen(argv[i], "rb");
        saida1 = fread(cont1, sizeof(char), 314572800, arquivo1);
        for (int j = i + 1; j < argc; j++)
        {
            arquivo2 = fopen(argv[j], "rb");
            saida2 = fread(cont2, sizeof(char), 314572800, arquivo2);
            printf("%s %s ", argv[i], argv[j]);

            if (saida1 != saida2)
            {
                printf("diferentes\n");
            }
            else
            {
                valida = 0;
                for (int k = 0; k < saida1; k++)
                {
                    if (cont1[k] != cont2[k])
                    {
                        printf("diferentes\n");
                        valida = 1;
                        break;
                    }
                }
                if (valida == 0)
                {
                    printf("iguais\n");
                }
            }
            fclose(arquivo2);
        }
        fclose(arquivo1);
    }

    return 0;
}