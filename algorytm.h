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
#include <omp.h>


class Algorytm {
  protected:
   double** macierz_;
   std::vector<double> b_;
   double czasStart_;
   double czasRoznica_;
   int rozmiar_macierzy_;

  std::vector<double> mnozenie(double** macierz,std::vector<double> wektor);
  std::vector<double> mnozenie(std::vector<double> wektor,double skalar);
  std::vector<double> odejmowanie(std::vector<double> odjemna,std::vector<double> odjemnik);
  std::vector<double> dodawanie(std::vector<double> skladnik1,std::vector<double> skladnik2);


  public:
   	void setMacierz(double** macierz) {macierz_=macierz;}
   	void setB(std::vector<double> b){b_=b;}
  	virtual std::vector<double> obliczMacierzRownan()=0;
  	void czasStart(){czasStart_ = omp_get_wtime();}
  	void czasStop() {czasRoznica_=omp_get_wtime()-czasStart_;}
  	double getCzasWykonania() {return (double) czasRoznica_;}
  	void wypiszWektor(std::vector<double> wektor);




    //readingModule - modul wczytujacy maciez
    // zliczanie czasu
    // klasa abstrakcyjna
    
};
#define algorytm_h


#endif /* algorytm_h */
