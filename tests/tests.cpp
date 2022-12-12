#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cmath>
#include "../Source_Files/Graph.h"

//Graph Test Cases - Aadarsh

int main (int argc, char** argv) {
    //Test Constructing Graph

    /* AADARSH - ADDED COMMAND LINE ARGUMENT VARIABLE INPUT */

    if (argc != 3) {
        std::cout << "Not enough inputs!" << std::endl;
        return -1;
    }



    //argc = 0;       //Processing doesn't work unless arguments are used at some point
    //**argv = ' ';   //These variables will be modified later on
    //TIME COMPLEXITY IS VASTLY IMPROVED WHEN COMMENTING OUT THE TEST FOR-LOOPS

    //airports.dat
    std::ifstream fin(argv[1]);  //Open file
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
    std::ifstream fin2(argv[2]);    //Open file
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

    //POSITIVE TEST CASES: There should be an edge between LAX and ATL
    if (!g.edgeExists("3484", "3682")) {
        std::cout << "TEST FAILED, THERE SHOULD BE AN EDGE FROM LAX TO ATL" << std::endl; //There should be an edge representing the route from LAX to ATL
    } else {
        std::cout << "TEST PASSED!" << std::endl;
        std::cout << std::endl;
    }

    if (!g.edgeExists("3484", "3759")) {
        std::cout << "TEST FAILED, THERE SHOULD BE AN EDGE FROM LAX TO CMH" << std::endl; //There should be an edge representing the route from LAX to CMH
    } else {
        std::cout << "TEST PASSED!" << std::endl;
        std::cout << std::endl;
    }

    //NEGATIVE TEST CASES: There shouldn't be an edge between LAX and Non-existing airport id
    if (g.edgeExists("3484", "8018")) {
        std::cout << "TEST FAILED, THERE SHOULD NOT BE AN EDGE FROM LAX TO NON EXISTANT" << std::endl; 
    } else {
        std::cout << "TEST PASSED!" << std::endl;
        std::cout << std::endl;
    }

    if (g.edgeExists("3484", "13122")) { //Should not be an edge in truncated dataset from LAX to ID 13112, an airport in Namibia
        std::cout << "TEST FAILED, THERE SHOULD NOT BE AN EDGE FROM LAX TO OTJ" << std::endl; 
    } else {
        std::cout << "TEST PASSED!" << std::endl;
        std::cout << std::endl;
    }



    //TEST PAGE RANK ALG : Should return Denver international airport
    if (g.PageRank().getAirportName() != "\"Denver International Airport\"") {
        std::cout << "TEST FAILED, WRONG PAGE RANK OUTPUT" << std::endl; 
    } else {
        std::cout << "TEST PASSED!" << std::endl;
        std::cout << std::endl;
    }



    return 0;



}



// TEST_CASE("Construct Graph Complex", "[weight=4][part=Graph]") {
    
// }

// TEST_CASE("Construct Graph Edge Case 1", "[weight=4][part=Graph]") {
    
// }

// TEST_CASE("Construct Graph Edge Case 2", "[weight=4][part=Graph]") {
    
// }

//ADD UNIT TEST CASES FOR OTHER PARTS OF CODE