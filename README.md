# GitHub Organization

entry: Contains main.cpp and the different .dat files that the project uses. 

    airports.dat - Full size dataset from openflights full of different airports and their lat long locations
    airports_test.dat - Truncated dataset used for testing purposes

    routes.dat - Full size dataset from openflights containing all routes from different airports
    routes_test.dat - Truncated dataset used for testing

    Makefile - Contains make main target that allows us to compile and run main.cpp automatically


Source_Files: Contains all .cpp and .h files used by the project
    
    Vertex.cpp
    Vertex.h
    ^ Airport representation

    Edge.cpp
    Edge.h
    ^ Route representation

    Graph.cpp
    Graph.h
    ^ Representation of all airports and routes between them

tests: Contains test suite using truncated datasets to test our code

    tests.cpp


# Running Instructions

To run main:
    
    cd into entry
    run ' g++ -c main.cpp ../Source_Files/Graph.cpp ../Source_Files/Vertex.cpp ../Source_Files/Edge.cpp ' 
    then run ' make main ' 
    then run ' ./main ../entry/airports.dat ../entry/routes.dat ' 
   
    Alternatively in the case make does not work:
        cd into Source_Files
        run ' clang++ -std=c++20 Edge.cpp Vertex.cpp Graph.cpp ../entry/main.cpp -Wall -Wextra -pedantic -o exec '
        run ' ./exec ../entry/airports.dat ../entry/routes.dat '

To run tests:

    cd into Source_Files
    run ' clang++ -std=c++20 Edge.cpp Vertex.cpp Graph.cpp ../tests/tests.cpp -Wall -Wextra -pedantic -o exec '
    run ' ./exec ../entry/airports_test.dat ../entry/routes_test.dat '




