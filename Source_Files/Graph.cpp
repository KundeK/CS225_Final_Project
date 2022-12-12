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
    (void)v;
}

bool Graph::insertEdge(Vertex source, Vertex destination) {
    return true;
}


unsigned int Graph::getDegree(Vertex node) { //For Krushank's PageRank
    return adjacency_list[node].size();
}


//Finished, needs to be tested
Vertex Graph::PageRank() {
    
    // vector of vertex initialized as rank;
    //adjacency_list (Key->Vertex, Value-> Map of Vertex and Key)
    std::map<Vertex, double> rank;
    std::vector<Vertex> vertices;
    int d = 0.15;

    // N <- number of nodes in G (number of airports)

    //get all vertices
    for (std::map<Vertex, std::map<Vertex, Edge>>::iterator iter = adjacency_list.begin(); iter != adjacency_list.end(); ++iter) {
        vertices.push_back(iter->first);
    }
    double N = (double) vertices.size();
    Vertex startingVertex = vertices[0];
    
    // For every node V in Graph:
    //     Initialize the rank of the node to be 1/N 
    //         - Rank(V) = 1/N
    
    for (Vertex v : vertices) {
        std::pair<Vertex, double> pair = std::pair<Vertex, size_t>(v, 1 / N);
        rank.insert(pair);
    }

    // for every vertex in graph
    //     For every node from ui (# of neighbors of current node) and uj (number of nodes with no outlinks) with no outlinks
    //         SUM_OF_RANKS_CALC = sum(rank(ui)/# of outlinks of ui)
    //         Rank(current node) = (d/N) + (1-d) * SUM_OF_RANKS_CAL
    std::vector<Vertex> neighbors;
    for (std::map<Vertex, Edge>::iterator iter = adjacency_list[startingVertex].begin(); iter != adjacency_list[startingVertex].end(); ++iter) {
        neighbors.push_back(iter->first);
    }
    double sum_rank_ui = 0;
    for (Vertex v : vertices) {
        for (Vertex ui : neighbors) {
            sum_rank_ui += rank[ui] / getDegree(v);
        }
        rank[v] = (d / N) + ((1-d) * (sum_rank_ui));
    }


    Vertex maxVertex = startingVertex;
    size_t maxNum = 0;
    for (std::map<Vertex, double>::iterator it = rank.begin(); it != rank.end(); ++it) {
        if (it->second > maxNum) {
            maxVertex = it->first;
            maxNum = it->second;
        }
    }
    return maxVertex;
}

Edge Graph::getEdge(Vertex start, Vertex end) const {
    Edge e; //Nothing found
    std::map<Vertex, Edge> map = adjacency_list.at(start);

    for (auto entry : map) {
        if (entry.first == end) {
            return entry.second;
        }
    }
    return e; //Nothing found, empty edge
}

vector<Vertex> Graph::getAdjacent(Vertex source) const {
    std::vector<Vertex> v;
    std::map<Vertex,Vertex> previous;
    std::map<Vertex, Edge> map = adjacency_list.at(source);
    for (auto entry : map) {
        v.push_back(entry.first);
    }
    return v;
}


std::vector<int> Graph::Dijkstras(Vertex source, Vertex destination) {
    std::vector<Vertex>node;
    for(auto it = adjacency_list.begin(); it != adjacency_list.end(); ++it) {
        node.push_back(it->first);
    }
    std::vector<int> to_return;
    map<int, bool> visited;
    map<int, double> distance;
    map<int,int> previous;
    for(unsigned int i = 0; i < )
   
    // std::set<Vertex> visited;
    // std::map<Vertex, Vertex> prev;
   
    // vertices.at(source) = 0;
   
    // std::priority_queue<Vertex,std::map<Vertex,int>,decltype(check)>

    // while(prop.top() != destination) {
    //     Vertex tmp = prop.top();
    //     prop.pop();
    //     int value = vertices.at(tmp);
    //     for(auto m : adjacency_list.at(tmp)) {
    //         Edge l = getEdge(tmp, m.first);
    //         int sec_dist = value + l.getDistance();
    //         if(visited.find(m.first) == visited.end()) {
    //             if(sec_dist < vertices.at(m.first)) {
    //                 vertices.at(m.first) = sec_dist;
    //                 prev.insert(std::pair<Vertex,Vertex>(m.first,tmp));
    //             }
    //         }
    //     }
    //     visited.insert(tmp);
    // }
    // Vertex start = destination;
    // bool flag  = false;
    // std::stack<Edge> val;
    // while(!flag) {
    //     Edge m = getEdge(prev.at(start),start);
    //     val.push(m);
    //     if(prev.at(start) == source) {
    //         flag = true;
    //     }
    // }
    // return vector<Edge>();
    
}