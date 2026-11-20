# Diário de bordo — MiniPlayer

**Escopo:** missões M01 a M04.  
**Integrantes:** Yuri Garcia e Luís Cavalcante.

## M01 — 11/11 | Preparação do projeto

- **Responsáveis:** Yuri Garcia e Luís Cavalcante; organização inicial em conjunto.
- **Objetivo:** iniciar o MiniPlayer a partir do kit fornecido pelo professor.
- **Atividades realizadas:** organização inicial dos arquivos e adoção da estrutura do kit como base para o desenvolvimento incremental.
- **Decisão técnica:** preservar a organização e as interfaces fornecidas, de modo a permitir a evolução do projeto nas missões seguintes.
- **Encaminhamento:** instalação do pacote incremental da M02 e registro do comportamento inicial da LSE.

## M02 — 13/11 | Contratos e testes iniciais

- **Responsabilidades:** **Luís Cavalcante** — implementação dos testes; **Yuri Garcia** — relatório dos resultados.
- **Objetivo:** instalar o pacote incremental e exercitar os contratos de `lse_criar`, `lse_tamanho`, `lse_primeiro` e `lse_destruir`, antes de sua implementação.
- **Atividades realizadas:** execução dos testes iniciais e documentação do comportamento das funções ainda incompletas; utilização do Git para acompanhar o trabalho da dupla.
- **Decisão técnica:** registrar o comportamento inicial antes de modificar as funções, preservando a evidência da evolução incremental.
- **Ocorrência e tratamento:** a execução foi interrompida na asserção de `lse_criar`, que ainda não retornava uma lista válida. A falha foi registrada como esperada para essa etapa; a implementação das funções ficou concentrada na M03.
- **Registro de testes:** falha inicial na verificação `l != NULL`; aprovação posterior da suíte da M02 após as implementações, conforme os resultados registrados pela dupla.
- **Encaminhamento:** implementar as funções básicas da LSE na M03.

## M03 — 16/11 | Operações básicas da LSE

- **Responsabilidades:** **Yuri Garcia** — `lse_criar` e `lse_tamanho`; **Luís Cavalcante** — `lse_primeiro` e `lse_destruir`.
- **Objetivo:** implementar criação, consulta de tamanho, acesso ao primeiro elemento e destruição da lista simplesmente encadeada.
- **Atividades realizadas:** implementação das quatro funções e da manipulação necessária da estrutura interna da lista e de seus nós.
- **Decisão técnica:** dividir igualmente as funções; manter os detalhes da lista encapsulados em `lse.c`, com alocação dinâmica e cargas genéricas representadas por `void *`.
- **Ocorrência e tratamento:** os testes falharam na execução inicial, quando as funções ainda não estavam implementadas. Após o desenvolvimento e os ajustes relativos à inicialização e à liberação de memória, a suíte da M03 foi aprovada, conforme os registros da dupla.
- **Registro de testes:** `mingw32-make -f missoes/M03/Makefile.incremental test_m03` — aprovação relatada após a implementação.
- **Encaminhamento:** ampliar a LSE com inserção, busca e remoção na M04.

## M04 — 18/11 | Inserção, busca e remoção

- **Responsabilidades:** **Yuri Garcia** — `lse_inserir_fim` e `lse_remover_inicio`; **Luís Cavalcante** — `lse_buscar` e `lse_remover`.
- **Objetivo:** desenvolver operações de inserção ao final, remoção do início, busca por chave e remoção por chave.
- **Atividades realizadas:** implementação das quatro operações, atualização do encadeamento e do tamanho da lista e utilização de comparadores nas operações orientadas por chave.
- **Decisão técnica:** manter a divisão de duas funções por integrante e utilizar callbacks de comparação para preservar a independência da LSE em relação ao tipo da carga.
- **Ocorrências e tratamento:** ajustes no tratamento de argumentos `NULL`, nas operações de inserção e remoção e na execução dos testes no Windows. Também foram corrigidas chamadas de teste que utilizavam o inteiro `1` no lugar do ponteiro da lista.
- **Registro de testes:** `mingw32-make -f missoes/M04/Makefile.incremental test_m04` — resultado registrado: `M04: todos os testes passaram.` Foram contempladas inserções, ordem dos elementos, buscas, remoções e argumentos inválidos.
- **Encaminhamento:** consolidar os contratos e a documentação da entrega até a M04. Nas missões futuras, prosseguir com a implementação das demais funções previstas em `include/lse.h`, segundo o escopo das próximas etapas.

## Referências documentais

- [Relatório de testes](relatorio-testes.md): cenários e resultados registrados.
- [Contratos dos TADs](contratos.md): comportamento das operações descritas.
- [Arquitetura](arquitetura.md): estruturas, decisões técnicas e planejamento futuro.
