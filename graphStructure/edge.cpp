#include "edge.h"

Edge::Edge(Vertex* start, Vertex* end, float weight){
    weight_ = weight;
    start_ = start;
    end_ = end;
}

Edge::~Edge() {
    start_ = NULL;
    end_ = NULL;
}

Vertex * Edge::getStart() {
    return start_;
}

Vertex * Edge::getEnd() {
    return end_;
}

float Edge::getWeight() {
    return weight_;
}

bool Edge::getVisited() {
    return visited_;
}

void Edge::setWeight(float weight) {
    weight_ = weight;
}

void Edge::setVisited(bool visited) {
    visited_ = visited;
}
        