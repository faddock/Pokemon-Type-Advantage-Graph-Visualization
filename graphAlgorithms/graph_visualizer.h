#pragma once 

#include "../graphStructure/graph.h"
#include "../graphAlgorithms/graph_coloring.h"
#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"

#include <cmath>
#include <random>
#include <vector>

using cs225::PNG;
using cs225::HSLAPixel;
using std::vector;


class GraphVisualizer {
    public:
        /**
         * Default constructor.
         */
        GraphVisualizer();
        
        /**
         * Construct a new Graph Visualizer object
         * 
         * @param graph to visualize
         * @param resize_vertices whether to resize the pixels based on degree
         * @param color_graph whether to color verticies
         */
        GraphVisualizer(Graph& graph, bool resize_vertices, bool color_graph);

        /**
         * Draws the given graph to a PNG
         * 
         * @param graph the graph to draw
         * @return PNG containing the drawn graph
         */
        PNG drawGraph(Graph& graph);

    private:
        //default size but changes based on number of vertices
        size_t image_size_ = 2000;
        
        //constants for verticies
        std::vector<Vertex*> vertices_;
        bool resize_vertices_;
        size_t kRadius = 3;
        double kScaleConst = 0.075;
        
        // Constants for the simulation and physics algorithms
        size_t kNumSimulations = 100;
        int kC1 = 1;
        int kC2 = 5;
        int kC3 = 1;
        double kC4 = 0.05;

        // variables for drawing image with color
        GraphColoring coloring_;
        std::map<int, cs225::HSLAPixel> color_map_;
        bool color_graph_;

        /**
         * Find the attractive force between two points given the edge and the vertex
         * 
         * @param first the first vertex being compared
         * @param second the second vertex being compared
         * @return (double) the force between the two verticies
         */
        double calculateSpringForce(Vertex* first, Vertex* second);

        /**
         * Find the repulsive force between two points given the edge and the vertex
         * 
         * @param first the first vertex being compared
         * @param second the second vertex being compared
         * @return (double) the force between the two verticies
         */
        double calculateCoulombicForce(Vertex* first, Vertex* second);

        /**
         * Runs the simulation to move vertices to the proper position according to section 12.2
         * of this handbook: https://cs.brown.edu/people/rtamassi/gdhandbook/chapters/force-directed.pdf
         * 
         * @param graph the graph
         */
        void simulateGraphForce(Graph& graph);
        
        /**
         * Return the distance between two 2-d points
         * 
         * @param x1 x-coord of first coordinate
         * @param y1 y-coord of first coordinate
         * @param x2 x-coord of second coordinate
         * @param y2 y-coord of second coordinate
         * @return double distance between the points
         */
        double calculateDistance(size_t x1, size_t y1, size_t x2, size_t y2);

        /**
         * Get the angle between two verticies
         * 
         * @param first first vertex to compare
         * @param second second vertex to compare
         * @return double the angle between the two veticies
         */
        double getAngle(Vertex* first, Vertex* second);

        /**
         * Draws an edge on the given png
         * 
         * @param png the image to draw the edge on
         * @param e the edge to draw
         */
        void drawLine(PNG* png, Edge* e);

        /**
         * Draws a vertex on a given png 
         * 
         * @param png the image to draw the vertex on
         * @param v the vertex to draw
         */
        void drawVertex(PNG* png, Vertex* v);

        /**
         * Circle drawing and filling helper function for drawVertex
         * 
         * @param image the image to draw the circle on
         * @param x x coordinate center of the node
         * @param y y coordinate center of the node
         * @param radius radius of the node
         * @param color HSLAPixel color of node
         */
        void drawCircle(PNG* image, size_t x, size_t y, size_t radius, const HSLAPixel& color);


        /**
         * Checks if two pointers are the same
         * 
         * @param v1 first vertex pointer
         * @param v2 second vertex pointer
         * @return true if the pointers are the same
         * @return false if the pointers are different
         */
        static bool pointerCompare(Vertex * v1, Vertex * v2);
};