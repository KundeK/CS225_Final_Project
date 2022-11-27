#pragma once
#include <string>

class Vertex {

    public:
        Vertex(); //Default constructor
        Vertex(std::string name, std::string id, std::string city, std::string country, std::string iata, std::string icao, double lati, double longi); 

        //Overloaded operators

        bool operator!=(Vertex& other) const {
            if (this->airport_id_ != other.airport_id_) {
                return true;
            }
            return false;
        }

    private:
        std::string airport_name_;
        std::string airport_id_;
        std::string city_;
        std::string country_;
        std::string iata_;
        std::string icao_;
        double lat;
        double lon;

        //Add any other data needed to store from CSV

};