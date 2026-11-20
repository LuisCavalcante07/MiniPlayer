# Arquitetura
## Componentes
| Módulo | Responsabilidade | Dependências |
|---|---|---|
| musica | Dados da música | biblioteca padrão |
| lse | Nós genéricos e encadeamento | biblioteca padrão |
| pilha | Política LIFO | lse |
| fila | Política FIFO | lse |
| miniplayer | Simulação e integração | demais TADs |

## Diagrama de dependências
MiniPlayer → (LSE, Pilha, Fila) → LSE → t_elem interno.

## Decisões técnicas (preencher)
- Por que `void *`?
- Quem é dono das cargas?
- Como tratar referências compartilhadas?
- Quando adicionar ponteiro `fim`?

## M02
- Por que `void *`? Para a lista guardar qualquer tipo de dado (músicas, números), sem conhecer `t_musica`. Comparações e liberações específicas são feitas por funções recebidas como parâmetro (callbacks).
- Quem é dono das cargas? Quem as cria. A lista guarda só o ponteiro e não copia a carga. `lse_destruir(lista, NULL)` libera apenas os nós.
- Como tratar referências compartilhadas? A mesma música pode estar na biblioteca, no histórico e na fila, todas apontando para o mesmo objeto (sem cópia). A biblioteca é a dona: só ela libera a música. Histórico e fila guardam apenas referências e destroem a estrutura com `lse_destruir(lista, NULL)`, que libera os nós e não as cargas. Antes de liberar uma música da biblioteca, ela deve ser removida da fila e do histórico, para não deixar ponteiros soltos. Na M02 a lista é sempre vazia, então ainda não há referências compartilhadas; a regra fica registrada para as próximas missões.
- Ponteiro `fim`: adiado (otimização opcional da M08).
