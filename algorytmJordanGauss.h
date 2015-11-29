//
//  algorytmJordaGauss.h
//  PORR_Czybyszew
//
//  Created by David Sieciński on 17.11.2015.
//
//

#ifndef algorytmJordanGauss_h
#define algorytmJordanGauss_h

#include "algorytm.h"
class AlgorytmJordanGauss : public  Algorytm{
	double alfa_;
	double beta_;
	double x0_;
	int s_;
public:
	AlgorytmJordanGauss(double** macierz,int rozmiar_macierzy,std::vector<double> b,double x0,double alfa,int s);
	std::vector<double> obliczMacierzRownan();
	~AlgorytmJordanGauss(){delete macierz_;}

};

#endif /* algorytmJordanGauss_h */
