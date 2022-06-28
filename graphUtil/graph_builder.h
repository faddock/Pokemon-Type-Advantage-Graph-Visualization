#pragma once 

#include "data_parser.h"
#include "type_mapper.h"
#include "../graphStructure/graph.h"

#include <string>

class GraphBuilder {
    public:
        /**
         * Default constructor for the GraphBuilder.
         */ 
        GraphBuilder();

        /**
         *  Constructor for the GraphBuilder based on file
         * 
         * @param file_name file to build the graph from
         */
        GraphBuilder(std::string file_name);

        /**
         * Destroy the Graph Builder object
         */
        ~GraphBuilder();

        /**
         * Adds all the Pokemon with ids start to end
         * 
         * @param target_graph the graph the vertices are added to
         * @param start the first number of the Pokemon being added
         * @param end the last number of the Pokemon being added (inclusive)
         */ 
        void addVertices(Graph& target_graph, size_t start, size_t end);

        /**
         * Adds a certain number of vertices to the graph
         * 
         * @param target_graph the graph the vertices are added to
         * @param num the number of pokemon added to the graph (starting from 1)
         */
        void addVertices(Graph& target_graph, size_t num);

        /**
         * Generates the edges for a certain graph 
         * 
         * @param target_graph the graph the edges are generated for 
         */
        void addEdges(Graph& target_graph);

    private:
        DataParser* parser_;
        TypeMapper types_values_;
};