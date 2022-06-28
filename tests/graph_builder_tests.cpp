#include "../graphUtil/graph_builder.h"
#include "../cs225/catch/catch.hpp"
#include <iostream>

TEST_CASE("Small graph building", "[builder]") {
    GraphBuilder test_builder;
    Graph test_graph;

    test_builder.addVertices(test_graph, 3);
    test_builder.addEdges(test_graph);

    SECTION("Verticies added to graph correctly") {
        REQUIRE(test_graph.getSize() == 3);
    
        REQUIRE(test_graph.getVertex(0)->getPokemonName() == "Bulbasaur");
        REQUIRE(test_graph.getVertex(0)->getIncidentEdges().size() == 0);
        REQUIRE(test_graph.getVertex(0)->getPokemonTypes()[0] == "grass");
        REQUIRE(test_graph.getVertex(0)->getPokemonTypes()[1] == "poison");

        REQUIRE(test_graph.getVertex(1)->getPokemonName() == "Ivysaur");
        REQUIRE(test_graph.getVertex(1)->getIncidentEdges().size() == 0);
        REQUIRE(test_graph.getVertex(1)->getPokemonTypes()[0] == "grass");
        REQUIRE(test_graph.getVertex(1)->getPokemonTypes()[1] == "poison");


        REQUIRE(test_graph.getVertex(2)->getPokemonName() == "Venusaur");
        REQUIRE(test_graph.getVertex(2)->getIncidentEdges().size() == 0);
        REQUIRE(test_graph.getVertex(2)->getPokemonTypes()[0] == "grass");
        REQUIRE(test_graph.getVertex(2)->getPokemonTypes()[1] == "poison");
    }

    SECTION("Edges were added correctly") {
        REQUIRE(test_graph.getEdges().size() == 0);
        for(size_t index = 0; index < 3; index++) {
            REQUIRE(test_graph.getVertex(index)->getIncidentEdges().size() == 0);
            REQUIRE(test_graph.getVertex(index)->getDegree() == 0);
        }
    }

}

TEST_CASE("Medium graph building", "[builder]") {
    GraphBuilder test_builder;
    Graph test_graph;

    test_builder.addVertices(test_graph, 4);
    test_builder.addEdges(test_graph);

    SECTION("Edges were added correctly") {
        REQUIRE(test_graph.getEdges().size() == 3);
        for(size_t index = 0; index < 3; index++) {
            REQUIRE(test_graph.getVertex(index)->getIncidentEdges().size() == 0);
            REQUIRE(test_graph.getVertex(index)->getDegree() == 0);
        }

        REQUIRE(test_graph.getVertex(3)->getDegree() == 3);
    }
}

TEST_CASE("Larger graph building", "[builder]") {
    GraphBuilder test_builder;
    Graph test_graph;

    test_builder.addVertices(test_graph, 9);
    test_builder.addEdges(test_graph);

    SECTION("Verticies added to graph correctly") {
        REQUIRE(test_graph.getSize() == 9);

        REQUIRE(test_graph.getVertex(0)->getPokemonName() == "Bulbasaur");
        REQUIRE(test_graph.getVertex(0)->getPokemonTypes()[0] == "grass");
        REQUIRE(test_graph.getVertex(0)->getPokemonTypes()[1] == "poison");   

        REQUIRE(test_graph.getVertex(1)->getPokemonName() == "Ivysaur");
        REQUIRE(test_graph.getVertex(1)->getPokemonTypes()[0] == "grass");
        REQUIRE(test_graph.getVertex(1)->getPokemonTypes()[1] == "poison");  

        REQUIRE(test_graph.getVertex(2)->getPokemonName() == "Venusaur");
        REQUIRE(test_graph.getVertex(2)->getPokemonTypes()[0] == "grass");
        REQUIRE(test_graph.getVertex(2)->getPokemonTypes()[1] == "poison");

        REQUIRE(test_graph.getVertex(3)->getPokemonName() == "Charmander");
        REQUIRE(test_graph.getVertex(3)->getPokemonTypes()[0] == "fire");
        REQUIRE(test_graph.getVertex(3)->getPokemonTypes()[1] == "fire");

        REQUIRE(test_graph.getVertex(4)->getPokemonName() == "Charmeleon");
        REQUIRE(test_graph.getVertex(4)->getPokemonTypes()[0] == "fire");
        REQUIRE(test_graph.getVertex(4)->getPokemonTypes()[1] == "fire");

        REQUIRE(test_graph.getVertex(5)->getPokemonName() == "Charizard");
        REQUIRE(test_graph.getVertex(5)->getPokemonTypes()[0] == "fire");
        REQUIRE(test_graph.getVertex(5)->getPokemonTypes()[1] == "flying");

        REQUIRE(test_graph.getVertex(6)->getPokemonName() == "Squirtle");
        REQUIRE(test_graph.getVertex(6)->getPokemonTypes()[0] == "water");
        REQUIRE(test_graph.getVertex(6)->getPokemonTypes()[1] == "water");

        REQUIRE(test_graph.getVertex(7)->getPokemonName() == "Wartortle");
        REQUIRE(test_graph.getVertex(7)->getPokemonTypes()[0] == "water");
        REQUIRE(test_graph.getVertex(7)->getPokemonTypes()[1] == "water");

        REQUIRE(test_graph.getVertex(8)->getPokemonName() == "Blastoise");
        REQUIRE(test_graph.getVertex(8)->getPokemonTypes()[0] == "water");
        REQUIRE(test_graph.getVertex(8)->getPokemonTypes()[1] == "water");
    }

    SECTION("Edges added to graph correctly") {
        REQUIRE(test_graph.getEdges().size() == 29);
        double edge_vals[29] = {2.5, 2.5, 2.75, 2, 2, 2, 2.5, 2.5, 2.75,
            2, 2, 2, 2.5, 2.5, 2.75, 2, 2, 2, 0.5, 3, 3, 3, 0.5, 3, 3, 3, 2.5, 2.5, 2.5};
        for(size_t index = 0; index < 29; index++) {
            REQUIRE(test_graph.getEdges()[index]->getWeight() == edge_vals[index]);
        }
    }

    SECTION("Edges added to verticies correctly") {
        for(size_t index = 0; index < 9; index++) {
            // std::cout << index << std::endl;
            if(index == 5) {
                REQUIRE(test_graph.getVertex(index)->getIncidentEdges().size() == 5);
                REQUIRE(test_graph.getVertex(index)->getDegree() == 5);
                continue;
            }

            REQUIRE(test_graph.getVertex(index)->getIncidentEdges().size() == 3);
            REQUIRE(test_graph.getVertex(index)->getDegree() == 3);
        }
    }



}
