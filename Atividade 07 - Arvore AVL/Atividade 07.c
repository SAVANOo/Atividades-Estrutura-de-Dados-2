#include <stdio.h>
#include <stdlib.h>

typedef struct SArvore
{
    struct SArvore *esq;
    int dado;
    struct SArvore *dir;
    int altura; // Adicionamos a altura ao nó
} TArvore;

TArvore *raiz;

// Função para obter a altura de um nó
int altura(TArvore *no)
{
    if (no == NULL)
        return 0;
    return no->altura;
}

// Função para obter o máximo de dois inteiros
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Cria um novo nó com uma dada informação
TArvore *novoNo(int informacao)
{
    TArvore *novo = malloc(sizeof(TArvore));
    novo->dado = informacao;
    novo->esq = novo->dir = NULL;
    novo->altura = 1; // A nova árvore tem altura 1
    return novo;
}

// Rotação à direita
TArvore *rotacaoDireita(TArvore *y)
{
    TArvore *x = y->esq;
    TArvore *T2 = x->dir;

    // Realiza a rotação
    x->dir = y;
    y->esq = T2;

    // Atualiza alturas
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;

    // Retorna o novo nó raiz
    return x;
}

// Rotação à esquerda
TArvore *rotacaoEsquerda(TArvore *x)
{
    TArvore *y = x->dir;
    TArvore *T2 = y->esq;

    // Realiza a rotação
    y->esq = x;
    x->dir = T2;

    // Atualiza alturas
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;

    // Retorna o novo nó raiz
    return y;
}

// Obtém o fator de balanceamento de um nó
int fatorBalanceamento(TArvore *no)
{
    if (no == NULL)
        return 0;
    return altura(no->esq) - altura(no->dir);
}

// Insere um nó na árvore AVL
TArvore *inserirNo(TArvore *no, int informacao)
{
    // Performa a inserção normal de BST
    if (no == NULL)
        return novoNo(informacao);

    if (informacao < no->dado)
        no->esq = inserirNo(no->esq, informacao);
    else if (informacao > no->dado)
        no->dir = inserirNo(no->dir, informacao);
    else // Chaves iguais não são permitidas
        return no;

    // Atualiza a altura do nó atual
    no->altura = 1 + max(altura(no->esq), altura(no->dir));

    // Obtém o fator de balanceamento do nó para verificar se houve desbalanceamento
    int balance = fatorBalanceamento(no);

    // Caso de desbalanceamento, há 4 casos possíveis

    // Caso Esquerda-Esquerda
    if (balance > 1 && informacao < no->esq->dado)
        return rotacaoDireita(no);

    // Caso Direita-Direita
    if (balance < -1 && informacao > no->dir->dado)
        return rotacaoEsquerda(no);

    // Caso Esquerda-Direita
    if (balance > 1 && informacao > no->esq->dado)
    {
        no->esq = rotacaoEsquerda(no->esq);
        return rotacaoDireita(no);
    }

    // Caso Direita-Esquerda
    if (balance < -1 && informacao < no->dir->dado)
    {
        no->dir = rotacaoDireita(no->dir);
        return rotacaoEsquerda(no);
    }

    // Nenhum caso de rotação é necessário, retorna o nó sem alterações
    return no;
}

// Função para percorrer a árvore em ordem
void emOrdem(TArvore *no)
{
    if (no == NULL)
        return;

    emOrdem(no->esq);
    printf("%d ", no->dado);
    emOrdem(no->dir);
}

int main()
{
    int valor;
    raiz = NULL;

    printf("Digite um numero para a raiz: ");
    scanf("%d", &valor);
    raiz = inserirNo(raiz, valor);

    while (1)
    {
        printf("Digite um numero: ");
        scanf("%d", &valor);

        if (valor == 0)
            break;

        raiz = inserirNo(raiz, valor);
    }

    printf("\nÁrvore AVL em ordem: ");
    emOrdem(raiz);
    printf("\n");

    return 0;
}
