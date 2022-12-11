EXENAME = main
OBJS = main.o graph.o vertex.o edge.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
# run command: g++ -c main.cpp ../Source_Files/Graph.cpp ../Source_Files/Vertex.cpp ../Source_Files/Edge.cpp
all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME) : output_msg $(OBJS)
	$(LD) $(OBJS) -o $(EXENAME)

#object file dependncies
main.o : main.cpp ../Source_Files/Graph.cpp ../Source_Files/Graph.h
	$(CXX) $(CXXFLAGS) main.cpp

# graph.o : ../Source_Files/Graph.cpp ../Source_Files/Graph.h ../Source_Files/Vertex.cpp ../Source_Files/Vertex.h ../Source_Files/Edge.h ../Source_Files/Edge.cpp
# 	$(CXX) $(CXXFLAGS) ../Source_Files/Graph.cpp

edge.o : ../Source_Files/Edge.cpp ../Source_Files/Edge.h ../Source_Files/Vertex.h ../Source_Files/Vertex.cpp
	$(CXX) $(CXXFLAGS) ../Source_Files/Edge.cpp

vertex.o : ../Source_Files/Vertex.cpp ../Source_Files/Vertex.h
	$(CXX) $(CXXFLAGS) ../Source_Files/Vertex.cpp


test: output_msg ../tests/tests.cpp ../Source_Files/Graph.cpp ../Source_Files/Edge.cpp ../Source_Files/Vertex.cpp
	$(LD) ../tests/tests.cpp ../Source_Files/Graph.cpp ../Source_Files/Edge.cpp ../Source_Files/Vertex.cpp -o test

.PHONY: output_msg