#include "Vertex.h"


//Paramaterized Constructor
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

//Default Constructor
Vertex::Vertex() {
    //Default
}

//Getter for latitude coordinate
//Returns latitude value
double Vertex::getLat() { 
    return lat;
}

//Getter for longitude coordinate
//Returns longitude value
double Vertex::getLong() { 
    return lon;
}

// Helper method for calculating distance
//Parameter: Takes in long double value in degrees
// Returns long double value in terms of radians
long double Vertex::toRadians(long double degree) { //Helper to calc distance
    long double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}

// Getter for Airport Name
// Returns string of airport name
std::string Vertex::getAirportName() { //Getters
   return airport_name_;
}

// Getter for Airport ID
// Returns string of Airport ID
std::string Vertex::getID() const { 
    return airport_id_;
}


//Calculate distance method
// Takes in 4 long doubles, two sets of latitude, longitude coordinates
// Returns 1 long double, representing the Edge weight
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