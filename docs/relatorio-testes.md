# Relatório de testes
| ID | Missão | Função/contrato | Entrada/cenário | Resultado esperado | Resultado obtido | Status |
|---|---|---|---|---|---|---|
| T01 | M01 | musica_criar | dados válidos | ponteiro não nulo e campos corretos | preencher | pendente |

| T02 | M02 | lse_criar | criar lista nova | ponteiro não nulo | `Assertion l != NULL` falhou; programa abortado | falha esperada (função ainda é stub) |
| T03 | M02 | lse_tamanho | lista recém-criada | retorna 0 | não executado (teste abortou em T02) | pendente |
| T04 | M02 | lse_primeiro | lista vazia | retorna NULL | não executado (teste abortou em T02) | pendente |
| T05 | M02 | lse_destruir | lista vazia | chamada sem erro | não executado (teste abortou em T02) | pendente |
| T06 | M03 | lse_criar | criar uma lista nova | ponteiro não nulo | lista criada durante os testes da M04 | passou na M04 |
| T07 | M03 | lse_tamanho | lista recém-criada e após inserções/remoções | retornar o tamanho correto | tamanho conferido durante os testes da M04 | passou na M04 |
| T08 | M03 | lse_primeiro | lista vazia | retornar NULL | não verificado diretamente nos testes da M04 | pendente de verificação |
| T09 | M03 | lse_destruir | destruir lista após os testes | liberar os nós sem provocar falhas | execução concluída sem erro aparente | passou na execução |
| T10 | M04 | lse_inserir_fim | inserir três elementos | inserir com sucesso, mantendo a ordem | três elementos inseridos na ordem esperada | passou |
| T11 | M04 | lse_buscar | buscar elementos presentes | retornar o ponteiro da carga correspondente | elementos encontrados corretamente | passou |
| T12 | M04 | lse_buscar | buscar elemento inexistente | retornar NULL | retornou NULL | passou |
| T13 | M04 | lse_remover | remover elementos do meio, fim e início | retornar a carga removida e atualizar a lista | remoções realizadas e lista conferida | passou |
| T14 | M04 | lse_remover_inicio | remover elementos até esvaziar a lista | retornar as cargas na ordem correta | elementos removidos na ordem esperada | passou |
| T15 | M04 | lse_remover_inicio | remover de lista vazia | retornar NULL | retornou NULL | passou |
| T16 | M04 | operações com argumentos inválidos | passar NULL como lista ou comparador | retornar 0 ou NULL conforme o contrato | retornos verificados pelos testes | passou |
| T17 | M04 | operações genéricas | inserir, buscar e remover músicas por ID | funcionar com estruturas além de inteiros | busca e remoção realizadas corretamente | passou |

## Casos-limite
- Estrutura vazia: testada na M04 por meio de `lse_remover_inicio`, `lse_buscar` e `lse_remover`, verificando o retorno de `NULL`.
- Estrutura com um elemento: testada após as remoções, verificando o tamanho e o elemento restante.
- Chave inexistente: testada na busca, com retorno esperado e obtido igual a `NULL`.
- Valores repetidos: testados na remoção sequencial do início da lista, utilizando dois inteiros com valor 5.
- Argumentos inválidos: testados com ponteiros `NULL` nas operações de inserção, busca e remoção.
- Falha de alocação: ainda não simulada. As funções verificam o retorno de `malloc`, mas será necessário um teste específico para comprovar esse comportamento.

## Memória
- Comando de teste da M02: `make -f missoes/M02/Makefile.incremental test_m02`
- Comando de teste da M04: `-make -f missoes/M04/Makefile.incremental test_m04`

- Flags de compilação: `-std=c11 -Wall -Wextra -Wpedantic -g -Iinclude`

- Ferramentas utilizadas: GCC, VS Code e Git.

- Problemas corrigidos: tratamento de argumentos nulos, ajustes nas operações de inserção e remoção, correção dos argumentos utilizados nos testes e adaptação do Makefile para execução no Windows.

- Resultado da M04: `M04: todos os testes passaram.`

- Gerenciamento de memória: os nós são alocados dinamicamente e liberados durante as remoções ou destruição da lista. A função `lse_destruir` permite utilizar uma função de liberação da carga quando necessário.

- Verificação de vazamentos de memória: ainda não realizada com ferramenta específica.

