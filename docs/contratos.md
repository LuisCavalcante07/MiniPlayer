# Contratos dos TADs
Para **cada função**, preencher:
- Nome e assinatura:
- Pré-condições:
- Pós-condições:
- Valor de retorno em sucesso/falha:
- Quem aloca/libera a memória:
- Invariantes preservadas:
- Testes associados:

## Invariantes da LSE
- `tamanho >= 0`.
- `tamanho == 0` se e somente se `inicio == NULL`.
- Há exatamente `tamanho` nós alcançáveis a partir de `inicio`.
- O último nó aponta para `NULL` e não há ciclos.

## M02

### lse_criar
- Nome e assinatura: `t_lse *lse_criar(void)`
- Pré-condições: nenhuma.
- Pós-condições: existe uma lista vazia (`inicio == NULL`, `tamanho == 0`).
- Valor de retorno em sucesso/falha: ponteiro para a lista; `NULL` se o `malloc` falhar.
- Quem aloca/libera a memória: a função aloca; quem chamou libera com `lse_destruir`.
- Invariantes preservadas: `tamanho == 0` se e somente se `inicio == NULL`.
- Testes associados: `missoes/M02/TESTE_INCREMENTAL_M02.c` (`teste_lista_vazia`).

### lse_tamanho
- Nome e assinatura: `int lse_tamanho(const t_lse *lista)`
- Pré-condições: lista criada por `lse_criar` (ou `NULL`).
- Pós-condições: a lista não é alterada.
- Valor de retorno em sucesso/falha: número de elementos; 0 para lista recém-criada. [Decisão: 0 também para lista `NULL`.]
- Quem aloca/libera a memória: ninguém.
- Invariantes preservadas: todas (só leitura).
- Testes associados: `TESTE_INCREMENTAL_M02.c` (`lse_tamanho(l) == 0`).

### lse_primeiro
- Nome e assinatura: `void *lse_primeiro(const t_lse *lista)`
- Pré-condições: lista criada por `lse_criar` (ou `NULL`).
- Pós-condições: a lista não é alterada; o elemento não é removido.
- Valor de retorno em sucesso/falha: carga do primeiro nó; `NULL` se a lista estiver vazia.
- Quem aloca/libera a memória: ninguém; a carga continua pertencendo a quem a criou.
- Invariantes preservadas: todas (só leitura).
- Testes associados: `TESTE_INCREMENTAL_M02.c` (`lse_primeiro(l) == NULL`).

### lse_destruir
- Nome e assinatura: `void lse_destruir(t_lse *lista, void (*destruir_carga)(void *))`
- Pré-condições: lista criada por `lse_criar`; não pode ser usada depois da chamada.
- Pós-condições: a memória da lista e dos nós é liberada; as cargas só são liberadas se `destruir_carga != NULL`.
- Valor de retorno em sucesso/falha: não retorna valor.
- Quem aloca/libera a memória: a função libera a lista e os nós; as cargas são de quem as criou.
- Invariantes preservadas: não se aplica (a lista deixa de existir).
- Testes associados: `TESTE_INCREMENTAL_M02.c` (chamada final do teste).
