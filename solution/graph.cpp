#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <exception>
#include "graph.hpp"

Graph::Edge::Edge(unsigned long endVertex, unsigned long weight) {
    this->endVertex = endVertex;
    this->weight = weight;
}

Graph::Graph(const std::vector<std::vector<Graph::Edge>> &v, unsigned long cntVertices, unsigned long cntEdges) {
    vertices = v;
    this->cntVertices = cntVertices + 1;
    this->cntEdges = cntEdges;
}

unsigned long long Graph::dijkstra(unsigned long start, unsigned long finish) {
    std::vector<unsigned long long> distance(cntVertices);
    distance.assign(cntVertices, std::numeric_limits<unsigned long long>::max());
    distance[start] = 0;

    std::priority_queue<std::pair<unsigned long long, unsigned long>, 
                        std::vector<std::pair<unsigned long long, unsigned long>>,
                        std::greater<std::pair<unsigned long long, unsigned long>>> Q;

    Q.push(std::make_pair(0ull, start));                   

    while (!Q.empty()) {
        unsigned long minVertex = Q.top().second;
        if (distance[minVertex] < Q.top().first) {
            Q.pop();
            continue;
        }
        Q.pop();

        for (auto edge : vertices[minVertex]) {
            if (distance[edge.endVertex] > distance[minVertex] + edge.weight) {
                distance[edge.endVertex] = distance[minVertex] + edge.weight;
                Q.push(std::make_pair(distance[edge.endVertex], edge.endVertex));
            }
        }
    }

    if (distance[finish] == std::numeric_limits<unsigned long long>::max()) {
        throw std::logic_error("No solution");
    }

    return distance[finish];
}