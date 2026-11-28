#include <lse.h>
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
typedef struct elem {
    void *carga;
    struct elem *prox;
} t_elem;

struct lse {
    t_elem *inicio;
    int tamanho;
};
/* Stubs intencionalmente incompletos; testes devem falhar ate implementacao. */

t_elem* criar_elem_lse(void* carga) {
    t_elem* novo = malloc(sizeof(t_elem));

    if (novo == NULL) {
        return NULL;
    }

    novo->carga = carga;
    novo->prox = NULL;

    return novo;
}

t_lse *lse_criar(void){
    t_lse* nova = malloc(sizeof(t_lse));

    if (nova == NULL) {
        return NULL;
    }

    nova->inicio = NULL;
    nova->tamanho = 0;

    return nova;
}

int lse_tamanho(const t_lse *lista) {
    if (lista == NULL) {
        return 0;
    }

    return lista->tamanho;
}

/* M03 */
void *lse_primeiro(const t_lse *lista) {
    if (lista == NULL || lista->inicio == NULL) {
        return NULL;
    }

    return lista->inicio->carga;
}/* M03 */

int lse_inserir_inicio(t_lse *lista, void*carga){
    if (lista == NULL) {
        return 0;
    }

    t_elem* novo = criar_elem_lse(carga);

    if(novo==NULL){
        return 0;
    }

    if(lista->inicio==NULL){
        lista->inicio = novo;
    }else{
        novo->prox = lista->inicio;
        lista->inicio=novo;
    }
    lista->tamanho++;
    return 1;
} /* M04 */

int lse_inserir_fim(t_lse *lista, void *carga){
    if (lista == NULL) {
        return 0;
    }

    t_elem* novo = criar_elem_lse(carga);

    if (novo==NULL){
        return 0;
    }
        
    if (lista->inicio == NULL){
        lista->inicio = novo;
    }else{
        t_elem* cam = lista->inicio;
        while (cam->prox!=NULL){
            cam = cam->prox;
        }
        cam->prox = novo;
    }
    lista->tamanho++;
    return 1;
}/* TODO M04 */

void *lse_remover_inicio(t_lse *lista) {
    if (lista == NULL) {
        return NULL;
    }

    if (lista->tamanho == 0) {
        return NULL;
    }

    t_elem *prim = lista->inicio;
    lista->inicio = prim->prox;

    void *carga = prim->carga;
    free(prim);

    lista->tamanho--;
    return carga;
} /* TODO M04 */

void *lse_buscar(const t_lse *l, const void *key, t_lse_comparador cmp) { 
    if (l == NULL || cmp == NULL) {
        return NULL;
    }

    t_elem *cam = l->inicio;

    while(cam != NULL){
        if(cmp(cam->carga, key) == 0){
            return cam->carga;
        }

        cam = cam->prox;
    }
    return NULL;

 } /* TODO M04 */

void *lse_remover(t_lse *l, const void *key, t_lse_comparador cmp) { 
    if (l == NULL || cmp == NULL) {
        return NULL;
    }
    
    t_elem* atual = l->inicio;
    t_elem* anterior = NULL;

    while(atual != NULL){
        if(cmp(atual->carga, key) == 0){

            if(anterior == NULL){
                l->inicio = atual->prox;
            }else{
                anterior->prox = atual->prox;
            }

            void *carga = atual->carga;
            free(atual);
            l->tamanho--;
            return carga;
        }

        anterior = atual;
        atual = atual->prox;
    }

    return NULL;
 } /* TODO M04 */

int lse_inserir_ordenado(t_lse *lista, void *carga, t_lse_comparador comparar) { 
    if(lista == NULL || comparar == NULL){
        return 0;
    }

    t_elem *novo = criar_elem_lse(carga);
    if(novo == NULL){
        return 0;
    }

    t_elem *anterior = NULL;
    t_elem *atual = lista->inicio;

    while(atual != NULL && comparar(atual->carga, carga) <=0){
        anterior = atual;
        atual = atual->prox;
    }

    novo->prox = atual;

    if(anterior == NULL){
        lista->inicio = novo;
    }else{
        anterior->prox = novo;
    }

    lista->tamanho++;
    return 1;
 } 


void lse_destruir(t_lse* lista, void (*destruir_carga)(void* )) { 
    if (lista == NULL) {
        return;
    }

    t_elem *cam = lista->inicio;

    while(cam!=NULL){
        t_elem *prox = cam -> prox;
        if(destruir_carga != NULL){
            destruir_carga(cam->carga);
        }

        free(cam);
        cam = prox;
    }
    free(lista);
}

void lse_percorrer(const t_lse *lista, t_visitar cb_visitar) {
    if (lista == NULL || cb_visitar == NULL) {
        return;
    }

    t_elem *atual = lista->inicio;

    while (atual != NULL) {
        cb_visitar(atual->carga);
        atual = atual->prox;
    }
}