#include "Edge.h"



Edge::Edge() {
    //Default constructor
}

//Parameterized Constructor w/ 2 vertices
Edge::Edge(Vertex start, Vertex end) {
    start_airport_ = start;
    end_airport_ = end;
}

//Parameterized Constructor w/ 2 vertices, airline, and distance
Edge::Edge(Vertex start, Vertex end, std::string airline, unsigned long distance) {
    start_airport_ = start;
    end_airport_ = end;
    airline_ = airline;
    distance_ = distance;
}

//Parameterized Constructor w/ 2 vertices, and airline
Edge::Edge(Vertex start, Vertex end, std::string airline) {
    start_airport_ = start;
    end_airport_ = end;
    airline_ = airline;
}

//Getters for instance variables
Vertex Edge::getStart() { 
    return start_airport_;
}
Vertex Edge::getEnd() {
    return end_airport_;
}
std::string Edge::getAirline() {
    return airline_;
}
unsigned long Edge::getDistance() {
    return distance_;
}

//Setters for instance variables
void Edge::setDistance(long double dist) {
    distance_ = dist;
}

void Edge::setLabel(std::string a) {
    airline_ = a;
}