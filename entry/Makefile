EXENAME = main
OBJS = main.o

CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
# LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm
# g++ -c main.cpp (run command)
all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME) : output_msg $(OBJS)
	$(LD) $(OBJS) -o $(EXENAME)

#object file dependncies
main.o : main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

# graph.o : graph.cpp graph.h vertex.cpp vertex.h utility.h utility.cpp
# 	$(CXX) $(CXXFLAGS) graph.cpp

# vertex.o : vertex.cpp vertex.h utility.h utility.cpp
# 	$(CXX) $(CXXFLAGS) vertex.cpp 

# utility.o : utility.cpp utility.h
# 	$(CXX) $(CXXFLAGS) utility.cpp

# output_msg: ; $(CLANG_VERSION_MSG)

# test: output_msg ../catch/catchmain.cpp ../tests/graph-tests.cpp graph.cpp vertex.cpp utility.cpp
# 	$(LD) ../catch/catchmain.cpp ../tests/graph-tests.cpp graph.cpp vertex.cpp utility.cpp $(LDFLAGS) -o test

.PHONY: output_msg