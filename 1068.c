/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Leonardo Rafael dos Santos Faria
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 02/09/2026
Objetivo    : Ler expressões e verificar se a quantidade e a distribuição dos parenteses está correta
Dificuldade : Houve dificuldade para a implementação da lógica na verificação da pilha com os parenteses da expressão
Uso de IA   : a IA me auxiliou para a correção do meu empilhamento e variáveis desecessárias que eu havia criado
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct celula{
    char value;
    struct celula *next;
}cel;

int verify_expression(char[]);
void pile(char, cel*);
int unpile(cel*);
void free_pile(cel*);
int main()
{
    char expression[1002];
    int iscorrect;
    while(fgets(expression, sizeof(expression), stdin) != NULL)
    {
        expression[strcspn(expression, "\n")] = '\0';
        iscorrect = verify_expression(expression);
        if(iscorrect)
        {
            printf("correct\n");
        }else{
            printf("incorrect\n");
        }
    }
}
int verify_expression(char expr[])
{
    cel stack;
    stack.next = NULL;
    int result;
    for(int i=0;expr[i]!='\0';i++)
    { 
        if (expr[i] == '(') {
            pile('(', &stack);
        } 
        else if (expr[i] == ')') 
        {
            if (!unpile(&stack)) 
            {
                free_pile(&stack);
                return 0; 
            }
        }
    }
    if(stack.next == NULL){result=1;}else{result=0;}
    free_pile(&stack);
    return result;
}

void pile(char value, cel *head)
{
    cel *new;
    new = malloc(sizeof(cel));
    new->value = value;
    new->next = head->next;
    head->next = new;
}
int unpile(cel *head)
{
    if (head->next == NULL) return 0;
    cel *q = head->next;
    head->next = q->next;
    free(q);
    return 1;
}
void free_pile(cel *head) 
{
    while (head->next != NULL) 
    {
        unpile(head);
    }
}