/****************************************************************************
Autoria:Viktor Kamei Mota
Data: 17/07/2022
Este trabalho consiste em elaborar um jogo no estilo PALAVRA CRUZADA.
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int horizontal(char* palavra, int linha, int coluna, int matriz[TAM][TAM]);
int vertical(char* palavra, int linha, int coluna, int matriz[TAM][TAM]);
int diagonal(char* palavra, int linha, int coluna, int matriz[TAM][TAM]);
//declara tres funções que são para proucurar as palavras em seu loop

int main ()
{
    int semente, linha, coluna;
    //gera 4 variaveis: semente e usada para gerar os valores randomicos/ n e m serão usados para percorrer pela matriz/
    int matriz[TAM][TAM];
    //cria uma matriz 10x10 / matriz[linha = m][coluna = n]
    int controle;
    char palavra[TAM];
    //palavra dada pelo usuario para ver se esta na matriz
    int i=0, i2 = 0, i3 = 0;
    //variaveis de controle

    /****************************************************************************
        1-Gerando a matriz com numeros randomicos a partir de uma semente
    ****************************************************************************/
    printf("Digite uma semente: ");
    scanf("%d", &semente);
    //pede e guarda o valor da semente que sera usada na função srand

    srand(semente);
    //da ao parametro da função srand o valor inserido pelo usuario

    /*****************gerando a matriz aleatoria*****************/
    //a função for a seguir serve para rodar todos os valores da matriz dando valores randomincos a cada termo
    for (linha = 0; linha < TAM; linha++)
    //primeiro iniciasse a primeira linha da matriz q vai de 0 a 9
    {
        for (coluna = 0; coluna < TAM; coluna++)
        //depois e rodado todas as colunas da linha, iniciada no for anterior
        //ex. no primeiro loop o valor da matriz seria [0][1,2,3...]
        {
            matriz[linha][coluna] = (rand()%26)+97;
            //o resultado do resto dos numeros randomicos por 26 vai ser numeros de 0 a 25
            //é somando 97 para q seja impressos somente letras visto que é esta a posição quando começa as letras na lista de char
        }
    }

    /*****************imprimindo a matriz*****************/
    //este "for loop" faz a mesma coisa que o anterior so que imprime cada termo da matriz
    for (linha = 0; linha < TAM; linha++)
    {
        printf("\n");
        //e dado uma quebra de linha depois q cada linha da função e rodada
        for (coluna = 0; coluna < TAM; coluna++)
        {
            printf("%c ", matriz[linha][coluna]);
            //imprime os valores inteiros da matriz como char
        }
    }

    printf("\n");

    /****************************************************************************
       2 Lendo a matriz na horizontal vertical e diagonal
    ****************************************************************************/
    while (palavra[0] != '.')
    //cria um loop infinito que para se for digitado "."
    {
        printf("\nDigite uma palavra: ");
        scanf("%s", &palavra);
        controle = 0;
        //pede e guarda uma string dada pelo usuário
        printf("\n");

        /*****************percorrendo na horizontal*****************/
        for (linha = 0; linha < TAM; linha++)
        {
            for (coluna = 0; coluna < TAM; coluna++)
            {
                controle += horizontal(palavra, linha, coluna, matriz);
                //roda a função que proucura palavras na horizontal
                //toda vez que uma palavra e encontrada e somada 1 ao controle 
            }
        }

        /*****************percorrendo na vertical*****************/
        for (coluna = 0; coluna < TAM; coluna++)
        //inicia na primeira coluna da matriz
        {
            for (linha = 0; linha < TAM; linha++)
            //depois e rodado todas as linhas da coluna iniciada no for anterior
            //ex. no primeiro loop o valor da matriz seria [0,1,2,3][0]
            {
                controle += vertical(palavra, linha, coluna, matriz);
                //roda a função que proucura palavras na vertical
                //toda vez que uma palavra e encontrada e somada 1 ao controle 
            }
        }

        /*****************percorrendo na diagonal*****************/
        i3=TAM;
        for (i = 0; i < TAM; i++)
        {
            for (i2 = 0; i2 < i3 ; i2++)
            {
                linha = i2;
                coluna = linha + i;
                controle += diagonal(palavra, linha, coluna, matriz);
                //roda a função que proucura palavras na diagonal
                //toda vez que uma palavra e encontrada e somada 1 ao controle 
            }
            i3--;
        }
        /* Estes "for loops" aninhados servem para percorrer a diagonal da seguinte forma:
        Primeiro e percorrido a diagonal principal, dado q no primeiro loop i = 0, entao m = n = i2, resultando em:[0][0], [1][1], [2][2],...
        Depois que o loop e rodado, i e somado 1, deslocando n(coluna) 1 casa a mais que m(linha), entao m = i2 / n = i2 + 1, resultando em:[0][1], [1][2], [2][3],...
        Assim depois de um loop sempre move-se uma coluna para direita ate acabar as colunas*/

        i3 = TAM;
        for (i = 1; i < TAM ; i++)
        {
            for (i2 = 0; i2 < i3-1 ; i2++)
            {
                coluna = i2;
                linha = coluna + i;
                controle += diagonal(palavra, linha, coluna, matriz);
                //roda a função que proucura palavras na diagonal
                //toda vez que uma palavra e encontrada e somada 1 ao controle 
            }
            i3--;
        }
        if (controle == 0)
        //se o controle e igual a 0 isso quer dizer que nenhuma palavra foi encontrada
        {
            printf("Palavra não encontrada\n");
        }
    }
    //para que todas as diagonais sejam percorridas e feito o mesmo so que deslocando 1 linha envez de uma coluna

    //void confirma(horizontal, vertical, diagonal);

    return 0;
}

/****************************************************************************
    3 Achando as palavras na matriz
****************************************************************************/
int horizontal(char* palavra, int linha, int coluna, int matriz[TAM][TAM])
//cria a função que achara a palavra na horizontal
{
    int i, controle = 0;
    for (i = 0; i < TAM+1; i++)
    {
        if (palavra[i] == '\0')
        {
            printf("palavra encontrada NA HORIZONTAL em: %d %d\n", linha + 1, coluna + 1);
            controle = 1;
            //toda vez que uma palavra e encontrada controle e dado o valor de 1
            break;
        }
        if(palavra[i] != matriz[linha][coluna + i])
        {
            break;
        }
    }
    return controle;
    //retorna o valor dado ao controle 
}

int vertical(char* palavra, int linha, int coluna, int matriz[TAM][TAM])
//cria a função que achara a palavra na vertical
{
    int i, controle = 0;
    for (i = 0; i < TAM+1; i++)
    {
        if (palavra[i] == '\0')
        {
            printf("palavra encontrada NA VERTICAL em: %d %d\n", linha + 1, coluna + 1);
            controle = 1;
            //toda vez que uma palavra e encontrada controle e dado o valor de 1
            break;
        }
        if(palavra[i] != matriz[linha + i][coluna])
        {
            break;
        }
    }
    return controle;
    //retorna o valor dado ao controle 
}

int diagonal(char* palavra, int linha, int coluna, int matriz[TAM][TAM])
//cria a função que achara a palavra na diagonal
{
    int i, controle = 0;
    for(i = 0; i < TAM+1; i++)
    {
        if(palavra[i] == '\0')
        {
            printf("palavra encontrada NA DIAGONAL em: %d %d\n", linha + 1, coluna + 1);
            controle = 1;
            //toda vez que uma palavra e encontrada controle e dado o valor de 1
            break;
        }
        if(palavra[i] != matriz[linha + i][coluna + i])
        {
            break;
        }
    }
    return controle;
    //retorna o valor dado ao controle 
}
