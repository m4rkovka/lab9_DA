#include <iostream>
#include <cstdlib>
#include <chrono>
#include <cmath>
#include "../solution/graph.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        return 1;
    }
    srand(time(0));
    unsigned long cntVertices = std::atol(argv[1]);
    unsigned long cntEdges = static_cast<unsigned long>(std::pow(cntVertices, 1.5));
    std::vector<std::vector<Graph::Edge>> vertices(cntVertices + 1);
    unsigned long startVertex, endVertex, weight;
    for (unsigned long m = 1; m <= cntEdges; m++) {
        startVertex = rand() % cntVertices + 1;
        endVertex = rand() % cntVertices + 1;
        weight = rand() % 500 + 1;
        vertices[startVertex].push_back(Graph::Edge(endVertex, weight));
        vertices[endVertex].push_back(Graph::Edge(startVertex, weight));
    }

    Graph graph(vertices, cntVertices, cntEdges);
    startVertex = rand() % cntVertices + 1;
    endVertex = rand() % cntVertices + 1;
    try {
        std::chrono::time_point<std::chrono::system_clock> start, end;
        start = std::chrono::system_clock::now();
        unsigned long long res = graph.dijkstra(startVertex, endVertex);
        end = std::chrono::system_clock::now();
        std::cout << "RES: " << res << "\n";
        std::cout << "COUNT VERTICES: " << cntVertices << ". " << "COUNT EDGES: " << cntEdges << "\n";
        std::cout << "TIME: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "\n";
    } catch (std::logic_error &e) {
        std::cout << e.what() << "\n";
    }

    return 0;
}