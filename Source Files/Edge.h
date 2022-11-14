#pragma once
#include "Vertex.h"


class Edge {

    public:
        Edge(); //Default Constructor

    private:
        Vertex start_airport_; //Beginning of edge
        Vertex end_airport_; //End of Edge
        std::string airline_; //Label of edge
        unsigned long amount_of_flight_; //Weight of edge

};