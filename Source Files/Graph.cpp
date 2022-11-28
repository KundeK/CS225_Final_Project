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
    
std::vector<size_t> Graph::PageRank() {

    // PageRank() -> uses graph and needs parameter n, which specifies number of iterations
    
    // vector of vertex initialized as rank;
    
    std::map<Vertex, size_t> rank;
    std::vector<size_t> to_return_ranks; //consider removing this and returning map
    std::vector<Vertex> vertices;
    int d = 0.15;

    size_t N = adjacent_.size();
    // N <- number of nodes in G (number of airports)

    //get all vertices
    for (std::map<Vertex, std::vector<Edge>>::iterator iter = adjacent_.begin(); iter != adjacent_.end(); ++iter) {
        vertices.push_back(iter->first);
    }

    
    // For every node V in Graph:
    //     Initialize the rank of the node to be 1/N 
    //         - Rank(V) = 1/N
    
    for (Vertex v : vertices) {
        to_return_ranks.push_back(1 / N);
        std::pair<Vertex, size_t> pair = std::pair<Vertex, size_t>(v, 1 / N);
        rank.insert(pair);
    }



    // for every vertex in graph
    //     For every node from ui (# of neighbors of current node) and uj (number of nodes with no outlinks) with no outlinks
    //         SUM_OF_RANKS_CALC = sum(rank(ui)/# of outlinks of ui) + sum(rank(uj)/N)
    //         Rank(current node) = (d/N) + (1-d) * SUM_OF_RANKS_CAL

    int sum_rank_ui = 0;
    int sum_rank_uj = 0;
    for (Vertex v : vertices) {
        for (Vertex ui : neighbors) { //need a way to get neighbors
            sum_rank_ui += rank[ui] / (outlink); // need way to find # of outlinks
        }

        for (Vertex uj : no_outlinks) { //need a way to get vertices with no outlinks
            sum_rank_uj += rank[uj] / N;
        }
        rank[v] = (d / N) + (1-d) * (sum_rank_ui + sum_rank_uj);
    } 

    // return rank; return map of vertices with rank
    
}
