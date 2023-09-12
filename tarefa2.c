#include <stdio.h>
#include <stdlib.h>
#define N 5
/* Funções e structs relacionados a Lista */
typedef struct Sudito 
{
    int numSudito;
    struct Sudito *proximoSudito;
} Sudito;

Sudito * GerarLista(int tamanho) // Função para gerar a lista de súditos
{
    Sudito * Controlador = NULL;
    Sudito * SuditoAtual = NULL;
    Controlador = (Sudito *)malloc(sizeof(Sudito));
    SuditoAtual = Controlador; // É necessário uma variável externa ao gerenciador da lista para não perdemos o primeiro ponteiro
    for(int i = 0; i < tamanho; i++)
    {
        SuditoAtual->numSudito = i+1;
        SuditoAtual->proximoSudito = NULL;
        if(i != tamanho - 1)
            SuditoAtual->proximoSudito = (Sudito *)malloc(sizeof(Sudito));
        SuditoAtual = SuditoAtual->proximoSudito;
    }
    return Controlador;
}

int RemovePosicaoLista(Sudito ** Controlador, int pos) {
    int i = 0;
    Sudito * SuditoAtual = *Controlador;
    Sudito * SuditoTemporario = NULL;

    if (pos == 0) {
        //Manipulação de variáveis para que o Sudito seguinte ocupe a primeira posição da lista
        Sudito * SuditoSeguinte = NULL;
        SuditoSeguinte = (*Controlador)->proximoSudito;
        free(*Controlador);
        *Controlador = SuditoSeguinte;
        return 1; // Operação concluida, retorna true;
    }

    for (i = 0; i < pos-1; i++) { 
        if(SuditoAtual == NULL) // Validando se o Sudito atual existe na lista;
            return 0;         
        SuditoAtual = SuditoAtual->proximoSudito;
    }
    SuditoTemporario = SuditoAtual->proximoSudito;
    SuditoAtual->proximoSudito = SuditoTemporario->proximoSudito;
    free(SuditoTemporario);
    return 1; // Operação concluida, retorna true;
}

void imprimirLista(Sudito * Controlador)
{
    Sudito * atual = Controlador;
    int i = 0;
    while (atual != NULL)
    {
        if(i == 0)
            printf("Lista de suditos: %d",atual->numSudito);
        else
            printf(", %d", atual->numSudito);
        atual = atual->proximoSudito;
        i++;
        if(i == 10000) return;
    }   
    printf("\n");
}

/*Funções auxiliares*/
int InputQuantidadeDeRounds()
{
    int resposta;
    do
    {
        if(resposta <= 0)
        {
            system("cls");
            printf("\n --- O valor %d nao e valido! ---\n", resposta);
        }
        printf("Quantos turnos deseja fazer?\n");
        scanf(" %d", &resposta);
    } while (resposta <= 0);
    return resposta;
}

void ComecarRounds(int qntRounds, Sudito * listaSuditos)
{
    
}

int main()
{
    Sudito *ListaSuditos = GerarLista(N);
    int qntRounds;
    int Multiplo;
    do
    {
        if(qntRounds <= 0)
        {
            system("cls");
            printf("\n --- O valor %d nao e valido! ---\n", qntRounds);
        }
        printf("Quantos turnos deseja fazer?\n");
        scanf(" %d", &qntRounds);
    } while (qntRounds <= 0);

    Sudito * SuditoTemporario = ListaSuditos;
    for(int i = 0; i < qntRounds; i++)
    {
        do
        {
            if(Multiplo <= 0)
            {
                system("cls");
                printf("\n --- O valor %d nao e valido! ---\n", Multiplo);
            }
            printf("Digite o multiplo a ser removido:\n");
            scanf(" %d", &Multiplo);
        } while (Multiplo <= 0);

        while(SuditoTemporario != NULL)
        {
            for(int j = 0; j < Multiplo; j++) // Lógica para caminhar o multiplo selecionado
            {
                SuditoTemporario = SuditoTemporario->proximoSudito;
            }
            SuditoTemporario->numSudito = -1; // Valor definido para remover depois;
        }

         SuditoTemporario = ListaSuditos; // Voltando para o ínicio para agora sim, remover todos os multiplos(Marcados com -1 anteriormentet).
        for(int k = 0; SuditoTemporario != NULL; k++)
        {
            if(SuditoTemporario->numSudito == -1)
            {
                SuditoTemporario = SuditoTemporario->proximoSudito;
                RemovePosicaoLista(&ListaSuditos, k);
                k--;
            }
            else
                SuditoTemporario = SuditoTemporario->proximoSudito;
        }
    }

    // ComecarRounds(qntRounds, ListaSuditos);
    // MostrarListaFinal();
    imprimirLista(ListaSuditos);
    return 0;
}
