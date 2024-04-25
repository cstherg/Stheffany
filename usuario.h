#define USUARIO_H
#define USUARIO_H

typedef struct user_tag {
    int id;
    char nome[50];
    char email[100];
    struct user_tag *proximo;
} Usuario;

Usuario *criarUsuario(int id, const char *nome, const char *email);
void inserirUsuario(Usuario **usuarios, Usuario *novoUsuario);
void removerUsuario(Usuario **usuarios, Usuario *usuarioARemover);
void liberarUsuarios(Usuario *usuarios);
void inicializarUsuarios(Usuario **usuarios, int tamanho);

#endif // USUARIO_H