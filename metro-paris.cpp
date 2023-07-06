#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

// define a estrutura para representar um nó do grafo
struct Node {
    int id;            // identificador da estação
    int g_cost;        // custo acumulado do caminho até o nó
    int h_cost;        // estimativa heurística do custo restante até o destino
    int f_cost;        // f_cost = g_cost + h_cost ou seja o custo total
    vector<int> path;  // caminho percorrido até o nó
};

// Definição do operador < para a estrutura Node
bool operator<(const Node& a, const Node& b) {
    return a.f_cost > b.f_cost; // ordem decrescente para o custo f
}

// funcao heuristica
int heuristic(int start, int goal, const vector<vector<int>>& dist) {
    return dist[start][goal];
}

// A*
vector<int> a_star(int start, int goal, const vector<vector<int>>& dist, unordered_map<int, vector<int>> adj_list) {
    priority_queue<Node> pq;  // fila de prioridade para nós a serem explorados
    vector<bool> visited(14, false);  // vetor para marcar nós visitados
    vector<int> parent(14, -1);  // vetor para rastrear os pais de cada nó
    vector<int> g_cost(14, INF);  // vetor para armazenar os custos acumulados
    vector<int> path;  // vetor para armazenar o caminho final

    // cria o nó inicial e adiciona à fila de prioridade
    Node start_node;
    start_node.id = start;
    start_node.g_cost = 0;
    start_node.h_cost = heuristic(start, goal, dist);
    start_node.f_cost = start_node.g_cost + start_node.h_cost;
    start_node.path.push_back(start);
    pq.push(start_node);

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int current_id = current.id; //current.id-1 para adequar à matriz, onde as posições se iniciam a partir do 0
        visited[current_id] = true;

        // verifica se chegamos ao destino
        if (current_id == goal) {
            path = current.path;
            break;
        }
    //printf("ate aqui no astar() ta blz\n");

        // itera sobre as estações adjacentes


        for (int neighbor : adj_list[current_id]) {
            if (!visited[neighbor]) {
                int cost = dist[current_id][neighbor]; //warning: current_id e neighbor estão indicando uma linha e coluna alem do que deveriam
                printf("current_id: %d, neigbor: %d, dist: %d ",current_id, neighbor, dist[current_id][neighbor]);
    
                int g = current.g_cost + cost;

                // verifica se o novo caminho é melhor que o atual
                if (g < g_cost[neighbor]) {
                    g_cost[neighbor] = g;
                    parent[neighbor] = current_id;

                    Node neighbor_node;
                    neighbor_node.id = neighbor;
                    neighbor_node.g_cost = g;
                    neighbor_node.h_cost = heuristic(neighbor, goal, dist);
                    neighbor_node.f_cost = g + neighbor_node.h_cost;
                    neighbor_node.path = current.path;
                    neighbor_node.path.push_back(neighbor);

                    pq.push(neighbor_node);
                }
            }
        }
    }
    return path;
}

// read adjacency matrix from a file
vector<vector<int>> read_adj_matrix(const string& file_name, int n, int m) {
    ifstream file(file_name);
    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            file >> matrix[i][j];
        }
    }

    file.close();
    return matrix;
}

// le a lista de adjacencia(estacoes)
unordered_map<int, vector<int>> read_adj_list (string file_name) {
    ifstream file;
    file.open(file_name);
    unordered_map<int, vector<int>> adj_list;
    string line;
    while (getline(file, line)) {
        int i = 0;
        while (line[i] != '-') i++;
        int u = stoi(line.substr(0, i));
        i++;
        vector<int> v;
        while (i < line.size()) {
            int j = i;
            while (line[j] != ',' && j < line.size()) j++;
            v.push_back(stoi(line.substr(i, j-i)));
            i = j+1;
        }
        adj_list[u] = v;
    }
    file.close();
    return adj_list;
}

int main (void) {

    // read distancias matrix
    vector<vector<int>> dist = read_adj_matrix("distancias.txt", 14, 14); 

    // read estacoes adjacency list
    unordered_map<int, vector<int>> adj_list = read_adj_list("estacoes.txt");

    // read linhas matrix
    vector<vector<int>> linhas = read_adj_matrix("linhas.txt", 14, 14);
 
    int start = 0;   // estação de partida
    int goal = 0;   // estação de destino

    cout << "Insira a estacao de partida: ";
    cin >> start;
    cout << "Insira a estacao de destino: ";
    cin >> goal;

    vector<int> shortest_path = a_star(start, goal, dist, adj_list);

    // Imprima o trajeto mais rápido
    cout << "Caminho mais rápido: ";
    for (int station : shortest_path) {
        cout << station << " ";
    }
    cout << endl;

}
