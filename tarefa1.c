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
    system("cls"); // Limpa o console
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

/* Funções do programa */

int MarcarRaio(Quadrante **cidade)
{
    int x, y, validacao = 0;
    do
    {
        system("cls"); // Limpa o console
        printf("==== MARCAR RAIO ====\n");

        if(validacao)
        {
            printf("\n--- O VALOR ANTERIOR NAO E VALIDO! ---\n\n");
        }
        validacao = 0;

        printf("Digite o quadrante X que ira receber o raio:\n");
        scanf(" %d", &x);
        if(x < 0 || x >= LARGURA)
        {
            validacao = 1;
            continue;
        }

        printf("Digite o quadrante Y que ira receber o raio:\n");
        scanf(" %d", &y);
        if(y < 0 || y >= LARGURA)
        {
            validacao = 1;
            continue;
        }
    } while (validacao);
    
    do
    {
        system("cls"); // Limpa o console
        printf("==== MARCAR RAIO ====\n");

        if((*(cidade+x)+y)->intensidadeRaio > 0)
        {
            system("cls"); // Limpa o console
            Erro("Um raio nao pode cair duas vezes no mesmo lugar!");
            return Sair; // Retorna para o controle do menu a opção de sair
        }

        if(validacao)
        {
              printf("\nO valor da intensidade invalido. O valor deve ser maior que 0!\n");
        }
        validacao = 0;

        printf("Digite a intensidade do raio:\n");
        scanf(" %d", &(*(cidade+x)+y)->intensidadeRaio);

        if( (*(cidade+x)+y)->intensidadeRaio <= 0)
            validacao = 1;
    } while (validacao);

    do
    {
        system("cls"); // Limpa o console
        printf("==== MARCAR RAIO ====\n");
        if(validacao)
        {
        printf("\n--- A data anterior era invalida! ---\n");
        }
        validacao = 0;

        printf("Digite o dia que o raio caiu:\n");
        scanf(" %d", &(*(cidade+x)+y)->dia);
        if(&(*(cidade+x)+y)->dia < 0 || (*(cidade+x)+y)->dia > 31)
        {
            validacao = 1;
        }

        system("cls"); // Limpa o console
        printf("==== MARCAR RAIO ====\n");
        printf("Digite o mes que o raio caiu:\n");
        scanf(" %d", &(*(cidade+x)+y)->mes);
        if((*(cidade+x)+y)->mes < 0 || (*(cidade+x)+y)->mes > 12)
        {
            validacao = 1;
        }

        system("cls"); // Limpa o console
        printf("==== MARCAR RAIO ====\n");
        printf("Digite o ano que o raio caiu:\n");   
        scanf(" %d", &(*(cidade+x)+y)->ano);
    } while (validacao);
    return 0;
}

int main()
{
    Quadrante **matrizCidade = GerarMatriz();
    int MenuOption = 0, qntRaios = 0;
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
            MenuOption = MarcarRaio(matrizCidade);
            if(MenuOption != 5)
                qntRaios++;
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
    // Debug teste
    printf("%d",(*(matrizCidade))->intensidadeRaio);
    printf("%d",(*(matrizCidade))->dia);
    printf("%d",(*(matrizCidade))->mes);
    printf("%d",(*(matrizCidade))->ano);

    // Libera a memória alocada
    for (int i = 0; i < LARGURA; i++)
    {
        free(matrizCidade[i]);
    }
    free(matrizCidade);
    return 0;
}