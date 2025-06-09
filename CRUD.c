#include <stdio.h>
#include <string.h>

#define MAX_PESSOAS 100

typedef struct {
    int id;
    char nome[50];
    int idade;
    int ativo; // 1 = ativo, 0 = excluído
} Pessoa;

Pessoa lista[MAX_PESSOAS];
int count = 0;

void criar() {
    if (count >= MAX_PESSOAS) {
        printf("Limite de cadastro atingido!\n");
        return;
    }

    Pessoa p;
    p.id = (count == 0) ? 1 : lista[count - 1].id + 1;
    printf("Digite o nome: ");
    scanf(" %[^\n]", p.nome);
    printf("Digite a idade: ");
    scanf("%d", &p.idade);
    p.ativo = 1;

    lista[count++] = p;

    printf("Pessoa cadastrada com ID %d\n", p.id);
}

void listar() {
    printf("\nLista de Pessoas:\n");
    for (int i = 0; i < count; i++) {
        if (lista[i].ativo) {
            printf("ID: %d, Nome: %s, Idade: %d\n", lista[i].id, lista[i].nome, lista[i].idade);
        }
    }
}

int buscarPorId(int id) {
    for (int i = 0; i < count; i++) {
        if (lista[i].id == id && lista[i].ativo) {
            return i;
        }
    }
    return -1;
}

void atualizar() {
    int id;
    printf("Digite o ID da pessoa que deseja atualizar: ");
    scanf("%d", &id);

    int pos = buscarPorId(id);
    if (pos == -1) {
        printf("Pessoa com ID %d não encontrada.\n", id);
        return;
    }

    printf("Novo nome: ");
    scanf(" %[^\n]", lista[pos].nome);
    printf("Nova idade: ");
    scanf("%d", &lista[pos].idade);

    printf("Pessoa atualizada com sucesso!\n");
}

void deletar() {
    int id;
    printf("Digite o ID da pessoa que deseja deletar: ");
    scanf("%d", &id);

    int pos = buscarPorId(id);
    if (pos == -1) {
        printf("Pessoa com ID %d não encontrada.\n", id);
        return;
    }

    lista[pos].ativo = 0;
    printf("Pessoa deletada com sucesso!\n");
}

int main() {
    int opcao;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Cadastrar pessoa\n");
        printf("2. Listar pessoas\n");
        printf("3. Atualizar pessoa\n");
        printf("4. Deletar pessoa\n");
        printf("0. Sair\n");
        printf("Escolha a opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criar();
                break;
            case 2:
                listar();
                break;
            case 3:
                atualizar();
                break;
            case 4:
                deletar();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
