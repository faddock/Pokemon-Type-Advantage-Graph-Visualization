#include "vertex.h"

Vertex::Vertex(std::string name, std::vector<string> types, 
    std::vector<double> effectiveness, int number) {
    name_ = name;
    types_ = types;
    effectiveness_ = effectiveness;
    pokedex_number_ = number;
    degree_ = 0;

    // Push back an x- and y-coordinate
    x_ = -1;
    y_ = -1;
}

Vertex::~Vertex() {
    types_.clear();
    effectiveness_.clear();
    incident_edges_.clear();
    incoming_edges_.clear();
}

std::string Vertex::getPokemonName() {
    return name_;
}

std::vector<std::string> Vertex::getPokemonTypes() {
    return types_;
}

std::vector<double> Vertex::getEffectiveness() {
    return effectiveness_;
}

int Vertex::getPokedexNumber() {
    return pokedex_number_;
}

int Vertex::getDegree() {
    return degree_;
}

bool Vertex::getVisited() {
    return visited_;
}

std::list<Edge*> Vertex::getIncidentEdges() {
    return incident_edges_;
}

std::list<Edge*> Vertex::getIncomingEdges() {
    return incoming_edges_;
}

double Vertex::getX() {
    return x_;
}

double Vertex::getY() {
    return y_;
}

int Vertex::getColorID() {
    return colorID_;
}

void Vertex::setDegree(int degree) {
    degree_ = degree;
}

void Vertex::addIncidentEdge(Edge* edge) {
    incident_edges_.push_back(edge);
}

void Vertex::addIncomingEdge(Edge* edge) {
    incoming_edges_.push_back(edge);
}

void Vertex::setVisited(bool visited) {
    visited_ = visited;
}

void Vertex::setX(double x) {
    x_ = x;
}

void Vertex::setY(double y) {
    y_ = y;
}

void Vertex::setColorID(int colorID) {
    colorID_ = colorID;
}

bool Vertex::operator<(Vertex v) const {
    return degree_ < v.getDegree();
}