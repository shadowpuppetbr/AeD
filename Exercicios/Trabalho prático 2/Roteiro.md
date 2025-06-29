---

# Roteiro da Apresentação: Resolvendo o Problema "Happy String"

---

## 1. Introdução (1 min)

* Apresentar o problema **"Happy String"** e a autoria do código por **Gustavo dos Santos Leon**.
* Mostrar o arquivo **README.md** com as informações do problema.

---

## 2. Código Desenvolvido (4 min)

* Explicar que a versão desenvolvida em aula não estava completa e não implementava a estrutura de dados correta (heap).
* Mostrar o **código desenvolvido em aula**.
* Mostrar o **código desenvolvido em casa**.

### Estruturas de Dados

#### Estrutura `Item`

Essa estrutura representa um item na fila (heap), contendo uma letra (`char c`) e a quantidade (`int qtd`) dessa letra.

#### Estrutura `Queue`

Essa estrutura representa a fila (heap), contendo os seguintes campos:
* `head`: Índice do início da fila.
* `end`: Índice do final da fila.
* `capacity`: Capacidade máxima da fila.
* `q`: Ponteiro para um array de `Items`, que representa a fila.

### Funções Declaradas

* `longestDiverseString`: Função principal que resolve o problema.
* `enqueue`: Função que adiciona um novo `Item` à fila (heap).
* `dequeue`: Função que remove e retorna o `Item` com maior quantidade da fila (heap).
* `new_queue`: Função que cria uma nova fila (heap) com uma capacidade especificada.

### Implementação da Função `new_queue`

Essa função aloca memória dinamicamente para uma nova `Queue`.
Ela inicializa os campos `head`, `end` e `capacity` da `Queue`.
Ela também aloca memória dinamicamente para o array de `Items` (`q`) dentro da `Queue`.
Por fim, ela retorna o ponteiro para a nova `Queue` criada.

### Implementação da Função `enqueue`

Este código implementa uma função `enqueue` para inserir um novo elemento em uma fila de prioridade implementada como um heap:
* Verifica se a fila está cheia ou se a quantidade (`qtd`) é inválida ( `<= 0` ), retornando `false` se sim.
* Insere o novo elemento no final da fila.
* Realiza uma **subida (bubble up)** no heap para manter a propriedade do heap (pai tem prioridade maior que os filhos), trocando elementos enquanto a quantidade do novo elemento for maior que a do pai.
    * *Uso de desenhos no Paint para auxiliar na explicação.*

### Implementação da Função `dequeue`

A função `dequeue` remove e retorna o elemento com maior prioridade (maior `qtd`) de uma fila de prioridade implementada como heap:

* Se a fila estiver vazia, retorna um item vazio.
* Remove o elemento do topo (índice 0) e substitui-o pelo último elemento da fila.
* Realiza uma **descida (bubble down)** para restaurar a propriedade do heap, trocando o elemento com o filho de maior prioridade até que a ordem seja restaurada.
    * *Uso de desenhos no Paint para auxiliar na explicação.*

### Implementação da Função Principal

### 1. Introdução

- A função `longestDiverseString` cria a string mais longa sem mais de duas letras iguais consecutivas (ex: "aaa").
- Recebe as contagens iniciais de 'a', 'b' e 'c'.

### 2. Preparação

- **`index`**: Controla a posição atual na string.
- **`s`**: A string sendo construída dinamicamente.
- **`queue`**: Uma **fila de prioridade (heap)** inicializada com as letras 'a', 'b', 'c' e suas respectivas contagens. O item com a maior contagem sempre terá a maior prioridade.

### 3. Loop Principal

- O loop continua enquanto houver letras na fila.
- **`Item item = dequeue(queue);`**: Removemos a letra com a **maior quantidade** da fila.

#### Lógica Crucial: Evitar "aaa"

- **`if (index >= 2 && s[index - 1] == item.c && s[index - 2] == item.c)`**: Se adicionar `item.c` resultar em três letras iguais seguidas:
  - Verificamos se há **outra letra disponível** na fila.
  - Se sim, retiramos essa **próxima letra** (`next`).
  - A `item` original (que causaria a repetição) é **recolocada na fila**.
  - `item` passa a ser a `next` para ser usada.
  - Se não houver outra letra disponível, o loop para.

#### Adicionar e Atualizar

- **`s = realloc(s, (index + 2) \* sizeof(char));`**: Redimensiona a string dinamicamente.
- **`s[index++] = item.c; s[index] = '\0';`**: Adiciona a letra à string e atualiza o terminador nulo.
- **`if (item.qtd > 1) { enqueue(queue, item.c, item.qtd - 1); }`**: Se a letra usada ainda tiver contagem restante, ela é **colocada de volta na fila** com sua contagem decrementada.

### 4. Finalização

- **`free(queue->q); free(queue);`**: Libera a memória alocada para a fila.
- **`return s;`**: Retorna a string final construída.

### Ajuda da IA

* Comentar as partes do código que precisaram de ajuda da IA e explicar os motivos.
* **Quase todo o código** foi desenvolvido com o auxílio da IA.

---

## 3. Casos de Teste (2 min)

* Ler os 3 casos de teste do **README.md**.
* Mostrar a execução do código para cada caso de teste.
* Exibir o resultado no LeetCode usando o botão **"Submit"**.

---

## 4. Complexidade do Algoritmo (1 min)

* Falar sobre a complexidade do algoritmo implementado.

### Complexidade do Algoritmo

A complexidade do algoritmo é $O(n \log n)$, onde $n$ é o total de caracteres ($a + b + c$).

* Cada operação de `enqueue` e `dequeue` na fila de prioridade (heap) tem complexidade $O(\log n)$.
* O algoritmo realiza aproximadamente $n$ operações de inserção e remoção, levando a $O(n \log n)$ no total.

---

## 5. Comparação com a Solução Editorial (1 min)

* Caso o problema tenha uma solução editorial no LeetCode, comparar a sua solução com a solução apresentada.
* Comentar sobre as diferenças e semelhanças entre as abordagens.

### Comparação com a Solução Editorial

A solução editorial geralmente também usa uma fila de prioridade ou uma abordagem semelhante, com complexidade $O(n \log n)$.

* A diferença pode estar na implementação do heap (por exemplo, usando uma estrutura pronta ou implementada manualmente).
* Ambas as soluções seguem a mesma lógica de evitar 3 letras iguais seguidas, mas podem variar em detalhes de implementação e eficiência prática.

---

## 6. Conclusão (1 min)

* Resumir os principais pontos abordados no vídeo.
* Mencionar se foi possível concluir o exercício sem a ajuda da IA/internet ou se foi necessário utilizá-las.

---