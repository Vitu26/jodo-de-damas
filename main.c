#include <stdio.h>
#include <stdlib.h>


#define WIDTH 640
#define HEIGHT 480


char matriz[10][10] = {
                    {' ', '1', '2', '3', '4', '5', '6', '7', '8', ' '},
                    {'1', 'P', ' ', 'P', ' ', 'P', ' ', 'P', ' ', ' '},
                    {'2', ' ', 'P', ' ', 'P', ' ', 'P', ' ', 'P', ' '},
                    {'3', 'P', ' ', 'P', ' ', 'P', ' ', 'P', ' ', ' '},
                    {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'6', ' ', 'B', ' ', 'B', ' ', 'B', ' ', 'B', ' '},
                    {'7', 'B', ' ', 'B', ' ', 'B', ' ', 'B', ' ', ' '},
                    {'8', ' ', 'B', ' ', 'B', ' ', 'B', ' ', 'B', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}


};

int x, y;
int linOri, colOri, linDes, colDes;
int player;
int vencer = 0;

/*int moverPeca( int linOri, int colOri, int linDes, int colDes) {
    int mover = 0;
    char peca;
    int dV = abs(linDes - linOri);
    int dH = abs (colDes - colOri);
    if((linOri >= 0 && linOri <= 8 && colOri >= 0 && colOri <= 8 ) &&
       (linDes >= 0 && linDes <= 8 && colDes >= 0 && colDes <= 8 )){
       peca = matriz[linOri][colOri];


        if((peca == 'P' || peca == 'B') &&
           ((dV >= 0 && dV <=1) && (dH >=0 && dH <=1))){
            mover = 1;
       }




        if(mover){
        matriz[linDes][colDes] = matriz[linOri][colOri];
        matriz[linOri][colOri] = ' ';
        return 1;//movimento realizado
        }else{
        return 9;//pe�a n�o pode ser movida deste jeito
        }
    }else{
        return 0;
    }

}*/






int pintarTelaTexto(){
    system("CLS");
    int lin = 0, col = 1, r;
    for(lin = 0; lin < 9; lin++){
        for(r = 0; r < 3; r++){
            for(col = 0; col < 9; col++){
                char peca = matriz[lin][col];
                char letra = ((lin + col) %2 == 0) ? '\xB2' : ' ';
                letra = (r == 1 && peca != ' ') ? peca : letra;
                if((lin + col) %2 == 0){
                printf("\xB2\xB2%c\xB2\xB2",letra);
                }else{
                printf("  %c  ",letra);
                }
            }
            printf("\n");
        }
    }
}

void atualizarJogo()
{

    int brancas, pretas;

    for(x = 1; x < 10; x++)
    {
        for(y = 1; y < 10; y++)
        {
            if(matriz[x][y] == 'P')
            {
                pretas += 1;
            }
            else if(matriz[x][y] == 'B')
            {
                brancas += 1;
            }
        }
    }

    if(pretas == 0)
    {
        printf("O Player 2 - BRANCAS - VENCEU! PARABENS!");
        vencer = 1;

    }
    if(brancas == 0)
    {
        printf("O Player 1 - PRETAS - VENCEU! PARABENS!");
        vencer = 1;
    }
}


