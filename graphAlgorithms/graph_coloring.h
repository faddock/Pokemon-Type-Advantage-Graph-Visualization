#pragma once

#include "../graphStructure/graph.h"
#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

class GraphColoring {
    public:
        map<int, cs225::HSLAPixel> vertex_colors;

        void generateColors(Graph& graph);

        // cs225::HSLAPixel getColorIdHSLAVal(Graph& graph, int colorId);

        //empty constructor
        GraphColoring();

        /**
         * @brief Colors the graph using a modified BFS algorithm by assigning 
         * each vertex a unique color Id that maps to a specific color
         * 
         * @param g graph to color on
         */
        void colorGraph(Graph& graph);

        /**
         * @brief grah coloring BFS helper function
         * 
         * @param g graph to color
         * @param v the vertex being looked at
         */
        void colorBFSHelper(Graph& graph, Vertex* vertex);

        //getters
        int getChromaticNumber();

        map<int, cs225::HSLAPixel> getColorMap();

        //setters
        void setChromaticNumber(int num);

    private:
        int chromatic_number;
};