#include "../cs225/catch/catch.hpp"
#include "../graphUtil/graph_builder.h"
#include "../graphAlgorithms/traversals.h"
#include "../graphAlgorithms/graph_coloring.h"
#include "../graphStructure/vertex.h"

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>

TEST_CASE("Test color 4", "[coloring]") {
    Graph test_graph;
    GraphBuilder builder;
    GraphColoring color;

    builder.addVertices(test_graph, 4);
    builder.addEdges(test_graph);
    color.colorGraph(test_graph);
   
    REQUIRE( color.getChromaticNumber() == 2);
}

TEST_CASE("Test color 9", "[coloring]") {
    Graph test_graph;
    GraphBuilder builder;
    GraphColoring color;

    builder.addVertices(test_graph, 9);
    builder.addEdges(test_graph);
    color.colorGraph(test_graph);

    REQUIRE(color.getChromaticNumber() == 4);
}

TEST_CASE("Test color 20", "[coloring]") {
    Graph test_graph;
    GraphBuilder builder;
    GraphColoring color;

    builder.addVertices(test_graph, 20);
    builder.addEdges(test_graph);
    color.colorGraph(test_graph);

    //couts for testing
    std::cout << " ------------- "<<std::endl;
    std::cout << "chromatic number: " << color.getChromaticNumber() <<std::endl;
    std::cout << " ------------- "<<std::endl;

    //For analysing pokemon data in coloring
    map<int, int> counts;
    map<int, std::vector<Vertex*>> pokemon;

    for (auto v : test_graph.getVertices()) {
        pokemon[v->getColorID()].push_back(v);
    }

    //prints pokemon types and degree and name
    for (auto a : pokemon) {
        // std::cout << a.first << ": ";

        for (auto p : a.second) {
            auto temp = p->getPokemonTypes();
            for (auto t : temp) {
                // std::cout<<t<< " ";                     //print type
            }
            // std::cout<<"("<<p->getDegree()<<")";        //print degree

            // std::cout<<p->getPokemonName()<<" ";        //print name
        // std::cout<<", ";
        }
        // std::cout<<std::endl;
    }

    // std::cout << " ------------- "<<std::endl;

    //generates and prints pokemon color id sums
    for (auto v : test_graph.getVertices()) {
        if (counts.find(v->getColorID()) == counts.end()) {
            counts[v->getColorID()] = 1;       
        } else {
            counts[v->getColorID()] += 1;
        }
    }

    REQUIRE(color.getChromaticNumber() == 6);
}


TEST_CASE("test generate color 20") {
    Graph test_graph;
    GraphBuilder builder;
    GraphColoring color;

    builder.addVertices(test_graph, 20);
    builder.addEdges(test_graph);
    color.colorGraph(test_graph);
    color.generateColors(test_graph);


    REQUIRE(color.vertex_colors.size() == 6);

}
