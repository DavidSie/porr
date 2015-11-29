//
//  main.c
//  PORR_Czybyszew
//
//  Created by David Sieciński on 12.11.2015.
//
//


#include <omp.h>
//#include <stdio.h>
#include <iostream>
#include <sstream>
#include "algorytmCzebyszew.h"

const int ROZMIAR_MACIERZY=5;
double** wypelnijMacierz();
std::vector<double> wypelnijB();


using namespace std;

int main() {
    double** macierz=wypelnijMacierz();
    //#pragma omp parallel
    //printf("Hello from thread %d, nthreads %d\n", omp_get_thread_num(), omp_get_num_threads());
    std::vector<double> b=wypelnijB();
    int x0=0;
    double alfa=100;
    int s=5;


    AlgorytmCzebyszew algCzebyszew=AlgorytmCzebyszew(macierz,ROZMIAR_MACIERZY,b,(double)x0,alfa,s);
    algCzebyszew.czasStart();
    algCzebyszew.wypiszWektor(algCzebyszew.obliczMacierzRownan());
    algCzebyszew.czasStop();
    //std::cout.precision(6);
    std::cout << "Czas wykonania: "<< fixed <<algCzebyszew.getCzasWykonania()<<" sekund"<<std::endl;
    //std::cout << "Czas wykonania: " << algCzebyszew.getCzasWykonania() << std::endl;
    return 0;
}

double** wypelnijMacierz(){

	double** macierz_;
	macierz_=new double* [ROZMIAR_MACIERZY];
	for (int i = 0; i < ROZMIAR_MACIERZY; ++i) {
	 macierz_[i] = new double [ROZMIAR_MACIERZY];
	  // each i-th pointer is now pointing to dynamic array (size 10) of actual int values
	}

	for (int i = 0; i < ROZMIAR_MACIERZY; ++i) {
		for (int j = 0; j < ROZMIAR_MACIERZY; ++j) {
			if (i==j)
		 		macierz_[i][j] = ROZMIAR_MACIERZY+3+i;
		 	else
				macierz_[i][j] =1;
			//std::cout<<"element macierzy["<<i<<","<<j<<"]="<<macierz_[i][j]<<std::endl;
		}
	}

	return macierz_;
}


std::vector<double> wypelnijB(){
	std::vector<double> b_;
	for (int i = 0; i < ROZMIAR_MACIERZY; ++i) {
		//b_.push_back(2*i);
		b_.push_back(2*ROZMIAR_MACIERZY+3+i-1);

	}
	return b_;
}


