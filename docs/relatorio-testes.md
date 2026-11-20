# Relatório de testes — MiniPlayer

**Escopo documentado:** testes incrementais das missões M02, M03 e M04, no contexto do projeto iniciado na M01 com o kit do professor.

## 1. Histórico de execução

| Etapa | Condição observada | Registro |
|---|---|---|
| M02 — execução inicial | `lse_criar` ainda não implementada | Falha na asserção `l != NULL`; a execução foi interrompida antes das verificações seguintes. |
| M03 — execução inicial | Funções básicas da LSE ainda não implementadas | Falhas iniciais informadas pela dupla. |
| M02 — após as implementações | Funções básicas disponíveis | Suíte incremental aprovada, conforme registro da dupla. |
| M03 — após as implementações | Funções básicas disponíveis | Suíte incremental aprovada, conforme registro da dupla. |
| M04 — após os ajustes | Operações de inserção, busca e remoção | Resultado registrado: `M04: todos os testes passaram.` |

As falhas iniciais integram o histórico de desenvolvimento e não representam o resultado final das suítes.

## 2. Cenários e resultados finais registrados

| ID | Missão | Operação | Cenário e comportamento esperado | Resultado registrado |
|---|---|---|---|---|
| T02 | M02 | `lse_criar` | Criar lista válida e vazia. | Suíte M02 aprovada após a implementação. |
| T03 | M02 | `lse_tamanho` | Retornar `0` para lista recém-criada. | Suíte M02 aprovada após a implementação. |
| T04 | M02 | `lse_primeiro` | Retornar `NULL` para lista vazia. | Suíte M02 aprovada após a implementação. |
| T05 | M02 | `lse_destruir` | Destruir lista vazia sem erro. | Suíte M02 aprovada após a implementação. |
| T06 | M03 | `lse_criar` | Criar a estrutura da LSE. | Suíte M03 aprovada após a implementação. |
| T07 | M03 | `lse_tamanho` | Informar a quantidade de elementos. | Suíte M03 aprovada; tamanho também conferido nas operações da M04. |
| T08 | M03 | `lse_primeiro` | Consultar a carga do primeiro nó sem removê-la. | Suíte M03 aprovada, conforme registro da dupla. |
| T09 | M03 | `lse_destruir` | Liberar a estrutura da lista. | Suíte M03 aprovada, conforme registro da dupla. |
| T10 | M04 | `lse_inserir_fim` | Inserir três elementos e preservar sua ordem. | Ordem de inserção preservada. |
| T11 | M04 | `lse_buscar` | Localizar chaves presentes. | Cargas correspondentes encontradas. |
| T12 | M04 | `lse_buscar` | Consultar chave inexistente. | Retorno `NULL`. |
| T13 | M04 | `lse_remover` | Remover elementos do início, meio e fim. | Remoções e atualização da lista registradas como corretas. |
| T14 | M04 | `lse_remover_inicio` | Remover sucessivamente até esvaziar a lista. | Cargas retornadas na ordem esperada. |
| T15 | M04 | `lse_remover_inicio` | Remover de lista vazia. | Retorno `NULL`. |
| T16 | M04 | Operações da LSE | Tratar lista ou comparador `NULL`, conforme o contrato aplicável. | Retornos previstos verificados. |
| T17 | M04 | Operações genéricas | Inserir, buscar e remover músicas por ID. | Busca e remoção registradas como corretas. |

Os resultados indicados correspondem aos registros fornecidos pela dupla; este documento não atribui saídas individuais a asserções cuja transcrição não consta no histórico.

## 3. Casos-limite documentados na M04

- **Lista vazia:** operações de busca e remoção retornaram `NULL`, conforme aplicável.
- **Um elemento:** sequência de remoções com verificação do tamanho e da carga restante.
- **Chave inexistente:** busca com retorno `NULL`.
- **Valores repetidos:** dois inteiros com valor `5` utilizados em remoções sequenciais do início.
- **Argumentos inválidos:** cenários com ponteiros `NULL` em operações de inserção, busca e remoção.
- **Cargas genéricas:** operações realizadas com músicas identificadas por ID, além dos cenários com inteiros.

## 4. Ambiente e comandos registrados

- **Ambiente:** Windows, VS Code, GCC (MSYS2), GNU Make (`mingw32-make`) e Git.
- **Flags de compilação registradas:** `-std=c11 -Wall -Wextra -Wpedantic -g -Iinclude`.

```powershell
mingw32-make -f missoes/M02/Makefile.incremental test_m02
mingw32-make -f missoes/M03/Makefile.incremental test_m03
mingw32-make -f missoes/M04/Makefile.incremental test_m04
```

## 5. Ajustes técnicos registrados

- **M02:** identificação e registro da falha inicial em `lse_criar`.
- **M03:** implementação das quatro operações básicas da lista e ajustes de inicialização e destruição.
- **M04:** tratamento de argumentos inválidos; ajustes no encadeamento e nas remoções; correção de chamadas de teste; adaptação da execução para Windows.

A gestão de memória associada às operações está descrita em [Contratos dos TADs](contratos.md). A estrutura e as decisões de projeto constam em [Arquitetura](arquitetura.md), e a sequência de trabalho está registrada no [Diário de bordo](diario-de-bordo.md).
