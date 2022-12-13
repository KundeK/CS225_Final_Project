#pragma once
#include <map>
#include <iostream>
#include <fstream>
#include "Edge.h"
#include <vector>
#include <queue>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;

class Graph {

    public:
    //Algs, Djikstra's, PageRank, project Graph on map?


    Graph(); //Default Constructor

    Graph(std::multimap<std::string, std::pair<std::string, std::pair<std::string, std::pair<std::string,
                  std::pair<std::string, std::pair<std::string, std::pair<std::string, std::string>>>>>>> airport_data, std::multimap<std::string, std::pair<std::string, std::pair<std::string, std::pair<std::string,
                  std::pair<std::string, std::string>>>>> route_data); //Constructor that takes cleaned data

    
    /**
     * Gets all adjacent vertices to the parameter vertex.
     */
    vector<Vertex> getAdjacent(Vertex source) const;
    

    /**
     * Gets the edge between two vertices.
     */
    Edge getEdge(Vertex source, Vertex destination) const;


    /**
     * Checks if the given vertex exists.
     */
    bool vertexExists (Vertex v) const;


    /**
     * Checks if edge exists between two air id's exists.
     */
    bool edgeExists(std::string air_id_1, std::string air_id_2) const;


    /**
     * Checks if edge exists between two vertices exists.
     */
    bool edgeExists(Vertex source, Vertex destination) const;

    /**
    * Helper for Page Rank to get degree of a node
    */
    double getDegree(Vertex node);

    /**
    * Get Vertex from ID of Airport
    */
    Vertex getVertex(std::string id);

    /**
     * Returns one random vertex in the graph. 
     */
    Vertex getStartingVertex() const;

    Vertex PageRank(); //PageRank Algoirhtm - returns busiest airport
    
    std::vector<Edge> Dijkstras(Vertex source, Vertex destination); //Dijkstra's Algorithm shortest path

    void DFS(Vertex start, std::vector<Vertex>& visited); //DFS Traversal of Graph

    std::map<Vertex, std::map<Vertex, Edge>> getAdjacencyList();

    private:
        std::map<Vertex, std::map<Vertex, Edge>> adjacency_list; //adajacency list representation

};