
/* M02: testes adicionais da lista simplesmente encadeada. */
#include <assert.h>
#include <stdio.h>
#include "lse.h"

static void teste_lista_vazia(void) {
    t_lse *l = lse_criar();
    assert(l != NULL && "lse_criar deve retornar uma lista valida");
    assert(lse_tamanho(l) == 0);
    assert(lse_primeiro(l) == NULL);
    lse_destruir(l, NULL);
}

/* Verifica se consultar uma lista vazia e consistente */
static void teste_consultas_repetidas(void) {
    t_lse *l = lse_criar();
    assert(l != NULL);

    for (int i = 0; i < 5; i++) {
        assert(lse_tamanho(l) == 0);
        assert(lse_primeiro(l) == NULL);
    }

    lse_destruir(l, NULL);
}

/* Verifica se destruir uma lista nao afeta outra */
static void teste_destruicao_independente(void) {
    t_lse *lista1 = lse_criar();
    t_lse *lista2 = lse_criar();

    assert(lista1 != NULL);
    assert(lista2 != NULL);

    lse_destruir(lista1, NULL);

    assert(lse_tamanho(lista2) == 0);
    assert(lse_primeiro(lista2) == NULL);

    lse_destruir(lista2, NULL);
}

/* Verifica a criacao de uma nova lista apos destruir outra */
static void teste_recriacao_lista(void) {
    t_lse *l = lse_criar();
    assert(l != NULL);

    lse_destruir(l, NULL);

    l = lse_criar();
    assert(l != NULL);
    assert(lse_tamanho(l) == 0);
    assert(lse_primeiro(l) == NULL);

    lse_destruir(l, NULL);
}

int main(void) {
    teste_lista_vazia();
    teste_consultas_repetidas();
    teste_destruicao_independente();
    teste_recriacao_lista();

    puts("M02: Todos os testes passaram.");
    return 0;
}
