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
public:
	AlgorytmCzebyszew(double** macierz,int rozmiar_macierzy,double* b,double x0,double alfa,int s);
	void obliczMacierzRownan();


};

#endif /* algorytmCzebyszew_h */
