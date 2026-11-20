# Diário de bordo
## Missão M01 — 11/11
- Integrantes e papéis:
- Objetivo:
- O que implementamos:
- Decisão técnica e justificativa:
- Problema encontrado e solução:
- Evidências de testes:
- Próxima ação:

> Duplicar esta seção a cada missão e alternar os papéis na dupla.

## Missão M02 — 13/11
- Integrantes e papéis: Yuri Garcia: Implementação de testes, Luis Cavalcante: Relatório dos resultados
- Objetivo: instalar o pacote incremental da M02 sem sobrescrever arquivos e executar o teste de contrato de `lse_criar`, `lse_tamanho`, `lse_primeiro` e `lse_destruir`.
- O que implementamos: Nenhuma função, conforme a orientação do professor; apenas executamos o teste e documentamos.
- Decisão técnica e justificativa: executar o teste antes de qualquer alteração para registrar o estado inicial do projeto. Passamos a usar Git em um repositório compartilhado para a dupla trabalhar sobre a mesma versão.
- Problema encontrado e solução:
- Evidências de testes: comando `make -f missoes/M02/Makefile.incremental test_m02`. Saída: teste_lista_vazia: Assertion `l != NULL && "lse_criar deve retornar uma lista valida"' failed.. Detalhes em `docs/relatorio-testes.md`.
- Próxima ação: M03, implementar a LSE: criação, tamanho, primeiro e destruição.

## Missão M03 — 16/11
- Integrantes e papéis: A preencher conforme a divisão da dupla.
- Objetivo: implementar as operações básicas da lista simplesmente encadeada (LSE).
- O que implementamos: funções `lse_criar`, `lse_tamanho`, `lse_primeiro` e `lse_destruir`, além da estrutura interna da lista e dos nós.
- Decisão técnica e justificativa: utilizamos alocação dinâmica de memória e ponteiros genéricos (`void *`) para permitir o armazenamento de diferentes tipos de dados. A estrutura interna da lista ficou definida em `lse.c`, mantendo sua implementação encapsulada.
- Problema encontrado e solução: foi necessário ajustar a criação e a destruição da lista, garantindo a inicialização dos campos e a liberação dos nós alocados.
- Evidências de testes: registrar o comando executado na M03 e seu resultado.
- Próxima ação: M04, implementar inserção, busca e remoção de elementos.

## Missão M04 — 18/11
- Integrantes e papéis: A preencher conforme a divisão da dupla.
- Objetivo: implementar e testar as operações de inserção no final, remoção do início, busca e remoção por chave na LSE.
- O que implementamos: funções `lse_inserir_fim`, `lse_remover_inicio`, `lse_buscar` e `lse_remover`, utilizando comparadores para localizar elementos.
- Decisão técnica e justificativa: utilizamos a função de comparação recebida por parâmetro para permitir buscas e remoções de diferentes tipos de dados. A remoção reorganiza os ponteiros da lista e atualiza seu tamanho.
- Problema encontrado e solução: corrigimos o tratamento de argumentos nulos, ajustamos a compilação no Windows e completamos os testes incrementais. Também corrigimos chamadas que utilizavam o inteiro `1` no lugar do ponteiro da lista.
- Evidências de testes: comando `mingw32-make -f missoes/M04/Makefile.incremental test_m04`. Resultado: `M04: todos os testes passaram.` Os testes verificaram inserção, ordem dos elementos, busca por chaves existentes e inexistentes, remoção em diferentes posições e tratamento de argumentos inválidos.
- Próxima ação: revisar os contratos, atualizar o relatório de testes e continuar para a M05.