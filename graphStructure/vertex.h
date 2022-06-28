#pragma once

#include <vector>
#include <string>
#include <list>
#include "edge.h"

using std::string;
using std::vector;
using std::list;

class Edge;
class Vertex {
    public:
        /**
         * Default constructor
         */
        Vertex();

        /**
         * Constructor for a vertex. This will hold data about the Pokemon, as well
         * as graph-related data.
         * 
         * @param name the Pokemon's name
         * @param types the Pokemon's type(s)
         * @param effectivenesses a list of type effectivenesses against the Pokemon
         * @param index the Pokemon's Pokedex number
         */
        Vertex(string name, vector<string> types, vector<double> effectiveness, int number);

        /**
         * Destroy the Vertex object
         */
        ~Vertex();

        /**
         * Gets the name of the Pokemon that this vertex represents.
         * 
         * @return the name of the Pokemon 
         */
        std::string getPokemonName();

        /**
         * Gets the types of the Pokemon.
         * 
         * @return a vector of the Pokemon's types
         */
        std::vector<std::string> getPokemonTypes();

        /**
         * Gets a vector of effectiveness of types against the Pokemon.
         * 
         * @return a vector of effectiveness
         */
        std::vector<double> getEffectiveness();

        /**
         * Get the Pokdex number of the Pokemon.
         * 
         * @return the Pokemon's Pokedex number
         */
        int getPokedexNumber();


        // Getters for vertex data
        /**
         * Gets the degree of the vertex (i.e. the number of edges coming out
         * of the vertex).
         * 
         * @return the degree of the vertex
         */
        int getDegree();

        /**
         * Gets the current value of the visited variable. Used in graph traversals
         * as well as graph coloring.
         * 
         * @return a bool representing whether or not the vertex has been visited
         */
        bool getVisited();
        
        /**
         * Gets all Edges that point away from the current vertex.
         * 
         * @return a list of Edges
         */
        std::list<Edge*> getIncidentEdges();

        /**
         * Gets all Edges that point to the current vertex.
         * 
         * @return a list of Edges
         */
        std::list<Edge*> getIncomingEdges();


        // Getters for graph visualization
        /**
         * Gets the current x-coordinate of the center of the vertex. Returns -1
         * if the x-coordinate has not been initialized.
         * 
         * @return an double repesnting the vertex's x-coordinate
         */
        double getX();

        /**
         * Gets the current y-coordinate of the center of the vertex. Returns -1
         * if the y-coordinate has not been initialized.
         * 
         * @return an double repesnting the vertex's y-coordinate
         */
        double getY();

        /**
         * Gets the color ID. Used for the graph-coloring algorithm.
         * 
         * @return an int representing the vertex's color ID
         */
        int getColorID();


        // Setters for vertex data
        /**
         * sets the degree of the vertex (i.e. the number of Edges coming out
         * of the vertex).
         * 
         * @param degree the degree of the vertex
         */
        void setDegree(int degree);

        /**
         * Adds an edge to the list of incident Edges.
         * 
         * @param edge the Edge to be added
         */
        void addIncidentEdge(Edge* edge);

        /**
         * Adds an edge to the list of incoming Edges.
         * 
         * @param edge the Edge to be added
         */
        void addIncomingEdge(Edge* edge);

        /**
         * Sets the current value of the visited variable. Used in graph traversals
         * as well as graph coloring.
         * 
         * @param visited a bool representing whether or not the vertex has been visited
         */
        void setVisited(bool visited);


        // Setters for graph visualization
        /**
         * Sets the vertex's x-coordinate
         * 
         * @param x the x-coordinate to be set
         */
        void setX(double x);

        /**
         * Sets the vertex's y-coordinate
         * 
         * @param x the y-coordinate to be set
         */
        void setY(double y);

        /**
         * Sets the color ID. for the graph-coloring algorithm.
         * 
         * @param colorID an int representing the vertex's color ID
         * 
         */
        void setColorID(int colorID);

        /**
         * Compares two Vertices based on their degree
         * 
         * @param v the other Vertex to compare with
         * 
         */
        bool operator<(const Vertex v) const;

    private:
        // Variables for the Pokemon that the vertex represents
        std::string name_;
        std::vector<std::string> types_;
        std::vector<double> effectiveness_;
        int pokedex_number_;                        

        // Variables for vertex data
        std::list<Edge*> incident_edges_;
        std::list<Edge*> incoming_edges_;
        int degree_;
        bool visited_;

        // Variableles for graph visualization
        double x_;
        double y_;
        int colorID_;
};