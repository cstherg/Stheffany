#include "pedido.h"

int pedido;
Pedido *criarPedido(int numeroPedido, const char *status) {
    Pedido *pedido = (Pedido *) malloc(sizeof(Pedido));
    pedido->numeroPedido = numeroPedido;
    strcpy(pedido->status, status);
    pedido->anterior = NULL;
    pedido->next = NULL;
    return pedido;
}

void inserirPedido(Pedido **pedidos, Pedido *novoPedido) {
    novoPedido->next = *pedidos;
    novoPedido->anterior = NULL;
    if (*pedidos != NULL) {
        (*pedidos)->anterior = novoPedido;
    }
    *pedidos = novoPedido;
}

void removerPedido(Pedido **pedidos, Pedido *pedidoARemover) {
    if (*pedidos == pedidoARemover) {
        *pedidos = pedidoARemover->next;
        if (*pedidos != NULL) {
            (*pedidos)->anterior = NULL;
        }
    } else {
        Pedido *atual = *pedidos;
        while (atual != NULL && atual->next != pedidoARemover) {
            atual = atual->next;
        }
        if (atual != NULL) {
            atual->next = pedidoARemover->next;
            if (atual->next != NULL) {
                atual->next->anterior = atual;
            }
        }
    }
    free(pedidoARemover);
}

void ordenarPedidos(Pedido **pedidos) {
    Pedido *atual = *pedidos;
    Pedido *menor = atual;
    Pedido *anterior = NULL;

    while (atual != NULL) {
        menor = atual;
        anterior = atual;

        Pedido *proximo = atual->next;
        while (proximo != NULL) {
            if (proximo->numeroPedido < menor->numeroPedido) {
                menor = proximo;
                anterior = proximo->anterior;
           }
            proximo = proximo->next;
        }

        if (anterior != menor) {
            if (anterior != NULL) {
                anterior->next = menor->next;
            } else {
                *pedidos = menor->next;
            }

            menor->anterior = anterior;
            menor->next = atual;
            atual->anterior = menor;

            if (menor->anterior != NULL) {
                menor->anterior->next = menor;
            }
            if (atual->next != NULL) {
                atual->next->anterior = atual;
            }
        }

        atual = atual->next;
    }
}