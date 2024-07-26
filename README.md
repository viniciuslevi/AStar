# Busca Informada Utilizando O Algoritmo A*: O Caso Do Metrô De Paris

---

## Resumo

O metrô de Paris é um clássico problema que permite trabalhar diversos conceitos da disciplina de estrutura de dados, como grafos, filas, entre outros. O objetivo é encontrar o menor percurso de uma estação A para uma estação B, considerando transições entre diferentes linhas. Implementamos um algoritmo que decide a cada estação qual próximo caminho a ser percorrido, visando aproximar o passageiro do destino pela rota mais eficiente. Utilizamos o algoritmo A* para resolver o problema, destacando o processo de tomada de decisões (heurística) e escolha do menor caminho. O algoritmo foi implementado em C++.

---

## Problema da Busca em Grafos

Um algoritmo de busca em grafos percorre todos os vértices de um grafo andando pelos arcos de um vértice a outro. Cada algoritmo utiliza diferentes metodologias para a visitação dos nós da forma mais eficiente possível.

---

## Tipos de Buscas

### Busca Cega

- **Busca em Largura (BFS):** Explora o grafo nível a nível utilizando uma fila para controlar a ordem de visita dos nós.
- **Busca em Profundidade (DFS):** Explora o grafo aprofundadamente seguindo um caminho até encontrar um ponto de parada, utilizando uma pilha.

### Busca Informada

- **A* (A-Star):** Combina busca de custo uniforme com uma heurística admissível que estima o custo restante para o objetivo.
- **Busca Gulosa (Greedy Best-First Search):** Escolhe o próximo nó para expansão com base na heurística que estima a proximidade ao objetivo.

---

## Problema do Caminho Mais Curto

Para resolver o problema do metrô de Paris, selecionamos algoritmos eficientes considerando as limitações de recursos de máquina e tempo de processamento. Utilizamos o algoritmo A* para escolher o caminho para um nó mais próximo do objetivo, combinando a distância atual até o próximo nó (g(x)) e a distância estimada do próximo nó até o objetivo (heurística) (h(x)).

---

## Algoritmo de Dijkstra

O algoritmo de Dijkstra encontra o caminho mais curto entre um nó de origem e todos os outros nós de um grafo ponderado, utilizando uma abordagem gulosa. A cada iteração, atualiza as distâncias se encontrar um caminho mais curto e repete até que todos os nós sejam visitados ou o nó de destino seja alcançado.

---

## Busca Informada com A*

O A* encontra o caminho mais curto em um grafo ponderado utilizando informações heurísticas. Combina o custo do caminho percorrido (g) com uma heurística que estima o custo restante (h), definindo a função de custo f(n) = g(n) + h(n). A heurística admissível garante encontrar o caminho mais curto.

---

## Considerações

O objetivo primordial foi a resolução do problema, alcançado com sucesso. Entendemos o funcionamento do algoritmo e suas partes constituintes. A fila de prioridade foi crucial para o ranqueamento dos nós pelo critério de menor custo f(x), permitindo a escolha da menor distância e rotas alternativas em caso de bloqueios. O algoritmo apresentou coerência ao encontrar a menor rota entre duas estações, contabilizando o tempo de percurso total, considerando distâncias reais e trocas de baldeações.

---

## Referências

GEEKSFORGEEKS. A* Search Algorithm. Disponível em: GeeksforGeeks

SIMIC, Milos. Dijkstra vs. A* – Pathfinding. Baeldung on Computer Science, 8 nov. 2022. Disponível em: Baeldung

BHAGAT, Avidant; AGARWAL, Satvik; POLLOCK, Josh; AUSTIN, Steven. A* Search and Dijkstra’s Algorithm. Disponível em: CSE442-17F
