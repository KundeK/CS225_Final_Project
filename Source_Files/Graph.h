#pragma once
#include <map>
#include <fstream>
#include "Edge.h"
#include <vector>
using namespace std;

class Graph {

    public:
    //Algs, Djikstra's, PageRank, project Graph on map?


    Graph(); //Default Constructor

    Graph(std::multimap<std::string, std::pair<std::string, std::pair<std::string, std::pair<std::string,
                  std::pair<std::string, std::pair<std::string, std::pair<std::string, std::string>>>>>>> airport_data, std::multimap<std::string, std::pair<std::string, std::pair<std::string, std::pair<std::string,
                  std::pair<std::string, std::string>>>>> route_data);

    
    /**
     * Gets all adjacent vertices to the parameter vertex.
     */
    vector<Vertex> getAdjacent(Vertex source) const;

    /**
     * Returns one random vertex in the graph. 
     */
    Vertex getStartingVertex() const;
    

    /**
     * Gets the edge between two vertices.
     */
    Edge getEdge(Vertex source, Vertex destination) const;


    /**
     * Checks if the given vertex exists.
     */
    bool vertexExists (Vertex v) const;


    /**
     * Checks if edge exists between two vertices exists.
     */
    bool edgeExists(Vertex source, Vertex destination) const;

    /**
     * Gets the edge label of the edge between vertices u and v.
     * if edge exists, return edge label
     * if edge doesn't exist, return InvalidLabel
     */
    std::string getEdgeLabel(Vertex source, Vertex destination) const;

    /**
     * Gets the weight of the edge between two vertices.
     */
    int getEdgeWeight(Vertex source, Vertex destination) const;

    /**
     * Inserts a new vertex into the graph
     */
    void insertVertex(Vertex v);

    /**
     * Inserts an edge between two vertices.
     */
    bool insertEdge(Vertex source, Vertex destination);


    unsigned int getDegree(Vertex node);



    //Below space-time complexity may get large, consider returning just the highest rank airport/5 highest ranked airports - Aadarsh
    Vertex PageRank(); //PageRank Algoirhtm - Krushank, Aadarsh Returns a vector arranging vertices by rank,
    
    std::vector<Edge> Dijkstras(); //Dijkstra's Algorithm - Shaarav, Aadarsh Returns a vector of edges representing shortest path

    private:
        std::map<Vertex, std::map<Vertex, Edge>> adjacency_list; //adajacency list

};