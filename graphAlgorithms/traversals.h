#pragma once

#include "../graphStructure/graph.h"
#include <vector>
#include <queue>

class Traversals {
    public: 
        Traversals();
        void BFS(Graph& G);
        std::vector<Vertex *> getVertices();
        std::vector<Edge *> getEdges();
    private:
        void BFSHelper(Graph& G, Vertex * v);
        std::vector<Vertex *> vertices_;
        std::vector<Edge *> edges_;

};