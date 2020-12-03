#include <iostream>
#include <vector>
#include <exception>
#include "graph.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned long n, m, start, finish;
    std::cin >> n >> m >> start >> finish;
    std::vector<std::vector<Graph::Edge>> vertices(n + 1);

    unsigned long startVertex, endVertex, weight;
    for (unsigned long i = 0; i < m; i++) {
        std::cin >> startVertex >> endVertex >> weight;
        vertices[startVertex].push_back(Graph::Edge(endVertex, weight));
        vertices[endVertex].push_back(Graph::Edge(startVertex, weight));
    }

    Graph graph(vertices, n, m);

    try {
        unsigned long long res = graph.dijkstra(start, finish);
        std::cout << res << "\n";
    } catch (const std::logic_error &e) {
        std::cout << e.what() << "\n";
    }

    return 0;
}