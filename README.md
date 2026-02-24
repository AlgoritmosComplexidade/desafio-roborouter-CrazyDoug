# ALGORITMOS EM GRAFOS - Desafio RoboRouter 🤖🗺️

Boas-vindas à **RescueBotics**! Nossa startup desenvolve robôs especializados no resgate de vítimas de grandes catástrofes, como terremotos e desabamentos. 

Você foi contratado(a) como pessoa desenvolvedora para criar o núcleo do **RoboRouter**, o sistema de navegação que permitirá ao nosso robô mapear os escombros (representados como um labirinto) e encontrar as vítimas.

O desafio está dividido em três níveis: **Novato**, **Aventureiro** e **Mestre**. Cada nível exige que você aplique conceitos de grafos cada vez mais avançados para otimizar o resgate.

### 🚨 Atenção: 
O nível **Novato** é o ponto de partida. Nele, o foco é puramente a **representação** computacional do labirinto utilizando Matriz de Adjacências ou Lista de Adjacências.

---

## 🎮 Nível Novato: Mapeando os Escombros

Antes de o robô andar, ele precisa "entender" o ambiente. O labirinto de escombros é composto por cruzamentos (vértices) e caminhos livres entre eles (arestas).

### 🚩 Objetivo:
- Modelar um labirinto simples como um grafo não direcionado e representá-lo na linguagem C.

### ⚙️ Funcionalidades do Sistema:
- **Estrutura de Dados:** Escolher e implementar uma forma de representação (sugerimos a **Matriz de Adjacências** para iniciar).
- **Operação:** Criar funções para inicializar o grafo e adicionar as arestas correspondentes aos caminhos do labirinto fornecido.
- **Saída:** O programa deve imprimir a estrutura do grafo no terminal (ex: imprimir a matriz com 0s e 1s) provando que o labirinto foi armazenado corretamente na memória.

---

## 🛡️ Nível Aventureiro: A Busca pela Vítima

Agora que o robô possui o mapa na memória, ele precisa saber se é possível chegar de um ponto A a um ponto B nos escombros. 

### 🆕 Diferenças em relação ao Nível Novato:
- **Travessia de Grafos:** O grafo deixa de ser apenas armazenado e passa a ser percorrido.
- **Algoritmo:** Você deverá implementar a **Busca em Profundidade (DFS)** ou a **Busca em Largura (BFS)**.
- **Operação:** O usuário informará um vértice de origem e um vértice de destino. O programa deve verificar se existe um caminho possível entre eles.

### 📥 Saída de Dados:
- Imprimir a ordem dos vértices visitados durante a busca e exibir uma mensagem confirmando se o caminho até o destino existe ou não.

---

## 🏆 Nível Mestre: Correndo Contra o Tempo

Em situações de resgate, cada segundo conta. Não basta encontrar *um* caminho; o robô precisa encontrar o **caminho mais rápido**. Os escombros agora possuem "pesos" (distâncias em metros estimadas por sensores).

### 🆕 Diferenças em relação ao Nível Aventureiro:
- **Grafo Ponderado:** As arestas não recebem mais apenas "1" para conexão, mas sim o valor da distância (peso) entre os cruzamentos.
- **Caminho Mínimo:** Em vez de uma busca cega (DFS/BFS), você precisará implementar o poderoso **Algoritmo de Dijkstra**.
- **Operação:** A partir de um vértice de entrada (origem), calcular a menor distância e o melhor trajeto até a saída (destino).

### 📥 Saída de Dados:
- Imprimir o custo total do menor caminho (a distância total).
- Imprimir a sequência exata de vértices que compõem o caminho mais curto (utilizando o vetor de "antecessores"). Ex: `Rota ideal: A -> C -> D (Distância: 5m)`.

---

💡 **Dica do Professor:** Lembre-se de que no algoritmo de Dijkstra, nós iniciamos as distâncias desconhecidas como "Infinito". Em C, como não existe um símbolo de infinito, costumamos declarar uma constante como `#define INFINITO 9999` para representar esse valor.

Mãos à obra! Vidas dependem do seu código. 🚀
