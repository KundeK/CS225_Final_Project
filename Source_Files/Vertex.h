#pragma once
#include <string>
#include <cmath>

class Vertex {

    public:
        Vertex(); //Default constructor
        Vertex(std::string name, std::string id, std::string city, std::string country, std::string iata, std::string icao, std::string lati, std::string longi); 

        //Overloaded operators

        bool operator!=(const Vertex& other) const {
            if (this->airport_id_ != other.airport_id_) {
                return true;
            }
            return false;
        }

        bool operator==(const Vertex& other) const {
            if (this->airport_id_ == other.airport_id_) {
                return true;
            }
            return false;
        }

        bool operator<(const Vertex& other) const {
            if (this->airport_name_ < other.airport_name_) {
                return true;
            }
            return false;
        }

        bool operator>(const Vertex& other) const {
            if (this->airport_name_ < other.airport_name_) {
                return true;
            }
            return false;
        }

        double getLat();
        double getLong();

        long double toRadians(long double degree);
        long double getEdgeWeight(long double lat1, long double long1, long double lat2, long double long2);

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