#include <stdio.h>
#include <stdlib.h>
#define N 30000
/* Funções e structs relacionados a Lista */
typedef struct Sudito 
{
    int numSudito;
    struct Sudito *proximoSudito;
} Sudito;

Sudito * GerarLista(int tamanho) // Função para gerar a lista de suditos
{
    Sudito * Controlador = NULL;
    Sudito * SuditoAtual = NULL;
    Controlador = (Sudito *)malloc(sizeof(Sudito));
    SuditoAtual = Controlador; // É necessário uma variável externa ao primeiro da lista para não perdemos o ponteiro da posicao inicial
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

int RemovePosicaoLista(Sudito * Controlador, int pos) {
    Sudito * SuditoAtual = Controlador;
    Sudito * SuditoTemporario = NULL;

    if (pos == 0) {
        //Manipulação de variáveis para que o Sudito seguinte ocupe a primeira posição da lista
        Sudito * SuditoSeguinte = NULL;
        SuditoSeguinte = (Controlador)->proximoSudito;
        free(Controlador);
        Controlador = SuditoSeguinte;
        return 1; // Operação concluida, retorna true;
    }

    for (int i = 0; i < pos-1; i++) { 
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
            printf("Suditos na lista de convidados:\n%d",atual->numSudito);
        else
            printf(", %d", atual->numSudito);
        atual = atual->proximoSudito;
        i++;
        if(i > 10000)
        {
            printf("\nAinda ha mais suditos na lista...\n");
            return; // Caso a lista tenha mais de 10mil suditos, apenas os 10mil primeiros serao impressos.
        }
    }   
    printf("\n");
}

/*Funções auxiliares*/
int InputQuantidadeDeRounds()
{
    int resposta = 1;
    do
    {
        printf("--- SISTEMA DE CONVIDADOS DE NLOGONIA ---\n");
        if(resposta <= 0)
        {
            system("cls");
            printf("\nO valor %d nao e valido! \n", resposta);
        }
        printf("Quantos turnos deseja fazer?\n");
        scanf(" %d", &resposta);
    } while (resposta <= 0);
    return resposta;
}

void ComecarRounds(int qntRounds, Sudito * listaSuditos)
{
    int Multiplo = 2;
    for(int i = 0; i < qntRounds; i++)
    {
        do
        {
            system("cls");
            printf("--- ROUND %d ---\n", i+1);
            if(Multiplo <= 0)
            {
                printf("\nO valor %d nao e valido!\n", Multiplo);
            }
            if(Multiplo == 1)
            {
                printf("\nO valor %d nao e valido!\n", Multiplo);
                printf("O valor 1 removeria todos os elementos, por isso e invalido!\n\n");
            }
            printf("Digite o multiplo das posicoes a serem removidas:\n");
            scanf(" %d", &Multiplo);
        } while (Multiplo <= 1);

        Sudito *suditoTemporario;
        int count = 0;
        suditoTemporario = listaSuditos;
        while(suditoTemporario != NULL)
        {
            if(count == Multiplo-1)
            {
                suditoTemporario->numSudito = -1;
                count = -1;
            }
            count++;
            suditoTemporario = suditoTemporario->proximoSudito;
        }
        suditoTemporario = listaSuditos;
        count = 0;

        while(suditoTemporario != NULL)
        {
            if(suditoTemporario->numSudito == -1)
            {
                suditoTemporario = suditoTemporario->proximoSudito;
                RemovePosicaoLista(listaSuditos, count);
                continue;
            }
            count++;
            suditoTemporario = suditoTemporario->proximoSudito;
        }
    imprimirLista(listaSuditos);
    printf("\n");
    system("pause");
    system("cls"); // Limpa o console
    }
}

void ImprimirResultadoFinal(Sudito * listaSuditos)
{
    printf("--- LISTA FINAL DE CONVIDADOS --- \n");
    imprimirLista(listaSuditos);
}

int main()
{
    Sudito *ListaSuditos = GerarLista(N);
    int qntRounds;
    qntRounds = InputQuantidadeDeRounds();
    ComecarRounds(qntRounds,ListaSuditos);
    ImprimirResultadoFinal(ListaSuditos);
    return 0;
}
