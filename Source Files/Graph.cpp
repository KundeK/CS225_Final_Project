#include "Graph.h"

Graph::Graph() {
    //Default
}

//Runtime depends on size of data: might be horrendous
Graph::Graph(std::multimap<std::string, std::pair<std::string, std::pair<std::string, std::pair<std::string,
                  std::pair<std::string, std::pair<std::string, std::pair<std::string, std::string>>>>>>> airport_data, std::multimap<std::string, std::pair<std::string, std::pair<std::string, std::pair<std::string,
                  std::pair<std::string, std::string>>>>> route_data) {

                    //Traverse through Map, Create a Vertex for Each and Add to Map
                    std::map<std::string, std::pair<double, double>> id_to_latlong;
                    std::map<std::string, Vertex> id_to_vertex;

                    for(auto it = airport_data.cbegin(); it != airport_data.cend(); it++){
                        Vertex port(it->first, it->second.first, it->second.second.first, it->second.second.second.first, it->second.second.second.second.first, it->second.second.second.second.second.first, it->second.second.second.second.second.second.first, it->second.second.second.second.second.second.second);
                        //Add these to adjacency list
                        id_to_vertex.insert({it->first, port});
                        //GONNA NEED A MAP OF AIRPORT ID, to LAT LONG
                        //GONNA NEED MAP OF AIRPORT ID TO VERTEX
                        id_to_latlong.insert({it->first, std::make_pair(port.getLat(), port.getLong())});
                    }

                    //Go through routes data
                    for(auto it = route_data.cbegin(); it != route_data.cend(); it++) {
                        //Add an edge between source airport and dest airport
                        Vertex start = id_to_vertex[it->second.second.second.first];
                        Vertex end = id_to_vertex[it->second.second.second.second.second];
                        Edge e(start, end); //Error could be id doesn't exist in vertices
                        
                        double dist = start.getEdgeWeight(start.getLat(), start.getLong(), end.getLat(), end.getLong());

                        //SET EDGE WEIGHT
                        e.setDistance(dist);
                        
                        //SET AIRLINE LABEL HERE 
                        e.setLabel(it->first);

                        //Check if start vertex exists in map
                        //If it does exist, add to its map
                        if (adjacency_list.find(id_to_vertex[it->second.second.second.first]) == adjacency_list.end()) {
                            std::map<Vertex, Edge> adj;
                            adj.insert({e.getEnd(), e});
                            adjacency_list.insert({e.getStart(), adj});
                        } else { //If it doesn't, create a new insertion in existing map
                            adjacency_list[e.getStart()].insert({e.getEnd(), e});
                        }

                    }



}


Vertex Graph::getStartingVertex() const { //COMPILES
    return adjacency_list.begin()->first;
}

void Graph::insertVertex(Vertex v) {
    //Not needed anymore
}

bool Graph::insertEdge(Vertex source, Vertex destination) {
    return true;
}


unsigned int Graph::getDegree(Vertex node) { //For Krushank's PageRank
    return adjacency_list[node].size();
}


/* Commented for Compiling Purposes - Aadarsh
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
*/