int comerBrancas(){
  if(matriz[linOri][colOri] == 'P' & (matriz[linOri + 1][colOri + 1] == 'B' & matriz[linOri + 2][colOri + 2] == 'X'))
    {
        if(matriz[linDes][colDes] == matriz[linOri + 2][colOri + 2])
        {
            matriz[linDes][colDes] = 'P';
            matriz[linOri][colOri] = 'X';
            matriz[linOri + 1][colOri + 1] = 'X';
            player += 1;
        }
        else
        {
            printf("Voce deve comer a peca na linha %d, coluna %d !", (linOri + 1), (colOri + 1));
            moverPeca();
        }
    }
    else if(matriz[linOri][colOri] == 'P' & (matriz[linOri + 1][colOri - 1] == 'B' & matriz[linOri + 2][colOri - 2] == 'X'))
    {
        if(matriz[linDes][colDes] == matriz[linOri + 2][colOri - 2])
        {
            matriz[linDes][colDes] = 'P';
            matriz[linOri][colOri] = 'X';
            matriz[linOri + 1][colOri - 1] = 'X';
            player += 1;
        }
        else
        {
            printf("Voce deve comer a peca na linha %d, coluna %d !", (linOri + 1), (colOri - 1));
            moverPeca();
        }
    }
    else if(matriz[linOri][colOri] == 'P' & (matriz[linOri - 1][colOri - 1] == 'B' & matriz[linOri - 2][colOri - 2] == 'X'))
    {
        if(matriz[linDes][colDes] == matriz[linOri - 2][colOri - 2])
        {
            matriz[linDes][colDes] = 'P';
            matriz[linOri][colOri] = 'X';
            matriz[linOri - 1][colOri - 1] = 'X';
            player += 1;
        }
        else
        {
            printf("Voce deve comer a peca na linha %d, coluna %d !", (linOri- 1), (colDes - 1));
            moverPeca();
        }
    }
    else if(matriz[linOri][colOri] == 'P' & (matriz[linOri - 1][colOri + 1] == 'B' & matriz[linOri - 2][colOri + 2] == 'X'))
    {
        if(matriz[linDes][colDes] == matriz[linOri - 2][colOri + 2])
        {
            matriz[linDes][colDes] = 'P';
            matriz[linOri][colDes] = ' ';
            matriz[linOri - 1][colOri + 1] = ' ';
            player += 1;
        }
        else
        {
            printf("Voce deve comer a peca na linha %d, coluna %d !", (linOri - 1), (colDes + 1));
            moverPeca();
        }
    }
}
 void comerPretas()
{
    if(matriz[linOri][colOri] == 'B' & (matriz[linOri + 1][colOri + 1] == 'P' & matriz[linOri + 2][colOri + 2] == ' '))
    {
        if(matriz[linDes][colDes] == matriz[linOri + 2][colOri + 2])
        {
            matriz[linDes][colDes] = 'B';
            matriz[linOri][colOri] = ' ';
            matriz[linOri + 1][colOri + 1] = ' ';
            player -= 1;
        }
        else
        {
            printf("Voce deve comer a peca na linha %d, coluna %d !", (linOri + 1), (colOri + 1));
            moverPeca();
        }
    }
    else if(matriz[linOri][colOri] == 'B' & (matriz[linOri + 1][colOri - 1] == 'P' & matriz[linOri + 2][colOri - 2] == ' '))
    {
        if(matriz[linDes][colDes] == matriz[linOri + 2][colOri - 2])
        {
            matriz[linDes][colDes] = 'B';
            matriz[linOri][colOri] = ' ';
            matriz[linOri + 1][colOri - 1] = ' ';
            player -= 1;
        }
        else
        {
            printf("Voce deve comer a peca na linha %d, coluna %d !", (linOri + 1), (colOri - 1));
            moverPeca();
        }
    }
    else if(matriz[linOri][colOri] == 'B' & (matriz[linOri - 1][colOri - 1] == 'P' & matriz[linOri - 2][colOri - 2] == ' '))
    {
        if(matriz[linDes][colDes] == matriz[linOri - 2][colOri - 2])
        {
            matriz[linDes][colDes] = 'B';
            matriz[linOri][colOri] = ' ';
            matriz[linOri - 1][colOri- 1] = ' ';
            player -= 1;
        }
        else
        {
            printf("Voce deve comer a peca na linha %d, coluna %d !", (linOri - 1), (colOri- 1));
            moverPeca();
        }
    }
    else if(matriz[linOri][colOri] == 'B' & (matriz[linOri - 1][colOri + 1] == 'P' & matriz[linOri - 2][colOri + 2] == ' '))
    {
        if(matriz[linDes][colDes] == matriz[linOri - 2][colDes + 2])
        {
            matriz[linDes][colDes] = 'B';
            matriz[linOri][colOri] = ' ';
            matriz[linOri - 1][colOri + 1] = ' ';
            player -= 1;
        }
        else
        {
            printf("Voce deve comer a peca na linha %d, coluna %d !", (linOri - 1), (colOri + 1));
            moverPeca();
        }
    }
}

