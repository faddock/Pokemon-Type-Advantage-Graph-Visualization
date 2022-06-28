#include <iostream>
#include <string>

#include "graphUtil/data_parser.h"
#include "graphUtil/graph_builder.h"
#include "graphAlgorithms/graph_visualizer.h"
#include "graphAlgorithms/traversals.h"

using namespace std;

int main(int argc, char *argv[]) {
    
    std::string input_file_path = "data/pokemon.csv";
    std::string output_file_path = "test_graph.png";
    int num_of_pokemon = 151;
    bool is_colored = true;
    bool is_scaling = true;
    bool run_bfs = false;

    std::string c;
    std::string s;
    std::string b;
    if(argc > 6) {
        std::cout << "Too many arguments passed in. Only accept max of 4: file_path, number_of_pokemon, is_colored, and is_scaling";
    } else if (argc == 6) {
        input_file_path = argv[1];
        output_file_path = argv[5];
        num_of_pokemon = stoi(argv[2]);
        c = argv[3];
        s = argv[4];
        transform(c.begin(), c.end(), c.begin(), ::tolower);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        is_colored = c.compare("true") == 0 ? true : false;
        is_scaling = s.compare("true") == 0 ? true : false;
    } else if (argc == 5) {
        input_file_path = argv[1];
        num_of_pokemon = stoi(argv[2]);
        c = argv[3];
        s = argv[4];
        transform(c.begin(), c.end(), c.begin(), ::tolower);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        is_colored = c.compare("true") == 0 ? true : false;
        is_scaling = s.compare("true") == 0 ? true : false;
    } else if (argc == 4) {
        num_of_pokemon = stoi(argv[1]);
        c = argv[2];
        s = argv[3];
        transform(c.begin(), c.end(), c.begin(), ::tolower);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        is_colored = c.compare("true") == 0 ? true : false;
        is_scaling = s.compare("true") == 0 ? true : false;      
    } else if (argc == 3) {
        c = argv[1];
        s = argv[2];
        transform(c.begin(), c.end(), c.begin(), ::tolower);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        is_colored = c.compare("true") == 0 ? true : false;
        is_scaling = s.compare("true") == 0 ? true : false;       
    } else if (argc == 2) {
        b = argv[1];
        transform(b.begin(), b.end(), b.begin(), ::tolower);
        if(b.compare("bfs") == 0) {
            run_bfs = true;
        } else {
            num_of_pokemon = stoi(argv[1]);
        } 
    }

    //Graph building
    Graph pkmn_graph;
    GraphBuilder builder(input_file_path);
    builder.addVertices(pkmn_graph, num_of_pokemon);
    builder.addEdges(pkmn_graph);

    //Runs BFS if requested
    if(run_bfs) {
        Traversals traversal;
        traversal.BFS(pkmn_graph);
        for (Vertex * v : traversal.getVertices()) {
            std::cout<<v->getPokemonName()<<std::endl;
        }
        
        return 0;
    }

    //Graph drawing
    GraphVisualizer visualizer = GraphVisualizer(pkmn_graph, is_scaling, is_colored);
    visualizer.drawGraph(pkmn_graph).writeToFile(output_file_path);
    std::cout << "=====Finished saving picture=====" << std::endl;

    return 0;
}
