#include <stdio.h>


void aplicar_habilidade(int tabuleiro[10][10], int matriz [5][5], int origem_linha, int origem_coluna){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++){
            int linha = origem_linha - 2 + i;
            int coluna = origem_coluna - 2 + j;
            if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10){
                if(matriz[i][j] == 1){
                    tabuleiro[linha][coluna] = 5;
                }
            }
        }
    }
}

int main() {
    // Representação das linhas do tabuleiro (letras A até J)
    char linha[10] = {'A', ' B', ' C', ' D', ' E', ' F', ' G', ' H', ' I', ' J'};

    // Tabuleiro 10x10 inicializado com água (valor 0)
    int tabuleiro[10][10] = {0};

    int navio_vertical[3]= {3, 3, 3};
    int navio_horizontal[3]= {3, 3, 3};
    int navio_diagonal[3]= {3, 3, 3};
    int cone[5][5] = {

        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };
   
    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    int linha_horizontal = 3, linha_vertical = 2;
    int coluna_horizontal = 4, coluna_vertical = 1;
    int linha_diagonal = 5, coluna_diagonal = 5;
    
   
    for (int i = 0; i < 3; i++){
        tabuleiro[linha_diagonal + i][coluna_diagonal + i] = navio_diagonal[i];
    }

    for (int i = 1; i < 3; i++){
       tabuleiro[linha_horizontal + i][linha_vertical] = navio_horizontal[i];
    }

    for (int i = 1; i < 3; i++){
       tabuleiro[coluna_horizontal][coluna_vertical + i] = navio_vertical[i];
    }

    aplicar_habilidade(tabuleiro, cone, 2, 2);
    aplicar_habilidade(tabuleiro, cruz, 5, 5);
    aplicar_habilidade(tabuleiro, octaedro, 8, 8);

    printf(" ");
    for (int i = 0; i < 10; i++) {
        printf("%2c", linha[i]);
        }
        printf("\n");

        for (int i = 0; i < 10; i++) {
            printf("%2d", i);
            for (int j = 0; j < 10; j++) {
                if (tabuleiro[i][j] == 0) printf(" 0"); // Água
                else if (tabuleiro[i][j] == 3) printf(" 3"); // Navio
                else if (tabuleiro[i][j] == 5) printf(" 1"); // Área afetada
            }
            printf("\n");
        }
    
        return 0;
    }