int verificarRegrasPretas()
{
    //Verificando movimentos das Peças PRETAS
    if (matriz[linOri][colOri] == 'P')
    {
        if(matriz[linDes][colDes] == ' ' & (matriz[linDes][colDes] == matriz[linOri + 1][colOri + 1]))
        {
            matriz[linDes][colDes] = 'P';
            matriz[linOri][colOri] = ' ';
            player += 1;
        }
        else if(matriz[linDes][colDes] == ' ' &(matriz[linDes][colDes] == matriz[linOri + 1][colOri - 1]))
        {
            matriz[linDes][colDes] = 'P';
            matriz[linOri][colOri] = ' ';
            player +=1;
        }
        else
        {
            printf("Voce tentou mover para um local invalido. Linha: %d | Coluna: %d \nTente novamente!", linDes, colDes);
            moverPeca();
        }
    }
    else
    {
            printf("Voce tentou mover a peca errada!\nLinha: %d | Coluna: %d | Peca: %c \nTente novamente!\n", linOri, colOri, matriz[linOri][colOri]);
            moverPeca();
    }
}
int verificarRegrasBrancas()
{
    if(matriz[linOri][colOri] == 'B')
    {
        if(matriz[linDes][colDes] == ' ' & (matriz[linDes][colDes] == matriz[linOri - 1][colOri - 1]))
        {
            matriz[linDes][colDes] = 'B';
            matriz[linOri][colOri] = ' ';
            player -= 1;
        }
        else if(matriz[linDes][colDes] == ' ' & (matriz[linDes][colDes] == matriz[linOri - 1][colOri + 1]))
        {
            matriz[linDes][colDes] = 'B';
            matriz[linOri][colOri] = ' ';
            player -=1;
        }
        else
        {
            printf("Voce tentou mover para um local invalido. Linha: %d | Coluna: %d \nTente novamente!", linDes, colDes);
            moverPeca();
        }
    }
    else
    {
        printf("Voce tentou mover a peca errada!\nLinha: %d | Coluna: %d | Peca: %c\nTente novamente!\n", linOri, colOri, matriz[linOri][colOri]);
        moverPeca();
    }
}


int moverPeca()
{

    //Recebendo Origem
    printf("\nQual Peca deseja mover?\nLinha: ");
    scanf("%d", &linOri);
    fflush(stdin);
    printf("Coluna: ");
    scanf("%d", &colOri);
    fflush(stdin);

    //Recebendo Destino
    printf("\nPara onde deseja mover?\nLinha: ");
    scanf("%d", &linDes);
    fflush(stdin);
    printf("Coluna: ");
    scanf("%d", &colDes);
    fflush(stdin);

    if(player == 1)
    {
        comerBrancas();
        verificarRegrasPretas();
    }
    else
    {
        comerPretas();
        verificarRegrasBrancas();
    }
}


int main(){
    int linOri, linDes, colOri, colDes;


        printf("Qual player ira comecar? \n1 -> PRETAS \n2 -> BRANCAS\n ");
    scanf(" %d", &player);

    if(player < 1 || player > 2)
    {
        printf("Por favor, escolha 1 ou 2! Pretas e Brancas respectivamente!");
    }

    while (vencer == 0)
    {
        system("CLS");
        pintarTelaTexto();
        if (player == 1)
        {
            printf("\nPRETAS\n");
        }
        else
        {
            printf("\nBRANCAS\n");
        }
        moverPeca();
        atualizarJogo();
    }
    /*while(1)  {

      pintarTelaTexto();
      moverPeca();
      printf("Informe a linha e coluna de origem: ");
      scanf("%d %d",&linOri, &colOri );
      printf("\nInforme a linha e coluna de destino: ");
      scanf("%d %d",&linDes, &colDes );
      int resultado = moverPeca(linOri, colOri, linDes, colDes);
      if( resultado != 1){
        switch( resultado ) {
            case 9:
                printf("\n ERRO: Pe�a n�o pode ser movida deste jeito!");
                getch();
                break;
            case 0:
                printf("\nERRO : Coordenadas inv�lidas!");
                getch();
                break;
            case 1:
                break;
        }
      }
    }*/

    getch();
    return 0;
}
