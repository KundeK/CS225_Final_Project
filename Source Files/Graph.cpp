#include "Graph.h"


std::vector<Vertex> Graph::getAdjacent(Vertex source) const {
    auto lookup = adjacency_list.find(source);

    if (lookup == adjacency_list.end()) {
        return vector<Vertex>();
    } else {
        std::vector<Vertex> vertex_list;
        std::unordered_map <Vertex, Edge> & map = adjacency_list[source];
        for (auto it = map.begin(); it != map.end(); it++) {
            vertex_list.push_back(it->first);
        }
        return vertex_list;
    }
}

Vertex Graph::getStartingVertex() const {
    return adjacency_list.begin()->first;
}
    

Edge Graph::getEdge(Vertex source, Vertex destination) const {
    if (edgeExists(source, destination) == false) {
        return Edge();
    }
    Edge ret = adjacency_list[source][destination];
    return ret;
}


bool Graph::vertexExists (Vertex v) const {
    if (adjacency_list.find(v) == adjacency_list.end()) {
        return false;
    }
    return true;
}

bool Graph::edgeExists(Vertex source, Vertex destination) const {
    if (vertexExists(source) == false) {
        return false;
    }
    if (adjacency_list[source].find(destination)== adjacency_list[source].end()) {
        return false;
    }
    return true;
}

std::string Graph::getEdgeLabel(Vertex source, Vertex destination) const {
    if (edgeExists(source, destination) == false) {
        throw std::invalid_argument("No Edge Exists");
    }
        
    return adjacency_list[source][destination].getLabel();
}

int Graph::getEdgeWeight(Vertex source, Vertex destination) const {
    if (edgeExists(source, destination) == false) {
        return -1;
    }
    return adjacency_list[source][destination].getDistance();
}

void Graph::insertVertex(Vertex v) {
    adjacency_list[v] = unordered_map<Vertex, Edge>();
}

bool Graph::insertEdge(Vertex source, Vertex destination) {
    if (adjacency_list.find(source)!= adjacency_list.end() 
    && adjacency_list[source].find(destination)!= adjacency_list[source].end()) 
    {
        //edge already exists
        return false;
    }
    
    if (adjacency_list.find(source)==adjacency_list.end()) {

        adjacency_list[source] = unordered_map<Vertex, Edge>();
    }
    //vertex exists
    adjacency_list[source][destination] = Edge(source, destination);

    return true;
}
    