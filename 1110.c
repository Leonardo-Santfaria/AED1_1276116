/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Leonardo Rafael dos Santos Faria
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 03/09/2026
Objetivo    : entrar com um determinado numero para saber seu range, colocar em uma lista encadeada, 
discartar primeiro numero e colocar o numero seguinte no final da lista e mostrar números descartados
 e o número que sobrou
Dificuldade : Tive dificuldade com vazamento de memória causado pela não liberação das celulas da lista e
 formatação para a forma aceita pelo beecrowd
Uso de IA   : A IA me ajudou a entender como ajustar as partes do código para não haver vazamento de memória
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int number;
    struct celula *next;
}cel;

void insert_card(int, cel*);
int remove_card(cel*);
int first_to_end(cel*);

int main(){
    int number_cards;
    cel *pile_cards;
    while(1)
    {
        scanf("%d", &number_cards);
        if(number_cards == 0) return 0;

        pile_cards = malloc(sizeof(cel));
        pile_cards->next = NULL;
        for(int n = number_cards; n >= 1; n--)
        {
            insert_card(n, pile_cards);
        }
        printf("Discarded cards:");
        int first = 1;
        while(pile_cards->next != NULL && pile_cards->next->next != NULL)
        {
            if(!first)
            {
                printf(",");
            }
            printf(" %d", first_to_end(pile_cards));
            first = 0;
        }
        printf("\n");
        if(number_cards != 1)
        {
            printf("Remaining card: %d\n", pile_cards->next->number);
        }else
        {
            printf("Remaining card: 1\n");
        }
        while(remove_card(pile_cards));
        free(pile_cards);
    }
}

void insert_card(int new_number, cel*head)
{
    cel *new;
    new = malloc(sizeof(cel));
    new->number = new_number;
    new->next = head->next;
    head->next = new;
}

int remove_card(cel*head){
    if(head->next == NULL) return 0;
    cel *trash;
    trash = head->next;
    head->next = trash->next;
    free(trash);
    return 1;
}

int first_to_end(cel*head)
{
    cel *first, *last_cel;
    int num_discarded = head->next->number;
    remove_card(head);
    if(head->next == NULL) return num_discarded;

    first = head->next;
    if(first->next == NULL) return num_discarded;
    head->next = first->next;
    last_cel = head->next;
    while(last_cel->next != NULL)
    {
        last_cel = last_cel->next;
    }
    
    last_cel->next = first;
    first->next = NULL;
    return num_discarded;
}