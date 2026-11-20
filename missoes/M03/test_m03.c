/* Testes aditivos da M03. Executar a partir da raiz com o Makefile incremental. */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "lse.h"

static int *esperados[3];
static int visitas = 0;
static int destruicoes = 0;

static void verificar_ordem(void *carga) {
    assert(visitas < 3);
    assert(carga = esperados[visitas]);
    visitas++;
}

static void destruir_int(void *carga) {
    assert(carga != NULL);
    destruicoes++;
    free(carga);
}


static void teste_lista_vazia(void) {
    t_lse *l = lse_criar();

    assert(l != NULL);
    assert(lse_tamanho(l) == 0);
    assert(lse_primeiro(l) == NULL);

    lse_destruir(l, NULL);
}
static void teste_encadeamento_e_percurso(void) {
  int a =10, b =20, c = 30;

  t_lse *l = lse_criar();
  assert(l != NULL);

    assert(lse_inserir_inicio(l, &a) == 1);
    assert(lse_inserir_inicio(l, &b) == 1);
    assert(lse_inserir_inicio(l, &c) == 1);

    assert(lse_tamanho(l) == 3);
    assert(lse_primeiro(l) == &c);

    esperados[0] = &c;
    esperados[1] = &b;
    esperados[2] = &a;

    visitas = 0;
    lse_percorrer(l, verificar_ordem);

    assert(visitas == 3);

    lse_destruir(l, NULL); 
}

static void teste_carga_generica(void) {
  typedef struct{
    int id;
    char titulo[30];
  } t_musica;

  t_musica a = {1, "Musica A"};
  t_musica b = {2, "Musica B"};

  t_lse *l = lse_criar();
  assert(l != NULL);

  assert(lse_inserir_inicio(l, &a) == 1);
  assert(lse_inserir_inicio(l, &b) == 1);

  assert(lse_tamanho(l) == 2);
  assert(lse_primeiro(l) == &b);
  lse_destruir(l, NULL);
  
}

static void teste_destruicao_com_callback(void) {
    t_lse *l = lse_criar();
    assert(l != NULL);

    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));

    assert(a != NULL);
    assert(b != NULL);

    *a = 10;
    *b = 20;

    assert(lse_inserir_inicio(l, a) == 1);
    assert(lse_inserir_inicio(l, b) == 1);

    assert(lse_tamanho(l) == 2);

    destruicoes = 0;

    lse_destruir(l, destruir_int);

    assert(destruicoes == 2);
}

int main(void) {
    teste_lista_vazia();
    teste_encadeamento_e_percurso();
    teste_carga_generica();
    teste_destruicao_com_callback();
    assert(lse_inserir_inicio(NULL, NULL) == 0);
    puts("M03: todos os testes passaram.");
    return 0;
}
