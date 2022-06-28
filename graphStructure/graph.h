#pragma once

#include <string>
#include <vector>
#include <map>
#include "vertex.h"
#include "edge.h"
#include "../graphUtil/type_mapper.h"

class Graph {
    public:        
        /**
         * Construct a new Graph object
         */
        Graph();

        /**
         * Destroy the Graph object
         */
        ~Graph();
        
        /**
         * Checks if two vertexes are adjacent
         * Uses the isStronger helper to see which vertex could potentially have the edge
         * By checking incident edges, this function also confirms that edge connections were made properly
         * 
         * @param v1 first vertex to compare
         * @param v2 second vertex to compare
         * 
         * @return true if two vertices have a edge between them
         * @return false if two vertices have no edge between them
         */
        bool areAdjacent(Vertex & v1, Vertex & v2);

        /**
         * Adds vertices to the vector of vertices
         * 
         * @param name The Pokemon's name
         * @param types The types of the Pokemon
         * @param advantages The advantage with each type
         * @param pokedex_number The index/id for the Pokemon
         */
        void addVertex(string name, std::vector<std::string> types, std::vector<double> advantages, int pokedex_number);

        /**
         * Adds an Edge between two vertices passed in as parameters
         * 
         * @param v1 first vertex to add to edge
         * @param v2 second vertex to add to edge
         */
        void addEdge(Vertex* v1, Vertex* v2);

        /**
         * Get all of the verticies in the graph
         * 
         * @return std::vector<Vertex *> all the vertices in the graph
         */
        std::vector<Vertex *> getVertices();

        /**
         * Get all the edges in the graph
         * 
         * @return std::vector<Edge*> all the edges in the graph
         */
        std::vector<Edge*> getEdges();

        /**
         * Get the number of verticies in the graph
         * 
         * @return size_t number of vertices in the graph
         */
        size_t getSize();

        /**
         * Get the Vertex object
         * 
         * @param i index of the vertex to get
         * @return Vertex* pointer to the vertex
         */
        Vertex* getVertex(int i);

        /**
         * Prints all of the edges stored in the graph
         */
        void printEdges();

    private:
        std::vector<Vertex *> vertices_;
        std::vector<Edge *> edges_;
        TypeMapper types_values_;

        /**
         * Helper function for areAdjacent function
         * 
         * @param v1 first vertex to compare
         * @param v2 second vertex t compare
         * @return true if v1 is stronger than v2
         * @return false if v1 is not stronger than v2
         */
        bool _isStronger(Vertex * v1, Vertex * v2);

};