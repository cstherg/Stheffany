#define PEDIDO_H
#define PEDIDO_H

#ifndef PEDIDO_H
#define PEDIDO_H

typedef struct order_tag {
    int id;
    int numero;
    char status[50];
    struct order_tag *proximo;
    struct order_tag *anterior;
} Pedido;

Pedido *criarPedido(int id, int numero, const char *status);
void inserirPedido(Pedido **pedidos, Pedido *novoPedido);
void removerPedido(Pedido **pedidos, Pedido *pedidoARemover);
void liberarPedidos(Pedido *pedidos);
void inicializarPedidos(Pedido **pedidos, int tamanho);
void imprimirPedidos(Pedido *pedidos);
void ordenarPedidos(Pedido **pedidos);

#endif // PEDIDO_H