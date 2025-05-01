#include <stdio.h>
#define LINHAS 10
#define COLUNAS 10


int main (){

  // Letras para o cabeçalho do tabuleiro (colunas de A a J)
   char letras[10] = {'A','B','C','D','E','F','G','H','I','J'};

   // Inicialização do tabuleiro 10x10 tudo em zeros 
   int tabuleiro[LINHAS][COLUNAS] = {0};

   int hab[LINHAS][COLUNAS] = {0};
   //POSICONAMENTO DOS NAVIOS

       //posição inicial para navio
       //começa na linha 5 e coluna H (índices 4 e 7)
       int linhax = 4, colunax = 7 ;
    
       // Verifica se o navio vertical de tamanho 3 cabe no tabuleiro (sem ultrapassar os limites)
       if (linhax + 2 < 10){ 
       // Posiciona o navio verticalmente (mesma coluna, linhas diferentes)
       for (int i = 0; i < 3; i++){
         tabuleiro[linhax + i][colunax] = 3;
         }
       }

       //posição inicial para navio
       //começa na linha 3 e coluna D (índices 2 e 3)
       int linhay = 2 , colunay = 3;

       // Posiciona o navio horizontalmente (mesma linha, colunas diferentes)
       tabuleiro[linhay][colunay] = 3;
       tabuleiro[linhay][colunay + 1] = 3;
       tabuleiro[linhay][colunay + 2] = 3;
      
      // Loop para posicionamento adicional de navio
       for(int i = 0; i < 3; i++){
      // Coloca parte de navio na diagonal na linha 8 coluna D (índices 7, 3)
        tabuleiro[7 + i][3 + i] = 3;
      //posicionamento de navio na diagonal secundária linha 8 coluna A (índices 7, 2)
        tabuleiro[7 + i][2 - i] = 3;
    }

    for(int i = 0; i < 3; i++){
      for ( int j = -i; j <= i; j++){
        hab[5 + i][2 + j] = 1;
      }
    }

    for(int i = -1; i <= 1; i++){
        hab[1 + i][3] = 2;
        hab[3 + i][3] = 2;
        hab[2][4 + i] = 2;
        hab[2][2 - i] = 2;
    }

     for(int i = 0; i < 3; i++){
     for ( int j = -i; j <= i; j++){
      hab[2 + i][7 + j] = 4;
      hab[6 - i][7 + j] = 4;
     }
    }

  // Imprimir do Tabuleiro
   printf("##### TABULEIRO NÁVIOS ##### %35s\n" , "##### TABULEIRO HABILIDADES #####");
  // Imprime o cabeçalho com as letras das colunas
   printf("     ");
   for(int i = 0; i < 10; i++)
   {
 printf("%2c", letras[i]);
   }

  printf("%13s","");

   for(int i = 0; i < 10; i++){
    printf("%2c", letras[i]);
   }
   printf("\n");
  // Imprime cada linha do tabuleiro com os números das linhas
   for(int i = 0; i < 10; i++)
   {
    printf("   ");
  // Número da linha (de 1 a 10)
   printf("%2d " , i + 1 );

  // Conteúdo da linha (valores da matriz são 0 e 3 são partes do navio)
   for(int j = 0; j < 10; j++)
   { 
   printf("%d ", tabuleiro[i][j]);
   } 
   printf("          ");

   printf("%2d ", i + 1);

   for(int j = 0; j < 10; j++){
    printf("%d " , hab[i][j]);
     }
     printf("\n");
   }

 return 0; // Programa finalizado
}

