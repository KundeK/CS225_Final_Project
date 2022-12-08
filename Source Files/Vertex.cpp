#include "Vertex.h"

//TODO Aadarsh
//ALL COMPILES

Vertex::Vertex(std::string id, std::string name, std::string city, std::string country, std::string iata, std::string icao, std::string lati, std::string longi) {
    airport_name_ = name;
    airport_id_ = id;
    city_ = city;
    country_ = country;
    iata_ = iata;
    icao_ = icao;
    lat = std::stod(lati);
    lon = std::stod(longi);
}

Vertex::Vertex() {
    //Default
}

double Vertex::getLat() {
    return lat;
}
double Vertex::getLong() {
    return lon;
}