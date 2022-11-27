#pragma once
#include <map>
#include <fstream>
#include "Edge.h"
#include <vector>

class Graph {

    public:
    //Algs, Djikstra's, PageRank, project Graph on map?
    Graph();
    void buildGraph(); //Temp, will change - Aadarsh

    //Below space-time complexity may get large, consider returning just the highest rank airport/5 highest ranked airports - Aadarsh
    std::vector<size_t> PageRank(); //PageRank Algoirhtm - Krushank, Aadarsh Returns a vector arranging vertices by rank,
    
    std::vector<Edge> Dijkstras(); //Dijkstra's Algorithm - Shaarav, Aadarsh Returns a vector of edges representing shortest path

    private:
        //COMPLETE, IGNORE Decide how to implement graph, adjacency matrix, etc.
        std::map<Vertex, std::map<Vertex, Edge>> adjacent_; //adajacency list

};