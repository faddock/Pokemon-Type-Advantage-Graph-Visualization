#include "../cs225/catch/catch.hpp"
#include "../graphUtil/graph_builder.h"
#include "../graphStructure/graph.h"
#include <iostream>

/**
 * Below are tests for the areAdjacent method for the graph
*/
TEST_CASE("Test areAdjacent small", "[graph]") {
    Graph test_graph;
    GraphBuilder builder;
    builder.addVertices(test_graph, 3);
    builder.addEdges(test_graph);

    REQUIRE(test_graph.areAdjacent(*(test_graph.getVertex(0)), *(test_graph.getVertex(1))) == false);
}

// Test if two disconnected pokemon are not adjacent
TEST_CASE("Test areAdjacent med - Not adjacent", "[graph]") {
    Graph test_graph;
    GraphBuilder builder;
    builder.addVertices(test_graph, 4);
    builder.addEdges(test_graph);

    // std::cout<<"Pokemon 1:"<<test_graph.getVertex(0)->name_<<std::endl;
    // std::cout<<"Pokemon 2:"<<test_graph.getVertex(2)->name_<<std::endl;
    REQUIRE(test_graph.areAdjacent(*(test_graph.getVertex(0)), *(test_graph.getVertex(2))) == false);
}

TEST_CASE("Test areAdjacent med - Adjacent", "[graph]") {
    Graph test_graph;
    GraphBuilder builder;
    builder.addVertices(test_graph, 4);
    builder.addEdges(test_graph);

    // std::cout<<"Pokemon 1:"<<test_graph.getVertex(0)->name_<<std::endl;
    // std::cout<<"Pokemon 2:"<<test_graph.getVertex(3)->name_<<std::endl;
    REQUIRE(test_graph.areAdjacent(*(test_graph.getVertex(0)), *(test_graph.getVertex(3))) == true);
}