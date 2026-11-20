# Arquitetura — MiniPlayer

**Escopo da documentação:** organização do projeto e evolução registrada das missões M01 a M04. A descrição dos componentes futuros representa planejamento arquitetural, não conclusão de sua implementação.

## 1. Componentes e dependências

| Módulo | Responsabilidade | Dependências | Situação documentada até M04 |
|---|---|---|---|
| `musica` | Representação dos dados de uma música | Biblioteca padrão de C | Presente na estrutura inicial do projeto. |
| `lse` | Lista de nós simplesmente encadeados com cargas genéricas | Biblioteca padrão de C | Operações básicas na M03; inserção, busca e remoção na M04. |
| `pilha` | Política LIFO | LSE | Prevista na arquitetura. |
| `fila` | Política FIFO | LSE | Prevista na arquitetura. |
| `miniplayer` | Integração dos demais TADs e simulação | Módulos do projeto | Integração prevista na arquitetura. |

```text
MiniPlayer
   |-- Música
   |-- Pilha ---- LSE
   |-- Fila  ---- LSE
   `-- Integração dos TADs

LSE ---- nós internos (t_elem)
```

A organização modular permite desenvolver os TADs de forma incremental, sem expor os detalhes internos dos nós aos componentes que utilizam a lista.

## 2. Estrutura da LSE

A lista mantém um ponteiro `inicio` para o primeiro nó e um contador `tamanho`. Cada nó interno (`t_elem`) armazena uma carga `void *` e o ponteiro para o próximo nó.

```text
inicio -> [carga | proximo] -> [carga | NULL]
tamanho = 2
```

As estruturas internas ficam no módulo `lse.c`, enquanto a interface pública é disponibilizada por `include/lse.h`.

### Invariantes estruturais

- `tamanho` é não negativo e coincide com o número de nós acessíveis por `inicio`.
- `inicio == NULL` se, e somente se, `tamanho == 0`.
- O último nó aponta para `NULL` e não há ciclos.
- Inserções e remoções mantêm o encadeamento e atualizam o tamanho.

## 3. Decisões de projeto

### Dados genéricos

O uso de `void *` permite armazenar referências a diferentes tipos de dados, sem acoplar a LSE ao tipo `t_musica`. Funções recebidas por parâmetro (*callbacks*) permitem realizar operações dependentes do conteúdo das cargas, como comparação e destruição.

### Propriedade e liberação de memória

A LSE é responsável pela alocação e liberação de seus nós e de sua estrutura. As cargas não são copiadas automaticamente. Em `lse_destruir(lista, NULL)`, apenas a estrutura e os nós são liberados; o callback `destruir_carga`, quando fornecido, permite liberar as cargas de acordo com o responsável por elas.

### Referências compartilhadas — diretriz futura

A arquitetura prevê que a biblioteca, o histórico e a fila possam referenciar a mesma música. Nesse cenário, a biblioteca é a proprietária da carga e as outras estruturas mantêm apenas referências. Antes da liberação de uma música, suas referências devem ser retiradas das estruturas dependentes para evitar ponteiros inválidos. Esta diretriz não pressupõe a integração concluída até a M04.

### Otimização opcional

A inclusão de um ponteiro `fim` na estrutura da lista foi adiada como otimização opcional da M08. Na organização registrada até a M04, a inserção no final pode percorrer os nós a partir de `inicio`.

## 4. Evolução até a M04

| Missão | Atividades registradas | Responsáveis |
|---|---|---|
| M01 | Início do projeto com o kit fornecido pelo professor. | Yuri Garcia e Luís Cavalcante. |
| M02 | Testes e contratos iniciais da LSE; registro da falha esperada antes das implementações. | Luís: implementação dos testes; Yuri: relatório dos resultados. |
| M03 | Implementação de `lse_criar`, `lse_tamanho`, `lse_primeiro` e `lse_destruir`. | Yuri: duas primeiras; Luís: duas últimas. |
| M04 | Implementação de `lse_inserir_fim`, `lse_remover_inicio`, `lse_buscar` e `lse_remover`. | Yuri: duas primeiras; Luís: duas últimas. |

Os registros da dupla informam aprovação das suítes incrementais M02, M03 e M04 após as implementações e ajustes. O [Relatório de testes](relatorio-testes.md) apresenta os cenários e resultados registrados.

## 5. Escopo das próximas missões

A continuidade do desenvolvimento prevê **implementar as demais funções definidas em `include/lse.h` que não estejam abrangidas pelo escopo documentado até a M04**, seguindo as exigências das missões futuras. A arquitetura também prevê a evolução dos módulos de pilha, fila e integração do MiniPlayer, além da otimização opcional `fim` na M08.

Não se estabelece aqui a numeração das missões de pilha, fila ou integração, pois ela não consta nos documentos que fundamentam este registro.

**Referências:** [Diário de bordo](diario-de-bordo.md) · [Contratos dos TADs](contratos.md) · [Relatório de testes](relatorio-testes.md).
