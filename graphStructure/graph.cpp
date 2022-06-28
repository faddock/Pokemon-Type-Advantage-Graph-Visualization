#include "graph.h"
#include <iostream>
#include <queue>

using namespace std;

Graph::Graph() { }

Graph::~Graph() {
    for(size_t i = 0; i < vertices_.size(); i++) {
        delete vertices_[i];
        vertices_[i] = NULL;
    }

    for(size_t i = 0; i < edges_.size(); i++) {
        delete edges_[i];
        edges_[i] = NULL;
    }

    vertices_.clear();
    edges_.clear();
}

bool Graph::areAdjacent(Vertex & v1, Vertex & v2) {
    if (_isStronger(&v1, &v2)) {
        for (Edge * edge : v1.getIncidentEdges()) {
            if (edge->getStart() == &v2 || edge->getEnd() == &v2) {
                return true;
            }
        }
    } else if (_isStronger(&v2, &v1)) {
        for (Edge * edge : v2.getIncidentEdges()) {
            if (edge->getStart() == &v1 || edge->getEnd() == &v1) {
                return true;
            }
        }
    }
    
    return false;
}

void Graph::addVertex(string name, vector<string> type, vector<double> effectiveness, int index) {
    Vertex * to_add = new Vertex(name, type, effectiveness, index);
    vertices_.push_back(to_add);
}

void Graph::addEdge(Vertex* v1, Vertex* v2) {
    // Addes the two advantage rating of v1 with v2
    double v2_against_v1 = v1->getEffectiveness()[types_values_.typeToIndex(v2->getPokemonTypes()[0])-1] 
        + v1->getEffectiveness()[types_values_.typeToIndex(v2->getPokemonTypes()[1])-1];
    // Addes the two advantage rating of v2 with v1
    double v1_against_v2 = v2->getEffectiveness()[types_values_.typeToIndex(v1->getPokemonTypes()[0])-1] 
        + v2->getEffectiveness()[types_values_.typeToIndex(v1->getPokemonTypes()[1])-1];

    if(v2_against_v1 > v1_against_v2) {
        // Adds edge to total list of edges
        Edge * to_add = new Edge(v2, v1, v2_against_v1 - v1_against_v2);
        edges_.push_back(to_add);

        v2->addIncidentEdge(to_add);
        v1->addIncomingEdge(to_add);
        v2->setDegree(v2->getDegree() + 1);

    } else if (v2_against_v1 < v1_against_v2) {
        // Adds edge to total list of edges
        Edge * to_add = new Edge(v1, v2, v1_against_v2 - v2_against_v1);
        edges_.push_back(to_add);

        v1->addIncidentEdge(to_add);
        v2->addIncomingEdge(to_add);
        v1->setDegree(v1->getDegree() + 1);
    }
}

size_t Graph::getSize() {
    return vertices_.size();
}

Vertex* Graph::getVertex(int i) {
    return vertices_.at(i);
}

std::vector<Vertex *> Graph::getVertices() {
    return vertices_;
}

std::vector<Edge*> Graph::getEdges() {
    return edges_;
}

void Graph::printEdges() {
    for(Edge * e: edges_) {
        std::cout << e->getStart()->getPokemonName() << "--" << e->getWeight() << "-->" << e->getEnd()->getPokemonName() << std::endl;
    }
}

bool Graph::_isStronger(Vertex * v1, Vertex * v2) {
    // Multiplies the two advantage rating of v1 with v2
    double v2_against_v1 = v1->getEffectiveness()[types_values_.typeToIndex(v2->getPokemonTypes()[0])-1] 
        + v1->getEffectiveness()[types_values_.typeToIndex(v2->getPokemonTypes()[1])-1];
    // Multiplies the two advantage rating of v2 with v1
    double v1_against_v2 = v2->getEffectiveness()[types_values_.typeToIndex(v1->getPokemonTypes()[0])-1] 
        + v2->getEffectiveness()[types_values_.typeToIndex(v1->getPokemonTypes()[1])-1];

    return v1_against_v2 > v2_against_v1 ? true : false;
}