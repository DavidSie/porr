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

const int ROZMIAR_MACIERZY=10;
double** wypelnijMacierz();
double* wypelnijB();


using namespace std;

int main() {
    double** macierz=wypelnijMacierz();
    #pragma omp parallel
    printf("Hello from thread %d, nthreads %d\n", omp_get_thread_num(), omp_get_num_threads());
    double* b=wypelnijB();
    int x0=0;
    double alfa=100;
    int s=5;


    AlgorytmCzebyszew algCzebyszew=AlgorytmCzebyszew(macierz,ROZMIAR_MACIERZY,b,(double)x0,alfa,s);
    algCzebyszew.czasStart();
    algCzebyszew.obliczMacierzRownan();
    algCzebyszew.czasStop();
    //std::cout.precision(6);
    std::cout << "Czas wykonania: "<< fixed <<algCzebyszew.getCzasWykonania()/CLOCKS_PER_SEC<<" sekund"<<std::endl;
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
		}
	}

	return macierz_;
}


double* wypelnijB(){
	double* b_=new double [ROZMIAR_MACIERZY];
	for (int i = 0; i < ROZMIAR_MACIERZY; ++i) {
		b_[i] = 2*i;
	}
	return b_;
}
