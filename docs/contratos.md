# Contratos dos TADs — MiniPlayer

**Escopo:** operações da lista simplesmente encadeada (LSE) documentadas nas missões M02 a M04. Os contratos básicos foram introduzidos na M02 e implementados na M03; as operações adicionais foram desenvolvidas na M04.

## 1. Invariantes da LSE

- `tamanho >= 0`.
- `tamanho == 0` se, e somente se, `inicio == NULL`.
- Existem exatamente `tamanho` nós alcançáveis a partir de `inicio`.
- O último nó aponta para `NULL`, sem ciclos.
- Uma inserção bem-sucedida aumenta `tamanho` em uma unidade; uma remoção bem-sucedida o diminui em uma unidade.
- Consultas não modificam a lista.

## 2. Contratos básicos — M02/M03

### `lse_criar`

- **Assinatura documentada:** `t_lse *lse_criar(void)`.
- **Pré-condições:** nenhuma.
- **Pós-condições:** em caso de sucesso, a lista está vazia (`inicio == NULL` e `tamanho == 0`).
- **Retorno:** ponteiro para a lista criada; `NULL` se a alocação falhar.
- **Memória:** aloca a estrutura da lista; a liberação cabe a `lse_destruir`.
- **Invariantes:** estabelecidas na criação.
- **Testes associados:** suítes M02 e M03.

### `lse_tamanho`

- **Assinatura documentada:** `int lse_tamanho(const t_lse *lista)`.
- **Pré-condições:** lista válida ou `NULL`, conforme a decisão registrada no projeto.
- **Pós-condições:** a lista permanece inalterada.
- **Retorno:** quantidade de elementos; `0` para lista `NULL`.
- **Memória:** não aloca nem libera.
- **Invariantes:** preservadas por se tratar de consulta.
- **Testes associados:** suítes M02/M03 e conferências de tamanho na M04.

### `lse_primeiro`

- **Assinatura documentada:** `void *lse_primeiro(const t_lse *lista)`.
- **Pré-condições:** lista válida ou `NULL`, conforme o tratamento documentado.
- **Pós-condições:** não remove elementos nem altera a lista.
- **Retorno:** ponteiro para a carga do primeiro nó; `NULL` para lista vazia ou inválida.
- **Memória:** não aloca nem libera a carga.
- **Invariantes:** preservadas por se tratar de consulta.
- **Testes associados:** suítes M02 e M03.

### `lse_destruir`

- **Assinatura documentada:** `void lse_destruir(t_lse *lista, void (*destruir_carga)(void *))`.
- **Pré-condições:** lista válida e ainda não destruída; `destruir_carga` pode ser `NULL`.
- **Pós-condições:** libera nós e estrutura; se houver callback, este pode ser usado para liberar as cargas sob responsabilidade da lista. O ponteiro destruído deixa de ser válido.
- **Retorno:** não possui.
- **Memória:** libera a estrutura e os nós; libera cargas apenas por meio do callback informado.
- **Invariantes:** deixam de se aplicar após a destruição.
- **Testes associados:** suítes M02 e M03 e destruição das estruturas utilizadas na M04.

## 3. Operações de inserção, busca e remoção — M04

As entradas e os resultados abaixo são descritos pelo comportamento registrado nos documentos do projeto. As assinaturas completas destas quatro funções não foram reproduzidas, pois os arquivos utilizados nesta consolidação não contêm as respectivas declarações de `include/lse.h`.

### `lse_inserir_fim`

- **Entradas:** lista e ponteiro para a carga.
- **Pré-condições:** lista válida e demais argumentos aceitos pela interface.
- **Pós-condições:** em caso de sucesso, adiciona um nó ao final, preserva a ordem existente e incrementa `tamanho`.
- **Retorno:** indicador de sucesso ou falha; argumentos inválidos não indicam sucesso.
- **Memória:** aloca o novo nó; não copia a carga apontada.
- **Invariantes:** encadeamento, tamanho e término em `NULL` preservados.
- **Testes associados:** M04, inserção de três elementos e conferência de ordem.

### `lse_remover_inicio`

- **Entradas:** lista.
- **Pré-condições:** lista válida; a situação de lista vazia é tratada.
- **Pós-condições:** quando há elemento, remove o primeiro nó, atualiza `inicio` e decrementa `tamanho`.
- **Retorno:** ponteiro para a carga removida; `NULL` para lista vazia.
- **Memória:** libera o nó removido, sem liberar a carga retornada.
- **Invariantes:** encadeamento e tamanho preservados, inclusive ao esvaziar a lista.
- **Testes associados:** M04, remoções sucessivas e lista vazia.

### `lse_buscar`

- **Entradas:** lista, chave e callback comparador.
- **Pré-condições:** parâmetros válidos conforme a interface da função.
- **Pós-condições:** não altera a estrutura.
- **Retorno:** ponteiro para a carga encontrada; `NULL` para chave inexistente ou argumentos inválidos, conforme os testes registrados.
- **Memória:** não aloca nem libera.
- **Invariantes:** preservadas por se tratar de consulta.
- **Testes associados:** M04, chaves existentes e inexistentes, argumentos inválidos e músicas por ID.

### `lse_remover`

- **Entradas:** lista, chave e callback comparador.
- **Pré-condições:** parâmetros válidos conforme a interface da função.
- **Pós-condições:** ao encontrar a chave, retira o nó correspondente, reconecta os demais e decrementa `tamanho`; quando não encontra, mantém a estrutura.
- **Retorno:** ponteiro para a carga removida; `NULL` para chave inexistente ou argumentos inválidos, conforme os testes registrados.
- **Memória:** libera o nó e devolve a carga ao chamador.
- **Invariantes:** encadeamento e tamanho preservados.
- **Testes associados:** M04, remoções no início, meio e fim e músicas por ID.

## 4. Propriedade das cargas e callbacks

- A LSE gerencia a estrutura da lista e seus nós; a carga é armazenada como ponteiro `void *`, sem cópia do objeto.
- `lse_destruir(lista, NULL)` libera a estrutura e os nós, mantendo as cargas sob responsabilidade de seus proprietários.
- Quando apropriado, `destruir_carga` permite liberar as cargas na destruição da lista.
- Busca e remoção por chave utilizam callback comparador para operar com diferentes tipos de dados.
- Na integração futura com referências compartilhadas, deve haver um proprietário definido para cada carga, evitando liberações duplicadas.

## 5. Continuidade nas missões futuras

Os contratos acima limitam-se às operações explicitamente documentadas até a M04. **Permanece prevista a implementação das demais funções declaradas em `include/lse.h` que forem exigidas nas missões seguintes**, respeitando suas interfaces e os contratos correspondentes. Não se atribuem assinaturas ou estados individuais a operações não discriminadas nos registros desta etapa.

**Referências:** [Diário de bordo](diario-de-bordo.md) · [Relatório de testes](relatorio-testes.md) · [Arquitetura](arquitetura.md).
