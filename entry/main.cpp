//#include "Graph.h"     Can uncomment once Graph class is implemented, otherwise errors
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cmath>

#include "/workspaces/CS225_2/Final Project/CS225_Final_2/CS225_Final_Project/Source Files/Graph.h"

int main(int argc, char** argv) {
    //DO DATA PROCESSING HERE, FEED IN PATH TO CSV FILE THROUGH TERMINAL
    //READ FROM CSV FILE BY CALLING extractCSVData Method
    //TODO Shreyas, Shaarav
    argc = 0;       //Processing doesn't work unless arguments are used at some point
    **argv = ' ';   //These variables will be modified later on
    //TIME COMPLEXITY IS VASTLY IMPROVED WHEN COMMENTING OUT THE TEST FOR-LOOPS

    //airports.dat
    std::ifstream fin("airports.dat");  //Open file
    if(!fin){                           //Checking if file open
        std::cout << "Could not open file" << std::endl;
        return -1;
    }
    std::multimap<std::string, std::pair<std::string, std::pair<std::string, std::pair<std::string,
                  std::pair<std::string, std::pair<std::string, std::pair<std::string, std::string>>>>>>> data; //Map data structure
    std::string line = "";
    
    while(getline(fin, line)){               //Reading CSV data into Map
        //std::cout << line << std::endl;    //Raw data output
        std::string AirportID, Name, City, Country, IATA, ICAO, Lat, Long;      //Data attributes
        std::stringstream inputString(line);
        getline(inputString, AirportID, ',');
        getline(inputString, Name, ',');
        getline(inputString, City, ',');
        getline(inputString, Country, ',');
        getline(inputString, IATA, ',');
        if(IATA == "\\N"){      //Removing NULL values
            IATA = "";
        }
        getline(inputString, ICAO, ',');
        if(ICAO == "\\N"){      //Removing NULL values
            ICAO = "";
        }
        getline(inputString, Lat, ',');
        getline(inputString, Long, ',');

        if(Country == "\"United States\""){     //Limiting data to US airports  
            data.insert(std::make_pair(AirportID, std::make_pair(Name, std::make_pair(City, std::make_pair(Country, 
                        std::make_pair(IATA, std::make_pair(ICAO, std::make_pair(Lat, Long))))))));
        }
    }
    fin.close();

    //For-loop for map data-verification, should be commented out unless testing
    // for(auto it = data.cbegin(); it != data.cend(); it++){
    //     std::cout << it->first << ", " << 
    //                  it->second.first << ", " << 
    //                  it->second.second.first << ", " << 
    //                  it->second.second.second.first << ", " <<
    //                  it->second.second.second.second.first << ", " << 
    //                  it->second.second.second.second.second.first << ", " <<
    //                  it->second.second.second.second.second.second.first << ", " << 
    //                  it->second.second.second.second.second.second.second << std::endl; 
    // }


    //routes.dat
    std::ifstream fin2("routes.dat");    //Open file
    if(!fin2){                           //Checking if file open
        std::cout << "Could not open file" << std::endl;
        return -1;
    }
    std::multimap<std::string, std::pair<std::string, std::pair<std::string, std::pair<std::string,
                  std::pair<std::string, std::string>>>>> data2; //Map data structure
    std::string line2 = "";
    
    while(getline(fin2, line2)){               //Reading CSV data into Map
        //std::cout << line << std::endl;      //Raw data output
        std::string Airline, AirlineID, SourceAir, S_AirID, DestAir, D_AirID; //Data attributes
        std::stringstream inputString(line2);
        getline(inputString, Airline, ',');
        getline(inputString, AirlineID, ',');
        getline(inputString, SourceAir, ',');
        getline(inputString, S_AirID, ',');
        getline(inputString, DestAir, ',');
        getline(inputString, D_AirID, ',');

        bool flag1 = false;
        bool flag2 = false;
        for(auto it = data.cbegin(); it != data.cend(); it++){
            if(it->first == S_AirID){
                flag1 = true;
            }
            if(it->first == D_AirID){
                flag2 = true;;
            }
        }
        if(flag1 && flag2){     //Limiting data to US airports
            data2.insert(std::make_pair(Airline, std::make_pair(AirlineID, std::make_pair(SourceAir, 
                             std::make_pair(S_AirID, std::make_pair(DestAir, D_AirID))))));
        }
    }
    fin2.close();

    //For-loop for map data-verification, should be commented out unless testing
    // for(auto it = data2.cbegin(); it != data2.cend(); it++){
    //     std::cout << it->first << ", " << 
    //                  it->second.first << ", " << 
    //                  it->second.second.first << ", " << 
    //                  it->second.second.second.first << ", " <<
    //                  it->second.second.second.second.first << ", " << 
    //                  it->second.second.second.second.second << std::endl; 
    // }


    Graph g(data, data2);
    return 0;
}



