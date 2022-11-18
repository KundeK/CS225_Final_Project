#include "Graph.h"

//TODO Aadarsh

std::vector<Vertex> Graph::PageRank() {
    // PAGE RANK ALGORITHM PSUEDOCODE

    /*
        PageRank() -> uses graph and needs parameter n, which specifies number of iterations
        
        vector of vertex initialized as rank;
        
        d <- 0.15
        N <- number of nodes in G (number of airports)
        For every node V in Graph:
            Initialize the rank of the node to be 1/N 
                - Rank(V) = 1/N
        
        While (n > 0) -> going through iterations n times
            For every node from ui (# of neighbors of current node) and uj (number of nodes with no outlinks) with no outlinks
                SUM_OF_RANKS_CALC = sum(rank(ui)/# of outlinks of ui) + sum(rank(uj)/N)
                Rank(current node) = (d/N) + (1-d) * SUM_OF_RANKS_CALC
            n--;
            
    return Rank;
    
    */
}