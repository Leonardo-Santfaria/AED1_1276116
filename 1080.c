#include <stdio.h>

typedef struct{
    int maior;
    int pos_maior;
}Mai;

Mai find_maior(int vet[], int range){
    Mai x;
    if(range == 1){
        x.maior = vet[0];
        x.pos_maior = 0;
        return x;
    }else{
        x = find_maior(vet, range-1);
        if(x.maior>vet[range-1]){
            return x;
        }else{
            x.maior = vet[range-1];
            x.pos_maior = range-1;
            return x;
        }
    }
    return x;
}

int main(){
    Mai m;
    int x[100];
    for(int i=0;i<100;i++){   
        scanf("%d", &x[i]);
    }
    m = find_maior(x, 100);
    printf("%d\n", m.maior);
    printf("%d\n", m.pos_maior+1);
}