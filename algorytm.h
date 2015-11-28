//
//  algorytm.h
//  PORR_Czybyszew
//
//  Created by David Sieciński on 17.11.2015.
//
//




#ifndef algorytm_h

#include <time.h>
#include <iostream>
#include <vector>

class Algorytm {
  protected:
   double** macierz_;
   double* b_;
   clock_t czasStart_;
   clock_t czasRoznica_;
   int rozmiar_macierzy_;

  std::vector<double> mnozenie(double** macierz,std::vector<double> wektor);
  std::vector<double> mnozenie(std::vector<double> wektor,double skalar);
  std::vector<double> odejmowanie(std::vector<double> odjemna,std::vector<double> odjemnik);
  std::vector<double> dodawanie(std::vector<double> skladnik1,std::vector<double> skladnik2);
  bool warunekCauchego(std::vector<double> wektor_n,std::vector<double> wektor_n_plus_1,double epsilon);

  public:
   	void setMacierz(double** macierz) {macierz_=macierz;}
   	void setB(double* b){b_=b;}
  	virtual std::vector<double> obliczMacierzRownan()=0;
  	void czasStart(){czasStart_ = clock();}
  	void czasStop() {czasRoznica_=clock()-czasStart_;}
  	double getCzasWykonania() {return (double) czasRoznica_;}



    //readingModule - modul wczytujacy maciez
    // zliczanie czasu
    // klasa abstrakcyjna
    
};
#define algorytm_h


#endif /* algorytm_h */
