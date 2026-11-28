/* Testes incrementais M05 — não acessar campos privados de t_lse/t_elem. */
#include <assert.h>
#include <stdio.h>
#include "lse.h"

static int comparar_int(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y); //se x > y return = 1 se y > x return = - 1
}

typedef struct { 
    int id; 
    const char *titulo; 
} musica_t;

static int comparar_musica(const void *a, const void *b) {
    int x = ((const musica_t *)a)->id, y = ((const musica_t *)b)->id;
    return (x > y) - (x < y);
}


static void *esperados[4];
static int visitas = 0;
static int  quantidade_esperada = 0;

static void verificar_ordem(void *carga) {
    assert(visitas < quantidade_esperada);
    assert(carga == esperados[visitas]);
    visitas++;
}


static void teste_vazia_inicio_meio_fim(void) {
    t_lse *l = lse_criar(); 
    assert(l);
    
    int a = 20;
    int b = 10;
    int c = 40;
    int d = 30;

    assert(lse_tamanho(l) == 0);

    assert(lse_inserir_ordenado(l, &a, comparar_int) == 1); // Lista vazia
    assert(lse_tamanho(l) == 1);
    assert(lse_primeiro(l) == &a); 

    assert(lse_inserir_ordenado(l, &b, comparar_int) == 1); // Inserir inicio
    assert(lse_tamanho(l) == 2);
    assert(lse_primeiro(l) == &b);

    assert(lse_inserir_ordenado(l, &c, comparar_int) == 1); // Inserir fim
    assert(lse_tamanho(l) == 3);

    esperados[0] = &b;
    esperados[1] = &a;
    esperados[2] = &c;
    visitas = 0;
    quantidade_esperada = 3;
    lse_percorrer(l, verificar_ordem);
    assert(visitas == quantidade_esperada);

    assert(lse_inserir_ordenado(l, &d, comparar_int) == 1); // Inserir meio
    assert(lse_tamanho(l) == 4);

    esperados[0] = &b;
    esperados[1] = &a;
    esperados[2] = &d;
    esperados[3] = &c;
    visitas = 0;
    quantidade_esperada = 4;
    lse_percorrer(l, verificar_ordem);
    assert(visitas == quantidade_esperada);


    lse_destruir(l,NULL);
}

static void teste_duplicados_estaveis(void) {
    musica_t a={10,"primeira"}, b={10,"segunda"}, c={5,"menor"}, d={10,"terceira"};
    t_lse *l=lse_criar(); 
    assert(l);

    assert(lse_inserir_ordenado(l, &a, comparar_musica) == 1);
    assert(lse_tamanho(l) == 1);
    assert(lse_primeiro(l) == &a);

    assert(lse_inserir_ordenado(l, &b, comparar_musica) == 1);
    assert(lse_tamanho(l) == 2);
    esperados[0] = &a;
    esperados[1] = &b;
    visitas = 0; 
    quantidade_esperada = 2;
    lse_percorrer(l, verificar_ordem);
    assert(visitas == quantidade_esperada);

    assert(lse_inserir_ordenado(l, &c, comparar_musica) == 1);
    assert(lse_tamanho(l) == 3);
    esperados[0] = &c;
    esperados[1] = &a;
    esperados[2] = &b;
    visitas = 0;
    quantidade_esperada = 3;
    lse_percorrer(l, verificar_ordem);
    assert(visitas == quantidade_esperada);

    assert(lse_inserir_ordenado(l, &d, comparar_musica) == 1);
    assert(lse_tamanho(l) == 4);
    esperados[0] = &c;
    esperados[1] = &a;
    esperados[2] = &b;
    esperados[3] = &d;
    visitas = 0;
    quantidade_esperada = 4;
    lse_percorrer(l, verificar_ordem);
    assert(visitas == quantidade_esperada);

 
    lse_destruir(l,NULL);
}

static void teste_invalido_e_reinsercao(void) {
    t_lse *l = lse_criar();
    assert(l);
    int a = 20;
    int b = 10;

    assert(lse_inserir_ordenado(l, &a, comparar_int) == 1);
    assert(lse_tamanho(l) == 1);
    assert(lse_primeiro(l) == &a);

    assert(lse_inserir_ordenado(NULL, &a, comparar_int) == 0); //Passando uma lisat nula
    assert(lse_tamanho(l) == 1);
    assert(lse_primeiro(l) == &a);

    assert(lse_inserir_ordenado(l, &a, NULL) == 0); //passando um comaprador nulo
    assert(lse_tamanho(l) == 1);
    assert(lse_primeiro(l) == &a);

    assert(lse_inserir_ordenado(l, &b, comparar_int) == 1);
    assert(lse_tamanho(l) == 2);

    esperados[0] = &b;
    esperados[1] = &a;
    visitas = 0;
    quantidade_esperada = 2;

    lse_percorrer(l, verificar_ordem);

    assert(visitas == quantidade_esperada);
    lse_destruir(l, NULL);

}

int main(void) {
    teste_vazia_inicio_meio_fim();
    teste_duplicados_estaveis();
    teste_invalido_e_reinsercao();
    puts("M05: todos os testes passaram.");
    return 0;
}
