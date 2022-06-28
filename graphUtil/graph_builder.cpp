#include "graph_builder.h"
#include <string>
#include <vector>

GraphBuilder::GraphBuilder(){
    parser_ = new DataParser("data/pokemon.csv");
}

GraphBuilder::GraphBuilder(std::string file_name) {
    parser_ = new DataParser(file_name);
}

GraphBuilder::~GraphBuilder() {
    delete parser_;
}

void GraphBuilder::addVertices(Graph& target_graph, size_t start, size_t end) {
    for(size_t i = start; i <= end; i++) {
        std::vector<double> effectiveness;
        for(size_t j = 0; j < 18; j++) {
            effectiveness.push_back(parser_->getTypeEffectiveness(i, types_values_.indexToType(j)));
        }
        target_graph.addVertex(parser_->getPokemonName(i), parser_->getPokemonTypes(i), effectiveness, i);
    }
}

void GraphBuilder::addVertices(Graph& target_graph, size_t num) {
    addVertices(target_graph, 1, num);
}

void GraphBuilder::addEdges(Graph& target_graph) {
    for(size_t i = 0; i < target_graph.getSize(); i++) {
        Vertex* v1 = target_graph.getVertex(i);
        for(size_t j = i+1; j < target_graph.getSize(); j++) {
            Vertex* v2 = target_graph.getVertex(j);
            // Two vertices can only have max one possible edge between them (in either direction, or no edge)
            // Therefore, we can call areAdjacent so that we don't add duplicate edge. Similar to undirected graph
            if(!target_graph.areAdjacent(*v1, *v2)) {
                target_graph.addEdge(v1,v2);
            }

        }
    }
}