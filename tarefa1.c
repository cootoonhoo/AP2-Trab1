#include <stdio.h>
#include <stdlib.h>

#define LARGURA 100
#define ALTURA 100

/* Enums auxiliares */
typedef enum
{
    Ensolarado = 1,
    Chuvoso,
    Nublado,
    Outro
} Tempo;

typedef enum
{
    ImprimirRaio = 1,
    QuantidadeRaios,
    QuantidadeAreas,
    Matriz,
    Sair
} OpcoesMenu;

/* Struct auxiliar*/

typedef struct
{
    int dia, mes, ano;
    int intensidadeRaio;
    Tempo tempo;
} Quadrante;

void ConstrutorQuadrante(Quadrante *quad)
{
    quad->dia = 0;
    quad->mes = 0;
    quad->ano = 0;
    quad->intensidadeRaio = 0;
    quad->tempo = Ensolarado;
}

/* Funções envolvendo matrizes*/

Quadrante ** GerarMatriz(){
    Quadrante **pntMatriz;
    pntMatriz = (Quadrante **)malloc(LARGURA * sizeof(Quadrante *));
    for(int i = 0; i < LARGURA; i++)
    {
        *(pntMatriz+i) = (Quadrante *)malloc(ALTURA * sizeof(Quadrante));
        ConstrutorQuadrante(*(pntMatriz+i));
    }
    return pntMatriz;
}

/* Funções para manipulação do menu*/

void ImprimirMenu()
{   
    system("clear");
    printf("==== MENU ====\n");
    printf("1 - Imprimir Raio\n");
    printf("2 - Quantidade de Raios que cairam\n");
    printf("3 - Quantidade de areas nao afetadas\n");
    printf("4 - Imprimir Matriz\n");
    printf("5 - Sair\n");
}

int PegarOpcaoMenu()
{
    int resposta;
    printf("Digite uma opcao valida:\n");
    scanf(" %d", &resposta);
    return resposta;
}
/* Funções auxiliares */
void Erro(char *msg)
{
    system("color 4F");
    printf("Erro: %s\n", msg);
}


int main()
{
    Quadrante **matrizCidade = GerarMatriz();
    int MenuOption = 0;
    if(matrizCidade == NULL)
    {
        Erro("Memoria insuficiente para alocar a Matriz!");
        return 0;
    }

    do
    {
        ImprimirMenu();
        MenuOption = PegarOpcaoMenu();
        switch (MenuOption)
        {
        case ImprimirRaio:
            printf("IMPLEMENTAR ImprimirRaio\n");
            scanf("%d", stdin);
            break;
        case QuantidadeRaios:
            printf("IMPLEMENTAR QuantidadeRaios\n");
            scanf("%d", stdin);
            break;
        case QuantidadeAreas:
            printf("IMPLEMENTAR QuantidadeAreas\n");
            scanf("%d", stdin);
            break;
        case Matriz:
            printf("IMPLEMENTAR QuantidadeAreas\n");
            scanf("%d", stdin);
            break;
        default:
            break;
        }
    } while (MenuOption != 5);
    
    // Exemplo de como imprimir dados do quadrante;
    //printf("%d",(*(matrizCidade))->intensidadeRaio);

    // Libera a memória alocada
    for (int i = 0; i < LARGURA; i++)
    {
        free(matrizCidade[i]);
    }
    free(matrizCidade);
    return 0;
}