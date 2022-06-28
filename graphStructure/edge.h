#pragma once

#include <utility>  
#include "vertex.h"

class Vertex;
class Edge {
    public:
        /**
         * Default constructor
         */
        Edge();
        
        /**
         * Creates an edge for two vertices and a weight
         * 
         * @param start vertex the edge goes out of 
         * @param end  vertext the edge goes into 
         * @param weight cost of the edge
         */
        Edge(Vertex* start, Vertex* end, float weight);

        /**
         * Destroy the Edge object
         */
        ~Edge();

        /**
         * Get the Start object
         * 
         * @return Vertex* pointer to the starting vertex
         */
        Vertex * getStart();

        /**
         * Get the End object
         * 
         * @return Vertex* pointer to the ending vertex
         */
        Vertex * getEnd();

        /**
         * Get the weight of the edge
         * 
         * @return float the weight of the edge
         */
        float getWeight();

        /**
         * Set the value for the weight
         * 
         * @param weight new weight of the edge
         */
        void setWeight(float weight);

        /**
         * Get the whether the object is visisted
         * 
         * @return true if the edge is visited
         * @return false if the edge is not visited
         */
        bool getVisited();
        
        /**
         * Set whether the edge is visited
         * 
         * @param visited new visited status of the edge
         */
        void setVisited(bool visited);

    private:
        float weight_;
        
        Vertex* start_;
        
        Vertex* end_;

        bool visited_;
};