CXX=/usr/local/bin/gcc-4.8
#CXX=gcc

CXXFLAGS=-fopenmp -lstdc++  -Wall
#CXXFLAGS= -lstdc++ -Wall

program01:	main.o algorytm.o algorytmCzebyszew.o algorytmJordaGauss.o
		$(CXX)    -o  porr_porownanie  algorytm.o algorytmCzebyszew.o algorytmJordaGauss.o main.o  $(CXXFLAGS)
main.o:	main.cpp
		$(CXX) -o main.o -c main.cpp $(CXXFLAGS) 
algorytm.o: algorytm.cpp algorytm.h
		$(CXX) -o  algorytm.o -c algorytm.cpp $(CXXFLAGS) 
algorytmCzebyszew.o: algorytmCzebyszew.cpp algorytmCzebyszew.h
		$(CXX) -o  algorytmCzebyszew.o -c algorytmCzebyszew.cpp $(CXXFLAGS) 

algorytmJordaGauss.o: algorytmJordaGauss.cpp algorytmJordaGauss.h
		$(CXX) -o  algorytmJordaGauss.o -c algorytmJordaGauss.cpp $(CXXFLAGS)

clean:
		rm -f *.o