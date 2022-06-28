#include "traversals.h"
#include <iostream>

Traversals::Traversals() { }

void Traversals::BFS(Graph& G) {
    for (Vertex * v : G.getVertices()) {
        v->setVisited(false);
    }
    for (Edge * e : G.getEdges()) {
        e->setVisited(false);
    }

    for (Vertex* v : G.getVertices()) {
        if (v->getVisited() == false) {
            BFSHelper(G, v);
        }
    }
}

void Traversals::BFSHelper(Graph& G, Vertex * v) {
    std::queue<Vertex *> q;
    v->setVisited(true);
    q.push(v);

    while (!q.empty()) {
        Vertex * front = q.front();
        q.pop();
        
        vertices_.push_back(front);

        for (Edge * e : front->getIncidentEdges()) {
            Vertex * w = NULL;
            if (e->getStart() == front) {
                w = e->getEnd();
            } else {
                w = e->getStart();
            }
            if (w->getVisited() == false) {
                e->setVisited(true);
                w->setVisited(true);
                edges_.push_back(e);
                q.push(w);
            } else if (e->getVisited() == false) {
                e->setVisited(true);
                edges_.push_back(e);
            }
        }
    }
}

std::vector<Vertex *> Traversals::getVertices() {
    return vertices_;
}

std::vector<Edge *> Traversals::getEdges() {
    return edges_;
}