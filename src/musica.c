#include "musica.h"
#include "string.h"
#include "stdlib.h"
#include <stddef.h>
#include<stdio.h>
#include <assert.h>

t_musica *musica_criar(int id, const char *titulo, const char *artista, int duracao) {

    t_musica* nova = malloc(sizeof(t_musica)); 
    assert(nova != NULL);
    nova->id = id;
    strcpy(nova->titulo, titulo);
    strcpy(nova->artista, artista);
    nova->duracao = duracao;

    return nova; 
}

void musica_imprimir(const t_musica *musica) {
    assert(musica != NULL);

    printf("ID: %d\n", musica->id);
    printf("Titulo: %s\n", musica->titulo);
    printf("Artista: %s\n", musica->artista);
    printf("Duracao: %d segundos\n", musica->duracao);
}

void musica_destruir(void *carga) { 
/* TODO M01 */ 
    assert(carga!=NULL);
    free((t_musica*)carga);
}

