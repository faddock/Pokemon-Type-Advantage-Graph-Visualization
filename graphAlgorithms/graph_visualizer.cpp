#include "graph_visualizer.h"

using cs225::HSLAPixel;
using cs225::PNG;

GraphVisualizer::GraphVisualizer(Graph& graph, bool resize_vertices, bool color_graph) {
    vertices_ = graph.getVertices();
    
    resize_vertices_ = resize_vertices;
    color_graph_ = color_graph;
    image_size_ = vertices_.size() * 20;

    //determine whether to color a graph or not 
    if(color_graph_) {
        coloring_.colorGraph(graph);
        coloring_.generateColors(graph);
        color_map_ = coloring_.getColorMap();
    }

    //randomize vertex locations
    for (Vertex* vertex : vertices_) {
        vertex->setX(std::rand() % int(image_size_));
        vertex->setY(std::rand() % int(image_size_));
    }

    simulateGraphForce(graph);
}

void GraphVisualizer::simulateGraphForce(Graph& graph) {
    std::cout << "====Simulating graph force... Please wait====" << std::endl;
    for (size_t simulation = 0; simulation < kNumSimulations; simulation++) {
        for (size_t i = 0; i < vertices_.size(); i++) {
            for (size_t j = i; j < vertices_.size(); j++) {
                // Need to make sure that we aren't checking a vertex with itself
                if (vertices_[i] != vertices_[j]) {
                    double distance = calculateDistance(vertices_[i]->getX(), vertices_[i]->getY(), 
                        vertices_[j]->getX(), vertices_[j]->getY());
                    double vertex_force; // May need to move this somewhere outside of the loop
                    if (graph.areAdjacent(*vertices_[i], *vertices_[j])) {
                        vertex_force = calculateSpringForce(vertices_[i], vertices_[j]);
                    }
                    else {
                        vertex_force = calculateCoulombicForce(vertices_[i], vertices_[j]);
                    }

                    double new_distance = kC4 * vertex_force;

                    // Need to get the new x and y coordinate of the current vertex v
                    double new_x = new_distance * std::sin(getAngle(vertices_[i], vertices_[j]));
                    double new_y = new_distance * std::cos(getAngle(vertices_[i], vertices_[j]));

                    // Move the current vertex in the proper direction
                    if (vertices_[j]->getX() < vertices_[i]->getX()) {
                        vertices_[i]->setX(vertices_[i]->getX() - new_x);
                    }
                    else {
                        vertices_[i]->setX(vertices_[i]->getX() + new_x);
                    }

                    if (vertices_[j]->getY() < vertices_[i]->getY()) {
                        vertices_[i]->setY(vertices_[i]->getY() - new_y);
                    }
                    else {
                        vertices_[i]->setY(vertices_[i]->getY() + new_y);
                    }
                }
            }
        }
    }
    std::cout << "=======Simulation finished=======" << std::endl;
}

double GraphVisualizer::calculateSpringForce(Vertex* first, Vertex* second) {
    double distance = calculateDistance(first->getX(), first->getY(), second->getX(), second->getY());
    return kC1*log(distance/kC2);
}

double GraphVisualizer::calculateCoulombicForce(Vertex* first, Vertex* second) {
    double distance = calculateDistance(first->getX(), first->getY(), second->getX(), second->getY());
    return kC3/(distance*distance);
}

double GraphVisualizer::calculateDistance(size_t x1, size_t y1, size_t x2,  size_t y2) {
    double distance = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    if (distance < kC2) {
        return kC2;
    }
    return distance;
}

double GraphVisualizer::getAngle(Vertex* first, Vertex* second) {
    int x1 = first->getX();
    int y1 = first->getY();

    int x2 = second->getX();
    int y2 = second->getY();

    double opposideSide = std::abs(y2 - y1);
    double adjacentSide = std::abs(x2 - x1);
    
    if (adjacentSide == 0) {
        return M_PI/2;
    }

    // TODO: This angle is in radians; put this in the .h comment
    return std::atan(opposideSide/adjacentSide);
}

PNG GraphVisualizer::drawGraph(Graph& graph) {
	std::cout << "=====Drawing graph... Please wait=====" << std::endl;
	PNG picture;
    picture.resize(image_size_, image_size_);
    for(size_t x = 0; x < image_size_; x++) {
        for(size_t y = 0; y < image_size_; y++) {
            picture.getPixel(x,y).a = 0;
        }
    }
    
	for(Edge * e: graph.getEdges()) {
		drawLine(&picture, e);
	}

    // Sorts the vertices in descending order of vertex degree.
    std::sort(vertices_.begin(), vertices_.end(), pointerCompare);
    std::reverse(vertices_.begin(), vertices_.end());
    
    double max_degree_ = vertices_.at(0)->getDegree();

    // Draw each vertex
	for(Vertex * v: vertices_) {
        drawVertex(&picture, v);
        
    }
    std::cout << "========Finished drawing========" << std::endl;
    std::cout << "=====Saving picture to file=====" << std::endl;
    return picture;
}

void GraphVisualizer::drawLine(PNG* png, Edge* e) {
	double x1 = e->getStart()->getX();
    double y1 = e->getStart()->getY();
	double x2 = e->getEnd()->getX(); 
	double y2 = e->getEnd()->getY();

    //find the longer direction which represents more pixels being drawn
    double x = x2 - x1;
    double y = y2 - y1;
    const double max = std::max(abs(x), abs(y));    
    x /= max;
    y /= max;

    //determine what color to make the edge and the rate of color change
    double step = (150)/max;
    HSLAPixel p(150, 1, 0.5, (e->getWeight()/8));

    //draws edge by pixel
    for(double n = 0; n < max; ++n) {
        if(png->getPixel(x1, y1).a < p.a) {
            png->getPixel(x1, y1) = p;
        }
        p.h -= step;
        x1 += x;
        y1 += y;
    }
}

void GraphVisualizer::drawVertex(PNG* png, Vertex* v) {
    int degree = v->getDegree();
    double x = v->getX();
    double y = v->getY();

    int radius = kScaleConst * degree + kRadius;

    // Check if the radius of each vertex should be resized based on constructor parameters
    if (!resize_vertices_) {
        radius = kRadius;
    }

    if (color_graph_) {
        drawCircle(png, x, y, radius, color_map_[v->getColorID()]);
    }
    else {
        HSLAPixel white(0, 0, 1);
        drawCircle(png, x, y, radius, white);
    }

}

bool GraphVisualizer::pointerCompare(Vertex * v1, Vertex * v2) {
    return (*v1) < (*v2);
}

void GraphVisualizer::drawCircle(PNG* image, size_t x, size_t y, size_t radius, const HSLAPixel& color) {
    size_t maxdx = radius;
    for (size_t dy = 1; dy <= radius; ++dy) {
        for (size_t dx = maxdx; dx <= maxdx; --dx) {
            if (dx * dx + dy * dy <= radius * radius) {
                for (size_t currentX = x - dx; currentX <= x + dx; ++currentX) {
                        image->getPixel(currentX, y + dy) = color;
                        image->getPixel(currentX, y - dy) = color;
                        image->getPixel(currentX, y) = color;
                }
            maxdx = dx;
            break;
            }
        }
    }
}