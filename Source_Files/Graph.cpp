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
                        id_to_vertex.insert({it->first, port}); //map id to vertex
                        id_to_latlong.insert({it->first, std::make_pair(port.getLat(), port.getLong())}); //map id to lat long
                    }

                    //Go through routes data
                    for(auto it = route_data.cbegin(); it != route_data.cend(); it++) {
                        //Add an edge between source airport and dest airport
                        Vertex start;
                        Vertex end;
                        Edge e;
                        try {
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
                        } catch (...) {
                            //std::cout << "Start and/or end Airports don't exist in graph" << std::endl;
                        }
                        
                        
                    }



}


Vertex Graph::getStartingVertex() const { //Just get whatever vertex is at the top of map
    return adjacency_list.begin()->first;
}


bool Graph::edgeExists(std::string air_id_1, std::string air_id_2) const {
    for (auto map : adjacency_list) {
        if (map.first.getID() == air_id_1) {
            for (auto map2 : map.second) {
                if (map2.first.getID() == air_id_2) {
                    return true;
                }
            }
        }
    }
    return false;
}


double Graph::getDegree(Vertex node) { //For Krushank's PageRank
    return adjacency_list[node].size();
}


//Finished, needs to be tested
Vertex Graph::PageRank() {
  
   std::map<Vertex, double> old_rank;
   std::map<Vertex, double> new_rank;
   std::vector<Vertex> vertices;
   std::vector<Vertex> no_outlinks;
   double d = 0.85;
 
   // N <- number of nodes in G (number of airports)
 
   //get all vertices
   for (std::map<Vertex, std::map<Vertex, Edge>>::iterator iter = adjacency_list.begin(); iter != adjacency_list.end(); ++iter) {
       vertices.push_back(iter->first);
       if (iter->second.size() == 0) {
           no_outlinks.push_back(iter->first);
       }
   }
   double N = (double) vertices.size();
  
   // For every node V in Graph:
   //     Initialize the rank of the node to be 1/N
   //         - Rank(V) = 1/N
 
   for (Vertex v : vertices) {
       std::pair<Vertex, double> pair = std::pair<Vertex, double>(v, 1.0 / N);
       old_rank.insert(pair);
       new_rank.insert(pair); //initialization for new_pagerank (will be overridden)
   }
 
   // for every vertex in graph
   //     For every node from ui (# of neighbors of current node) and uj (number of nodes with no outlinks) with no outlinks
   //         SUM_OF_RANKS_CALC = sum(rank(ui)/# of outlinks of ui)
   //         Rank(current node) = (d/N) + (1-d) * SUM_OF_RANKS_CAL
  
   for (Vertex v : vertices) {
       double dp = 0;
       for (Vertex uj : no_outlinks) {
           dp += d * (old_rank[uj] / N);
       }
 
       for (Vertex ui : vertices) {
           new_rank[ui] = dp + ((1-d) / N);
           std::vector<Vertex> inlinks;
           for (std::map<Vertex, std::map<Vertex, Edge>>::iterator iter = adjacency_list.begin(); iter != adjacency_list.end(); ++iter) {
               for (std::map<Vertex, Edge>::iterator it = iter->second.begin(); it != iter->second.end(); ++it) {
                   if (it->first == ui) {
                       inlinks.push_back(iter->first);
                   }
               }
           }
           for (Vertex v_in : inlinks) {
               new_rank[ui] += (d * old_rank[v_in]) / getDegree(v_in);
           }
       }
      
       for (std::map<Vertex, double>::iterator iter = old_rank.begin(); iter != old_rank.end(); ++iter) {
           old_rank[iter->first] = new_rank[iter->first];
       }
   }
 
 
 
   Vertex maxVertex;
   double maxNum = 0.0;
   for (std::map<Vertex, double>::iterator it = new_rank.begin(); it != new_rank.end(); ++it) {
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
    std::map<Vertex, Edge> map = adjacency_list.at(source);
    for (auto entry : map) {
        v.push_back(entry.first);
    }
    return v;
}

bool Graph::vertexExists (Vertex v) const {
    if (adjacency_list.find(v) != adjacency_list.end()) {
        return true; //Found
    } 
    return false; //Doesn't exist
}

bool Graph::edgeExists(Vertex source, Vertex destination) const {
    if (adjacency_list.find(source) == adjacency_list.end()) {
        return false; //Vertex not in map
    } 
    std::map<Vertex, Edge> map = adjacency_list.at(source);

    for (auto entry : map) {
        if (entry.first == destination) {
            return true;
        }
    }

    return false; //Doesn't exist
}

std::vector<Edge> Graph::Dijkstras(Vertex source, Vertex destination) {
    //Follow class psuedo code, handle edge cases
    if(source == destination) {
        return std::vector<Edge>();
    }
    std::vector<Vertex> adj = getAdjacent(source);
    for(unsigned int i = 0; i < adj.size(); i++) {
        if (adj[i] == destination) {
            std::vector<Edge> value;
            Edge l = getEdge(source,destination);
            value.push_back(l);
            return value;
        }
    }
    std::vector<Edge> to_return;
    std::map<Vertex,int> vertices;
    std::vector<Vertex> node;
    std::map<Vertex,Vertex> previous;
    std::set<Vertex> visited;

    for(auto it = adjacency_list.begin(); it != adjacency_list.end(); ++it) {
        node.push_back(it->first);
        if(it->first != source) {
            vertices.insert(pair<Vertex,int>(it->first,INT16_MAX));
        } else {
            vertices.insert(pair<Vertex,int>(it->first,0));
        }
        
    }
    std::priority_queue<Vertex,std::vector<Vertex>,std::greater<Vertex>>prop(node.begin(),node.end());
    while (prop.top() != destination) 
    {
        Vertex c = prop.top();
        visited.insert(c);
        prop.pop();
        for(Vertex neighbor : getAdjacent(c)) {
            if(visited.find(neighbor) == visited.end()) {
                Edge l = getEdge(c,neighbor);
                if(l.getDistance() < (double)(vertices.at(c))) {
                    vertices.at(c) = l.getDistance();
                    previous.insert(pair<Vertex,Vertex>(c,neighbor));
                    to_return.push_back(l);
                }
            }
            
        }

    }
    //Testing
    // for(Edge c : to_return) {
    //     std::cout << c.getStart(). << "  " << c.getEnd().a << endl;
    // }
    return to_return;
    //return std::vector<Edge>();
    
}



Vertex Graph::getVertex(std::string id) { //Get vertex from airport id
    Vertex v;
    for (auto map : adjacency_list) {
        if (map.first.getID() == id) {
            return map.first;
        }
    }
    return v;
}