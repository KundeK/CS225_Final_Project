#include "Edge.h"


//TODO Aadarsh

Edge::Edge() {
    //Default
}

Edge::Edge(Vertex start, Vertex end) {
    start_airport_ = start;
    end_airport_ = end;
}

Edge::Edge(Vertex start, Vertex end, std::string airline, unsigned long distance) {
    start_airport_ = start;
    end_airport_ = end;
    airline_ = airline;
    distance_ = distance;
}

Edge::Edge(Vertex start, Vertex end, std::string airline) {
    start_airport_ = start;
    end_airport_ = end;
    airline_ = airline;
}

Vertex Edge::getStart() { //Getters for instance variables
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

void Edge::setDistance(long double dist) {
    distance_ = dist;
}

void Edge::setLabel(std::string a) {
    airline_ = a;
}