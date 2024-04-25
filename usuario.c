#include "usuario.h"

Usuario *criarUsuario(const char *nomeUsuario, const char *senha, const char *email) {
    Usuario *usuario = (Usuario *) malloc(sizeof(Usuario));
    strcpy(usuario->nomeUsuario, nomeUsuario);
    strcpy(usuario->senha, senha);
    strcpy(usuario->email, email);
    usuario->next = NULL;
    return usuario;
}

void inserirUsuario(Usuario **usuarios, Usuario *novoUsuario) {
    novoUsuario->next = *usuarios;
    *usuarios = novoUsuario;
}

void liberarUsuarios(Usuario *usuarios) {
    Usuario *proximoUsuario = NULL;
    while (usuarios != NULL) {
        proximoUsuario = usuarios->next;
        free(usuarios);
        usuarios = proximoUsuario;
    }
}

int carregarUsuariosArquivo(Usuario **usuarios) {
    FILE *arquivo = fopen("usuarios.txt", "r");
    if (arquivo == NULL) {
        return 0;
    }

    Usuario *ultimoUsuario = NULL;
    char nomeUsuario[20];
    char senha[20];
    char email[MAX_EMAIL_LENGTH];

    while (fscanf(arquivo, "%s %s %s", nomeUsuario, senha, email) == 3) {
        Usuario *novoUsuario = criarUsuario(nomeUsuario, senha, email);
        if (ultimoUsuario == NULL) {
            *usuarios = novoUsuario;
        } else {
            ultimoUsuario->next = novoUsuario;
        }
        ultimoUsuario = novoUsuario;
    }

    fclose(arquivo);
    return 1;
}

int salvarUsuariosArquivo(Usuario *usuarios) {
    FILE *arquivo = fopen("usuarios.txt", "w");
    if (arquivo == NULL) {
        return 0;
    }

    Usuario *usuarioAtual = usuarios;
    while (usuarioAtual != NULL) {
        fprintf(arquivo, "%s %s %s\n", usuarioAtual->nomeUsuario, usuarioAtual->senha, usuarioAtual->email);
        usuarioAtual = usuarioAtual->next;
    }

    fclose(arquivo);
    return 1;
}