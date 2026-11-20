# Diário de bordo — MiniPlayer

**Escopo:** missões M01 a M04.  
**Integrantes:** Yuri Garcia e Luís Cavalcante.

## M01 — 11/11 | Preparação do projeto e TAD de músicas

- **Responsáveis:** Yuri Garcia e Luís Cavalcante; organização inicial em conjunto.
- **Objetivo:** iniciar o MiniPlayer a partir do kit fornecido pelo professor e desenvolver as operações básicas do TAD de músicas.
- **Atividades realizadas:** organização inicial dos arquivos, análise das interfaces fornecidas e implementação das funções `musica_criar`, `musica_destruir` e `musica_imprimir`. Foram realizados testes para verificar os atributos das músicas, exibir seus dados no terminal e liberar a memória alocada.
- **Decisão técnica:** preservar a estrutura do projeto e as interfaces fornecidas, utilizando alocação dinâmica para armazenar músicas e uma função específica para apresentar seus atributos, mantendo a impressão separada dos testes.
- **Ocorrências e tratamento:** durante o desenvolvimento, foram realizados ajustes nas funções do TAD de músicas e verificações dos atributos armazenados. A função `musica_imprimir` foi utilizada para conferir visualmente os dados da música criada, complementando as verificações feitas com `assert`.
- **Registro de testes:** execução de `test_musica`, com verificações por `assert` dos atributos da música e chamada de `musica_imprimir`. A saída apresentou corretamente ID, título, artista e duração, encerrando com `test_musica: OK`.
- **Encaminhamento:** instalar o pacote incremental da M02 e registrar o comportamento inicial da lista simplesmente encadeada.

## M02 — 13/11 | Contratos e testes iniciais

- **Responsabilidades:** Luís Cavalcante — implementação dos testes; Yuri Garcia — relatório dos resultados.
- **Objetivo:** instalar o pacote incremental e exercitar os contratos de `lse_criar`, `lse_tamanho`, `lse_primeiro` e `lse_destruir`, antes da conclusão de suas implementações.
- **Atividades realizadas:** execução dos testes iniciais, identificação das funções incompletas e documentação do comportamento observado. Também foi utilizado o Git para acompanhar as alterações realizadas no projeto.
- **Decisão técnica:** registrar as falhas iniciais antes de concluir as implementações, preservando o histórico do desenvolvimento incremental e permitindo comparar os resultados posteriores.
- **Ocorrências e tratamento:** a primeira execução foi interrompida na asserção de `lse_criar`, pois a função ainda não retornava uma lista válida. Posteriormente, também foi necessário ajustar o tratamento de ponteiros `NULL` em `lse_tamanho` e `lse_destruir` para atender aos contratos testados.
- **Registro de testes:** `mingw32-make -f missoes/M02/Makefile.incremental test_m02`. A falha inicial foi registrada e, após as correções, a suíte apresentou `M02: teste de contrato passou.`
- **Encaminhamento:** concluir as operações básicas da LSE e ampliar os testes na M03.

## M03 — 16/11 | Operações básicas da LSE

- **Responsabilidades:** Yuri Garcia — implementação de `lse_criar`, `lse_tamanho` e `lse_percorrer`; Luís Cavalcante — implementação de `lse_primeiro`, `lse_inserir_inicio` e `lse_destruir`.
- **Objetivo:** implementar a criação, consulta de tamanho, acesso ao primeiro elemento, inserção no início, percurso e destruição da lista simplesmente encadeada.
- **Atividades realizadas:** implementação das operações básicas da LSE, incluindo criação e encadeamento de nós, atualização do tamanho, armazenamento de cargas genéricas por meio de `void *` e utilização de callbacks para percorrer os elementos e liberar suas cargas quando necessário.
- **Decisão técnica:** manter os detalhes internos da lista encapsulados em `lse.c`, utilizar ponteiros genéricos para armazenar diferentes tipos de dados e empregar callbacks para operações que dependem do tipo da carga.
- **Ocorrências e tratamento:** os testes inicialmente falharam devido às funções ainda incompletas. Após a implementação e os ajustes no encadeamento e no gerenciamento de memória, a suíte passou. Durante a revisão posterior, foi identificada uma asserção que utilizava atribuição (`=`) no lugar de comparação (`==`) na verificação da ordem dos elementos. O erro foi corrigido.
- **Registro de testes:** `mingw32-make -f missoes/M03/Makefile.incremental test_m03` — resultado informado: `M03: todos os testes passaram.` Foram verificados lista vazia, inserção e ordem dos elementos, armazenamento de cargas genéricas e destruição com callback.
- **Encaminhamento:** ampliar a LSE com inserção ao final, busca e remoção na M04.

## M04 — 18/11 | Inserção, busca e remoção

- **Responsabilidades:** Yuri Garcia — `lse_inserir_fim` e `lse_remover_inicio`; Luís Cavalcante — `lse_buscar` e `lse_remover`.
- **Objetivo:** implementar operações de inserção ao final, remoção do início, busca por chave e remoção por chave.
- **Atividades realizadas:** implementação das quatro operações, atualização dos ponteiros entre os nós e do tamanho da lista, além da utilização de comparadores para localizar e remover elementos por chave. Os testes foram completados para verificar diferentes posições e condições da lista.
- **Decisão técnica:** manter a divisão das funções entre os integrantes e utilizar callbacks de comparação para permitir operações sobre diferentes tipos de carga, sem depender diretamente da estrutura `t_musica`.
- **Ocorrências e tratamento:** foram realizados ajustes no tratamento de argumentos `NULL`, nas operações de inserção e remoção e na execução dos testes no Windows. Também foram corrigidas chamadas de teste que utilizavam o inteiro `1` no lugar do ponteiro da lista.
- **Registro de testes:** `mingw32-make -f missoes/M04/Makefile.incremental test_m04` — resultado: `M04: todos os testes passaram.` Foram verificadas inserções ao final, ordem dos elementos, buscas por chave, remoções no início, meio e fim, operações com músicas e tratamento de argumentos inválidos.
- **Encaminhamento:** revisar os contratos, atualizar o relatório de testes e consolidar a documentação para a entrega até a M04. As operações previstas para missões posteriores permanecem fora do escopo desta entrega.

## Referências documentais

- [Relatório de testes](relatorio-testes.md): cenários executados, resultados e casos-limite.
- [Contratos dos TADs](contratos.md): pré-condições, pós-condições, retornos e gerenciamento de memória.
- [Arquitetura](arquitetura.md): organização das estruturas, decisões técnicas e planejamento futuro.