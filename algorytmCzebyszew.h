//
//  algorytmCzebyszew.h
//  PORR_Czybyszew
//
//  Created by David Sieciński on 17.11.2015.
//
//

#ifndef algorytmCzebyszew_h
#define algorytmCzebyszew_h

#include "algorytm.h"
#include <vector>

class AlgorytmCzebyszew : public  Algorytm{
	double alfa_;
	double beta_;
	double x0_;
	int s_;
	bool warunekCauchego(std::vector<double> wektor_n,std::vector<double> wektor_n_plus_1,double epsilon);
public:
	AlgorytmCzebyszew(double** macierz,int rozmiar_macierzy,std::vector<double> b,double x0,double alfa,int s);
	~AlgorytmCzebyszew(){delete macierz_;}
	std::vector<double> obliczMacierzRownan();

};

#endif /* algorytmCzebyszew_h */
