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

long double Vertex::toRadians(long double degree) {
    long double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}

std::string Vertex::getAirportName() {
   return airport_name_;
}


long double Vertex::getEdgeWeight(long double lat1, long double long1, long double lat2, long double long2) {
    lat1 = toRadians(lat1);
    long1 = toRadians(long1);
    lat2 = toRadians(lat2);
    long2 = toRadians(long2);
     
    // Haversine Formula, taken from wikipedia
    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;
 
    long double result = std::pow(std::sin(dlat / 2), 2) +
                          std::cos(lat1) * std::cos(lat2) *
                          std::pow(std::sin(dlong / 2), 2);
 
    result = 2 * asin(sqrt(result));
 
    // Radius of Earth in miles = 3956
    long double radii = 3956;
     
    // Calculate the result
    result = result * radii;
 
    return result;
}