#include <stdio.h>
#include <stdlib.h>


#define WIDTH 640
#define HEIGHT 480


char xadrez[8][8] = {
    { 'B', ' ', 'B', ' ', 'B', ' ', 'B', ' ' },
    { ' ', 'B', ' ', 'B', ' ', 'B', ' ', 'B' },
    { 'B', ' ', 'B', ' ', 'B', ' ', 'B', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { 'P', ' ', 'P', ' ', 'P', ' ', 'P', ' ' },
    { ' ', 'P', ' ', 'P', ' ', 'P', ' ', 'P' },
    { 'P', ' ', 'P', ' ', 'P', ' ', 'P', ' ' }


};








int pintarTelaTexto(){
    system("CLS");
    int lin, col, r;
    for(lin = 0; lin < 8; lin++){
        for(r = 0; r < 3; r++){
            for(col = 0; col < 8; col++){
                char peca = xadrez[lin][col];
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

int moverPeca( int linOri, int colOri, int linDes, int colDes) {
    int mover = 0;
    char peca;
    int dV = abs(linDes - linOri);
    int dH = abs (colDes - colOri);
    if((linOri >= 0 && linOri <= 8 && colOri >= 0 && colOri <= 8 ) &&
       (linDes >= 0 && linDes <= 8 && colDes >= 0 && colDes <= 8 )){
       peca = xadrez[linOri][colOri];


        if((peca == 'P' || peca == 'B') &&
           ((dV >= 0 && dV <=1) && (dH >=0 && dH <=1))){
            mover = 1;
       }




        if(mover){
        xadrez[linDes][colDes] = xadrez[linOri][colOri];
        xadrez[linOri][colOri] = ' ';
        return 1;//movimento realizado
        }else{
        return 9;//pe�a n�o pode ser movida deste jeito
        }
    }else{
        return 0;
    }

}

int main(){

    int linOri, linDes, colOri, colDes;
    while(1)  {

      pintarTelaTexto();
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
    }

    getch();
    return 0;
}
