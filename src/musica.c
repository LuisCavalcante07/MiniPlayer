#include "musica.h"
#include "string.h"
#include "stdlib.h"
#include <stddef.h>
#include <assert.h>
/* M01: substituir stubs por alocacao, copia segura de strings e free. */

t_musica *musica_criar(int id, const char *titulo, const char *artista, int duracao) {

    t_musica* nova = malloc(sizeof(t_musica)); //alocacao de memoria dinamia(cria variavel anonima em tempo de execucao)

    nova->id = id;
    strcpy(nova->titulo, titulo);
    strcpy(nova->artista, artista);
    nova->duracao = duracao;

    return nova; 
}

void musica_destruir(void *carga) { 
/* TODO M01 */ 
    assert(carga!=NULL);
    free((t_musica*)carga);


}

