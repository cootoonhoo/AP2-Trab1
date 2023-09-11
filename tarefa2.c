#include <stdio.h>
#include <stdlib.h>

/* Lógicas e structs relacionados a Lista */
typedef struct 
{
    int numSudito;
    int *proxSudito;
} Sudito;

Sudito * GerarListaSuditos(int tamLista)
{
    Sudito * ptrListaSuditos;
    ptrListaSuditos = (Sudito *)malloc(tamLista * (sizeof(Sudito)));
    return ptrListaSuditos;
}

void PreencherListaSuditos(Sudito *listaSuditos, int tamLista)
{
    Sudito * suditoAnterior;
    //Para preenchermos o valor do proxSudito, devemos começar o preenchimento decrescentemente para termos o valor do sudito anterior;
    for(int i = tamLista - 1; i >=0; i--)
    {
        if(i == tamLista - 1)
            listaSuditos->proxSudito = NULL;
        else
            listaSuditos->proxSudito = suditoAnterior;
        (listaSuditos+i)->numSudito = i + 1;
        suditoAnterior = (listaSuditos+i);
    }
}

int main()
{
    Sudito *listaSuditos = GerarListaSuditos(10);
    if(listaSuditos == NULL)
    {
        system("color 4F");
        printf("Nao foi possivel alocar memoria suficiente para a lista de suditos!\n");
        return 0;
    }
    PreencherListaSuditos(listaSuditos, 10);

    printf("%d", (listaSuditos+9)->numSudito);
    return 0;
}
