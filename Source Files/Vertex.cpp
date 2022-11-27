#include "Vertex.h"

//TODO Aadarsh

Vertex::Vertex(std::string name, std::string id, std::string city, std::string country, std::string iata, std::string icao, double lati, double longi) {
    airport_name_ = name;
    airport_id_ = id;
    city_ = city;
    country_ = country;
    iata_ = iata;
    icao_ = icao;
    lat = lati;
    lon = longi;
}

Vertex::Vertex() {
    //Default
}