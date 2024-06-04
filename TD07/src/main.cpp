#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <stack>
#include <queue>


namespace Graph {
    struct WeightedGraphEdge {
        int to {};
        float weight {1.0f};

        // default ici permet de définit les opérateurs de comparaison membres à membres automatiquement
        // Cela ne fonction qu'en C++20, si vous n'avez pas accès à cette version je vous donne les implémentations des opérateurs plus bas
        bool operator==(WeightedGraphEdge const& other) const = default;
        bool operator!=(WeightedGraphEdge const& other) const = default;
    };

    struct WeightedGraph {
        // L'utilisation d'un tableau associatif permet d'avoir une complexité en O(1) pour l'ajout et la recherche d'un sommet.
        // Cela permet de stocker les sommets dans un ordre quelconque (et pas avoir la contrainte d'avoir des identifiants (entiers) de sommets consécutifs lors de l'ajout de sommets).
        // Cela permet également de pouvoir utiliser des identifiants de sommets de n'importe quel type (string, char, int, ...) et pas seulement des entiers.
        std::unordered_map<int, std::vector<WeightedGraphEdge>> adjacency_list {};

        void add_vertex(int const id){
            if (adjacency_list.find(id) == adjacency_list.end())
            {
                adjacency_list[id] = std::vector<WeightedGraphEdge>{};
            }
        }

        void add_directed_edge(int const from, int const to, float const weight = 1.0f){
            add_vertex(from);
            add_vertex(to);
            adjacency_list[from].emplace_back(WeightedGraphEdge{to, weight});
        }

        void add_undirected_edge(int const from, int const to, float const weight = 1.0f){
            add_directed_edge(from, to, weight);
            add_directed_edge(to, from, weight);
        }
        
        // Même fonctionnement que pour WeightedGraphEdge
        bool operator==(WeightedGraph const& other) const = default;
        bool operator!=(WeightedGraph const& other) const = default;

        void print_DFS(int const start) const {
            std::vector<bool> visited(adjacency_list.size(), false);
            std::stack<int> stack;

            stack.push(start);

            while (!stack.empty()) 
            {
                int node = stack.top();
                stack.pop();

                if (!visited[node]) 
                {
                    std::cout << node << " ";
                    visited[node] = true;

                    for (auto it = adjacency_list.at(node).rbegin(); it != adjacency_list.at(node).rend(); it++) 
                    {
                        if (!visited[it->to])
                        {
                            stack.push(it->to);
                        }
                    }
                }
            }
        }

        void print_BFS(int const start) const{
            std::vector<bool> visited(adjacency_list.size(), false);
            std::queue<int> queue;

            queue.push(start);
            visited[start] = true;

            while (!queue.empty()) 
            {
                int node = queue.front();
                queue.pop();

                std::cout << node << " ";

                for (const auto& edge : adjacency_list.at(node)) 
                {
                    if (!visited[edge.to]) 
                    {
                        queue.push(edge.to);
                        visited[edge.to] = true;
                    }
                }
            }
        }

    };

    WeightedGraph build_from_adjacency_matrix(std::vector<std::vector<int>> const& adjacency_matrix){
        WeightedGraph graph;

        for (size_t i = 0; i < adjacency_matrix.size(); i++)
        {
            for (size_t j = 0; j < adjacency_matrix[i].size(); j++)
            {
                if (adjacency_matrix[i][j] != 0)
                {
                    graph.add_directed_edge(i, j, static_cast<float>(adjacency_matrix[i][j]));
                }
            }
        }

        return graph;
    }

} // namespace


int main(){

    std::vector<std::vector<int>> adjacency_matrix = {
        {0, 1, 5, 2, 0, 0},
        {0, 0, 4, 5, 0, 0},
        {0, 0, 0, 0, 3, 4},
        {0, 0, 2, 0, 5, 0},
        {0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0}
    };

    Graph::WeightedGraph graph1 = Graph::build_from_adjacency_matrix(adjacency_matrix);
    Graph::WeightedGraph graph2;

    for (int i = 0; i < adjacency_matrix.size(); i++) {
        graph2.add_vertex(i);
    }

    graph2.add_undirected_edge(0, 1, 1.0f);
    graph2.add_undirected_edge(1, 2, 1.0f);
    graph2.add_undirected_edge(1, 3, 1.0f);
    graph2.add_undirected_edge(2, 3, 1.0f);

    if (graph1 == graph2) 
    {
        std::cout << "Les graphes sont égaux." << std::endl;
    } 
    else 
    {
        std::cout << "Les graphes ne sont pas égaux." << std::endl;
    }

    graph1.print_DFS(0);
    std::cout << std::endl;

    graph1.print_BFS(0);
    std::cout << std::endl;

}