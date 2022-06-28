#include "../cs225/catch/catch.hpp"
#include "../graphUtil/graph_builder.h"
#include "../graphAlgorithms/traversals.h"

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

/**
 * The following test cases check on 3 small samples that we hand
 * drew consisting of 0 edges, only one pokémon has edges, and 
 * multiple pokémon have edges
*/
TEST_CASE("Test BFS small - check vertex and edge count", "[bfs]") {
    Graph test_graph;
    GraphBuilder builder;
    builder.addVertices(test_graph, 3);
    builder.addEdges(test_graph);

    Traversals traversal;
    traversal.BFS(test_graph);

    REQUIRE(traversal.getVertices().size() == 3);
    REQUIRE(traversal.getEdges().size() == 0);
}

TEST_CASE("Test BFS med-part1 - check vertex and edge count", "[bfs]") {
    Graph test_graph;
    GraphBuilder builder;
    builder.addVertices(test_graph, 4);
    builder.addEdges(test_graph);

    Traversals traversal;
    traversal.BFS(test_graph);

    REQUIRE(traversal.getVertices().size() == 4);
    REQUIRE(traversal.getEdges().size() == 3);
}

TEST_CASE("Test BFS med-part2 - check vertex and edge count", "[bfs]") {
    Graph test_graph;
    GraphBuilder builder;
    builder.addVertices(test_graph, 9);
    builder.addEdges(test_graph);

    Traversals traversal;
    traversal.BFS(test_graph);

    REQUIRE(traversal.getVertices().size() == 9);
    REQUIRE(traversal.getEdges().size() == 29);
}

/**
 * The following test cases check if the BFS actually traversed
 * the correct vertices and edges. 
*/
TEST_CASE("Test BFS med-part1 - check vertex names", "[bfs]") {
    Graph test_graph;
    GraphBuilder builder;
    builder.addVertices(test_graph, 4);
    builder.addEdges(test_graph);

    Traversals traversal;
    traversal.BFS(test_graph);

    std::vector<std::string> expected_names = {"Bulbasaur", "Ivysaur", "Venusaur", "Charmander"};
    std::vector<std::string> traversed_names;

    for (size_t i = 0; i < traversal.getVertices().size(); i++) {
        traversed_names.push_back(traversal.getVertices().at(i)->getPokemonName());
    }
    std::sort(expected_names.begin(), expected_names.end());
    std::sort(traversed_names.begin(), traversed_names.end());

    REQUIRE(expected_names == traversed_names);
}

TEST_CASE("Test BFS med-part1 - check vertices were visited", "[bfs]") {
    Graph test_graph;
    GraphBuilder builder;
    builder.addVertices(test_graph, 4);
    builder.addEdges(test_graph);

    Traversals traversal;
    traversal.BFS(test_graph);

    for (size_t i = 0; i < traversal.getVertices().size(); i++) {
        REQUIRE(traversal.getVertices().at(i)->getVisited() == true);
    }
}

TEST_CASE("Test BFS med-part1 - check edge names", "[bfs]") {
    Graph test_graph;
    GraphBuilder builder;
    builder.addVertices(test_graph, 4);
    builder.addEdges(test_graph);

    Traversals traversal;
    traversal.BFS(test_graph);

    REQUIRE(traversal.getEdges().at(0)->getStart()->getPokemonName() == "Charmander");
    REQUIRE(traversal.getEdges().at(0)->getEnd()->getPokemonName() == "Bulbasaur");

    REQUIRE(traversal.getEdges().at(1)->getStart()->getPokemonName() == "Charmander");
    REQUIRE(traversal.getEdges().at(1)->getEnd()->getPokemonName() == "Ivysaur");

    REQUIRE(traversal.getEdges().at(2)->getStart()->getPokemonName() == "Charmander");
    REQUIRE(traversal.getEdges().at(2)->getEnd()->getPokemonName() == "Venusaur");
}
