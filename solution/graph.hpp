#ifndef GRAPH_HPP
#define GRAPH_HPP 1

#include <vector>

class Graph {
public:
    struct Edge {
        unsigned long endVertex;
        unsigned long weight;

        Edge(unsigned long endVertex, unsigned long weight);
    };
private:
    std::vector<std::vector<Graph::Edge>> vertices;
    unsigned long cntVertices;
    unsigned long cntEdges;
public:
    Graph(const std::vector<std::vector<Graph::Edge>> &v, unsigned long cntVertices, unsigned long cntEdges);
    unsigned long long dijkstra(unsigned long start, unsigned long finish);
};

#endif // GRAPH_HPP