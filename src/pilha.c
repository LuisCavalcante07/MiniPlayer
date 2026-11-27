#include "pilha.h"
#include "lse.h"
#include <stddef.h>
struct pilha { 
    t_lse* lista;
    int altura; 
};
t_pilha *pilha_criar(void) { 
    t_pilha* nova = malloc(sizeof(t_pilha));
    nova->lista = lse_criar();
    nova->altura=0;

    return nova; 
}
int pilha_empilhar(t_pilha *p, void *c) { (void)p; (void)c; return 0; }
void *pilha_desempilhar(t_pilha *p) { (void)p; return NULL; }
void *pilha_topo(const t_pilha *p) { (void)p; return NULL; }

static bool pilha_vazia(t_pilha* p){
    return (p->altura == 0);
}

void pilha_destruir(t_pilha *p, t_pilha_destruir_carga destruir_carga) { 
    if (p==NULL) 
        return;
 
    // while(p->altura>0){
    //     void* carga = pilha_desempilhar(p);
    //     destruir_carga(carga);
    // }
    lse_destruir(p->lista, destruir_carga);
    p->altura=0;

    free(p);

}
