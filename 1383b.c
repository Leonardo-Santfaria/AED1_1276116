/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Leonardo Rafael dos Santos Faria
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383 - (com alocação dinâmica)
Data        : 02/09/2026
Objetivo    : Ler quantidade de sudokus de entradas, suas respectivas soluções e retornar quais resoluções de sudoku estão certas e quais estão erradas.
Dificuldade : Tive dificuldade em saber como adaptar os parâmetros de cada função.
Uso de IA   : --
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

int verify_horizontal_vertical(int**);
int verify_tre_per_tre(int**);

int main(){
    int n;
    scanf("%d", &n);
    int **sudokus, certin[n];
    sudokus = (int**) malloc(9*sizeof(int*));
    for(int i=0;i<9;i++){sudokus[i] = (int*) malloc(9*sizeof(int));}
    for (int num_sudokus = 0; num_sudokus < n; num_sudokus++){
        for (int row = 0; row < 9; row++){
            for (int col = 0; col < 9; col++){
                scanf("%d", &sudokus[row][col]);
            }
        }
        certin[num_sudokus] = verify_horizontal_vertical(sudokus) && verify_tre_per_tre(sudokus);
    }
    for (int num_sudokus = 0; num_sudokus < n; num_sudokus++){
        printf("Instancia %d\n", num_sudokus + 1);
        if (certin[num_sudokus] == 1){
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }
        printf("\n");
    }
    for(int i=0;i<9;i++){free(sudokus[i]);}
    free(sudokus);
}

int verify_horizontal_vertical(int **sudokus){
    for (int row = 0; row < 9; row++){
        int seen_row[10] = {0};
        int seen_col[10] = {0};
        for (int col = 0; col < 9; col++){
            int value_row = sudokus[row][col];
            int value_col = sudokus[col][row];
            if (seen_row[value_row] == 1){
                return 0;
            }
            if (seen_col[value_col] == 1){
                return 0;
            }
            seen_row[value_row] = 1;
            seen_col[value_col] = 1;
        }
    }
    return 1;
}

int verify_tre_per_tre(int **sudokus){
    int seen[10] = {0}, value;
    for (int row = 0; row < 9; row += 3){
        for (int col = 0; col < 9; col += 3){
            int seen[10] = {0};
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    value = sudokus[row + i][col + j];
                    if (seen[value] == 1){
                        return 0;
                    }
                    seen[value] = 1;
                }
            }
        }
    }
    return 1;
}
