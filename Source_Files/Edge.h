#pragma once
#include "Vertex.h"


class Edge {

    public:
        Edge(); //Default Constructor
        
        //Paramaterized Constructors
        Edge(Vertex start, Vertex end);

        //Getters
        Vertex getStart();
        Vertex getEnd();
        unsigned long getDistance();
        void setDistance(long double dist);
        void setLabel(std::string a);

        //Overloaded operators

        bool operator!=(Edge& other) const {
            if (this->start_airport_ != other.start_airport_) {
                return true;
            }
            if (this->end_airport_ != other.end_airport_) {
                return true;
            }
            if (this->airline_ != other.airline_) {
                return true;
            }
            return false;
        }

    private:
        Vertex start_airport_; //Beginning of edge
        Vertex end_airport_; //End of Edge
        std::string airline_; //Label of edge
        unsigned long distance_; //Weight of edge

};