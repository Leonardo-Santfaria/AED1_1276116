/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Leonardo Rafael dos Santos Faria
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1180
Data        : 02/09/2026
Objetivo    : Ler quantidade de entradas, seus respectivos valores e retornar o menor número e sua posição
Dificuldade : --
Uso de IA   : --
-------------------------------------------------------------------------- */

#include <stdio.h>

typedef struct{
    int minor;
    int pos_minor;
}Mino;

Mino find_minor(int vet[], int range){
    Mino x;
    if(range == 1){
        x.minor = vet[0];
        x.pos_minor = 0;
        return x;
    }else{
        x = find_minor(vet, range-1);
        if(x.minor<vet[range-1]){
            return x;
        }else{
            x.minor = vet[range-1];
            x.pos_minor = range-1;
            return x;
        }
    }
    return x;
}

int main(){
    int n;
    Mino m;
    do{ scanf("%d", &n);    }while(n<=1||n>=1000);
    int x[n];
    for(int i=0;i<n;i++){   scanf("%d", &x[i]);}
    m = find_minor(x, n);
    printf("Menor valor: %d\n", m.minor);
    printf("Posicao: %d\n", m.pos_minor);
}
