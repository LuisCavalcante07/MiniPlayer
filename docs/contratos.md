# Contratos dos TADs — MiniPlayer

**Escopo:** operações da lista simplesmente encadeada (LSE) desenvolvidas e testadas até a missão M04. Os contratos iniciais foram trabalhados na M02, a estrutura e suas operações básicas foram desenvolvidas na M03, e as operações adicionais de inserção, busca e remoção foram implementadas na M04.

## 1. Invariantes da LSE

- `tamanho >= 0`.
- `tamanho == 0` se, e somente se, `inicio == NULL`.
- Existem exatamente `tamanho` nós alcançáveis a partir de `inicio`.
- O último nó aponta para `NULL`, sem ciclos.
- Uma inserção bem-sucedida aumenta `tamanho` em uma unidade.
- Uma remoção bem-sucedida diminui `tamanho` em uma unidade.
- Consultas não modificam a estrutura da lista.

A LSE é representada internamente por uma estrutura `t_lse`, que contém o ponteiro `inicio` e o campo `tamanho`. Cada nó (`t_elem`) armazena uma carga genérica (`void *`) e um ponteiro para o próximo nó.

## 2. Contratos básicos — M02/M03

### `lse_criar`

- **Assinatura:** `t_lse *lse_criar(void)`.
- **Pré-condições:** nenhuma.
- **Pós-condições:** em caso de sucesso, cria uma lista vazia, com `inicio == NULL` e `tamanho == 0`.
- **Retorno:** ponteiro para a lista criada; `NULL` se a alocação falhar.
- **Memória:** aloca a estrutura da lista, que posteriormente deve ser liberada por `lse_destruir`.
- **Invariantes:** estabelecidas na criação.
- **Testes associados:** M02 e M03, criação de listas e verificação do estado inicial.

### `lse_tamanho`

- **Assinatura:** `int lse_tamanho(const t_lse *lista)`.
- **Pré-condições:** recebe uma lista válida ou `NULL`.
- **Pós-condições:** a lista permanece inalterada.
- **Retorno:** quantidade de elementos armazenados; `0` caso a lista seja `NULL`.
- **Memória:** não realiza alocações nem liberações.
- **Invariantes:** preservadas por se tratar de consulta.
- **Testes associados:** M02, M03 e M04, verificações de tamanho antes e depois das operações.

### `lse_primeiro`

- **Assinatura:** `void *lse_primeiro(const t_lse *lista)`.
- **Pré-condições:** recebe uma lista válida ou `NULL`.
- **Pós-condições:** a lista permanece inalterada e nenhum elemento é removido.
- **Retorno:** ponteiro para a carga do primeiro nó; `NULL` se a lista for vazia, nula ou se a carga do primeiro nó for `NULL`.
- **Memória:** não aloca nem libera memória.
- **Invariantes:** preservadas por se tratar de consulta.
- **Testes associados:** M02 e M03, consultas em listas vazias e com elementos.

### `lse_inserir_inicio`

- **Assinatura:** `int lse_inserir_inicio(t_lse *lista, void *carga)`.
- **Pré-condições:** a lista deve ser válida.
- **Pós-condições:** em caso de sucesso, cria um nó no início da lista, atualiza `inicio` e incrementa `tamanho`.
- **Retorno:** `1` em caso de sucesso; `0` se a lista for `NULL` ou a alocação do nó falhar.
- **Memória:** aloca um novo nó, armazenando o ponteiro para a carga sem copiar seu conteúdo.
- **Invariantes:** preserva o encadeamento e a contagem de elementos.
- **Testes associados:** M03, inserção de elementos e verificação da ordem de percurso; M04, verificação de argumentos inválidos.

### `lse_percorrer`

- **Assinatura:** `void lse_percorrer(const t_lse *lista, t_visitar cb_visitar)`.
- **Pré-condições:** recebe uma lista e um callback de visitação. Se algum deles for `NULL`, a função encerra sem realizar o percurso.
- **Pós-condições:** percorre os nós do início ao fim, executando `cb_visitar` para cada carga, sem modificar diretamente os encadeamentos.
- **Retorno:** não possui.
- **Memória:** não aloca nem libera nós.
- **Invariantes:** preservadas pela própria função, desde que o callback não altere ou destrua a estrutura durante o percurso.
- **Testes associados:** M03, conferência da ordem de visitação; M04, conferência da sequência de elementos.

### `lse_destruir`

- **Assinatura:** `void lse_destruir(t_lse *lista, void (*destruir_carga)(void *))`.
- **Pré-condições:** recebe uma lista válida ou `NULL`. O callback de destruição pode ser `NULL`.
- **Pós-condições:** libera todos os nós e a estrutura da lista. Se um callback for informado, ele será chamado para cada carga antes da liberação do respectivo nó.
- **Retorno:** não possui.
- **Memória:** libera a lista e seus nós. A liberação das cargas depende do callback fornecido. Uma chamada com lista `NULL` não realiza nenhuma operação.
- **Invariantes:** deixam de se aplicar após a destruição.
- **Testes associados:** M02, destruição de listas vazias e nulas; M03, destruição com callback; M04, liberação das listas utilizadas nos testes.

## 3. Operações de inserção, busca e remoção — M04

### `lse_inserir_fim`

- **Assinatura:** `int lse_inserir_fim(t_lse *lista, void *carga)`.
- **Pré-condições:** a lista deve ser válida.
- **Pós-condições:** em caso de sucesso, adiciona um novo nó ao final, preservando a ordem dos elementos existentes e incrementando `tamanho`.
- **Retorno:** `1` em caso de sucesso; `0` se a lista for `NULL` ou a alocação falhar.
- **Memória:** aloca um novo nó, sem copiar ou alocar a carga.
- **Invariantes:** preserva o encadeamento, o tamanho e o término da lista em `NULL`.
- **Testes associados:** M04, inserção de elementos e conferência da ordem.

### `lse_remover_inicio`

- **Assinatura:** `void *lse_remover_inicio(t_lse *lista)`.
- **Pré-condições:** recebe uma lista válida ou `NULL`.
- **Pós-condições:** quando existe um primeiro nó, remove esse nó, atualiza `inicio` e decrement