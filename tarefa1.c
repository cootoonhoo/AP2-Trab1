#include <stdio.h>
#include <stdlib.h>
#define LARGURA 10
#define ALTURA 10

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
    }
    return pntMatriz;
}

void InicializarMatriz(Quadrante **pntMatriz)
{
    for(int y = 0; y < ALTURA; y++)
    {
        for(int x = 0; x < LARGURA; x++)
        {
            ConstrutorQuadrante(*(pntMatriz+x)+y);
        }
    }
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
            continue;
        }

        system("cls"); // Limpa o console
        printf("==== MARCAR RAIO ====\n");
        printf("Digite o mes que o raio caiu:\n");
        scanf(" %d", &(*(cidade+x)+y)->mes);
        if((*(cidade+x)+y)->mes < 0 || (*(cidade+x)+y)->mes > 12)
        {
            validacao = 1;
            continue;
        }

        system("cls"); // Limpa o console
        printf("==== MARCAR RAIO ====\n");
        printf("Digite o ano que o raio caiu:\n");   
        scanf(" %d", &(*(cidade+x)+y)->ano);
    } while (validacao);

    do
    {
        system("cls"); // Limpa o console
        printf("==== MARCAR RAIO ====\n");
        if(validacao)
        {
        printf("\n--- Opcao de clima invalido! ---\n\n");
        }
        validacao = 0;
        printf("Selecione um clima:\n");
        printf("1 - Ensolarado\n");
        printf("2 - Chuvoso\n");
        printf("3 - Nublado\n");
        printf("4 - Outro\n");
        printf("\nDigite um numero correspondente ao tempo:\n");
        scanf(" %d", &(*(cidade+x)+y)->tempo);

        if((*(cidade+x)+y)->tempo  < 1 || (*(cidade+x)+y)->tempo > 4)
            validacao = 1;
    } while (validacao);
    return 0;
}

void ImprimirQntRaios(int qnt)
{
    system("cls"); // Limpa o console
    printf("==== QUANTIDADE QUADRANTES AFETADOS ====\n");
    printf("Quantidade de quadrante(s) afetado(s) : %d \n\n", qnt);
    system("pause");    //Função para ficar aguardando algum input do usuário. Apenas por questões de experiencia de usuario
}

void ImprimirQntCidadesNaoAtingidas(int qnt)
{
    system("cls"); // Limpa o console
    printf("==== QUANTIDADE QUADRANTES NAO ATINGIDOS ====\n");
    printf("Quantidade de quadrante(s) nao atingido(s): %d \n\n", (ALTURA * LARGURA - qnt));
    system("pause");    //Função para ficar aguardando algum input do usuário. Apenas por questões de experiencia de usuario
}

void ExibirMatrizCidade(Quadrante **Cidade)
{
    // ATENÇÃO - Cidades com quaisquer dimensoes maiores que 10x10 ira desalinhar a exibicao
    // Sendo assim, desativamos as coordenadas ao lado da matriz nessas situações;
    system("cls"); // Limpa o console
    printf("==== MAPA DA CIDADE ====\n");
    printf("   ");
    if(LARGURA <= 10)
        for(int x = 0; x < ALTURA; x++)
            printf(" %d ", x);
    printf("\n");
    for(int y = 0; y < ALTURA; y++)
    {
        if(ALTURA <= 10)
            printf(" %d ", y);
        for(int x = 0; x < LARGURA; x++)
        {
            printf(" ");
            if((*(Cidade+x)+y)->intensidadeRaio == 0)
                printf("-");
            else
                printf("x");
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
    system("pause");
}

// --------------------------------------------------------------

int main()
{
    Quadrante **matrizCidade = GerarMatriz();
    int MenuOption = 0, qntRaios = 0;
    if(matrizCidade == NULL)
    {
        Erro("Memoria insuficiente para alocar a Matriz!");
        return 0;
    }

    InicializarMatriz(matrizCidade);

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
            ImprimirQntRaios(qntRaios);
            break;
        case QuantidadeAreas:
            ImprimirQntCidadesNaoAtingidas(qntRaios);
            break;
        case Matriz:
            ExibirMatrizCidade(matrizCidade);
            break;
        default:
            break;
        }
    } while (MenuOption != 5);
    
    // Exemplo de como imprimir dados do quadrante;
    // Debug teste
    // printf("%d",(*(matrizCidade))->intensidadeRaio);
    // printf("%d",(*(matrizCidade))->dia);
    // printf("%d",(*(matrizCidade))->mes);
    // printf("%d",(*(matrizCidade))->ano);

    // Libera a memória alocada
    for (int i = 0; i < LARGURA; i++)
    {
        free(matrizCidade[i]);
    }
    free(matrizCidade);
    return 0;
}