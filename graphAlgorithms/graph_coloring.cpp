#include "graph_coloring.h"
#include <iostream>

using cs225::HSLAPixel;

GraphColoring::GraphColoring() { };

void GraphColoring::generateColors(Graph& g) {
    int c = 0;
    double step = 210 / chromatic_number;
    double curr = 150.0;
     
    for (int c = 1; c <= chromatic_number; c++) {
        HSLAPixel p(curr, 1, 0.5);
        vertex_colors[c] = p;
        curr += step;
    }
}    

map<int, cs225::HSLAPixel> GraphColoring::getColorMap() {
    return vertex_colors;
}

int GraphColoring::getChromaticNumber() {
    return chromatic_number;
}

void GraphColoring::setChromaticNumber(int num) {
    chromatic_number = num;
}

void GraphColoring::colorGraph(Graph& g) {
    chromatic_number = 0;
    for (auto v : g.getVertices()) {
        v->setVisited(false);
        v->setColorID(1);
    }

    for (Vertex * v :g. getVertices()) {
        if (v->getVisited() == false) {
            colorBFSHelper(g, v);
        }
    }

}

void GraphColoring::colorBFSHelper(Graph& g, Vertex * v) {

    std::queue<Vertex *> BFS_queue;
    v->setVisited(true);
    BFS_queue.push(v);

    while (!BFS_queue.empty()) {
        Vertex * front = BFS_queue.front();
        BFS_queue.pop();

        //combining INCIDENT and INCOMING edges
        std::list<Edge*> temp = front->getIncomingEdges();
        temp.merge(front->getIncidentEdges());
        temp.sort();
        
        for (Edge * e : temp) {          
            //getting vertex at other end of edge
            Vertex * end_vertex = NULL;
            if (e->getStart() == front) {
                end_vertex = e->getEnd();
            } 
            else {
                end_vertex = e->getStart();
            }

            //incrementing end_vertex's color id if adjacent color ids are same
            if (e->getStart()->getColorID() == e->getEnd()->getColorID()) {
                end_vertex->setColorID(end_vertex->getColorID() + 1);

                if (end_vertex->getColorID() > chromatic_number) {
                    chromatic_number = end_vertex->getColorID();
                }
            }

            //updating queue and visited state for BFS
            if (end_vertex->getVisited() == false) { 
                end_vertex->setVisited(true);
                BFS_queue.push(end_vertex);
            }
        }
    }
}