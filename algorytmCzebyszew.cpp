#include "algorytmCzebyszew.h"

AlgorytmCzebyszew::AlgorytmCzebyszew(double** macierz,int rozmiar_macierzy,double* b,double x0,double alfa, int s){
	macierz_=macierz;
	b_=b;
	x0_=x0;
	alfa_=alfa;
	s_=s;
	double maxaii=0;
	rozmiar_macierzy_=rozmiar_macierzy;
	
	for (int i=0; i<rozmiar_macierzy_; i++){
		if (i==0)
			maxaii=macierz_[i][i];
		else
			if (macierz_[i][i]>maxaii)
				maxaii=macierz_[i][i];
	}
	beta_=2*maxaii;
}

void AlgorytmCzebyszew::obliczMacierzRownan(){
	int krok=0;
	int iteracja=0; //zamienic na warunek cauchego
	int i,c,L,k;
	std::vector<double> omega;
	std::vector<double> x0;
	std::vector<double> zeroVector;

	for (int j=0; j<rozmiar_macierzy_; j++){
		x0.push_back(x0_);
		zeroVector.push_back(0);
	}
	std::vector<std::vector<double> > x;
	do{
		switch( krok)
		{
		case 0:
			std::cout <<"iteracja: "<< iteracja<<" krok: 0" <<std::endl;
		    i=0;
		    omega.push_back(0); // w i-1 
		    omega.push_back((beta_-alfa_)/(beta_+alfa_)); // w 0
		    c=2/(beta_+alfa_);
		    L=2*(beta_+alfa_)/(beta_-alfa_);
		    x.push_back(zeroVector); // x dla i=-1
		    krok=1;
		    break;
		    
		case 1:
			std::cout <<"iteracja: "<< iteracja<<" krok: 1" <<std::endl;
		    k=0;
		    if ((int)x.size()<=(i+1))
		    	x.push_back(x0); // x i
		    else
		    	x.at(i+1)=x0; // x i
		    if (i!=0){
		    	omega[i]=0;  // w i -1=0  
		    	omega.push_back(omega.at(1));// w i = w 0
		    }
		    krok=2;
		    break;
		    
		case 2:
		{
			std::cout <<"iteracja: "<< iteracja<<" krok: 2" <<std::endl;
		    std::vector<double> cz1;
		    std::vector<double> cz2;
		    std::vector<double> cz3;
		    std::vector<double> value;
		    std::cout <<"iteracja: "<< iteracja<<" rozmiar wektor x: "<< x.size()<<" a i+1:"<< i+1 <<std::endl;
		    cz1=x.at(i+1);
		    std::cout <<" krok: 2, p 1" <<std::endl;
		    cz2=mnozenie( odejmowanie(x.at(i+1),x.at(i)), omega.at(i+1)*omega.at(i)  );
		    std::cout <<" krok: 2, p 2" <<std::endl;
		    std::vector<double> mac=mnozenie(macierz_,x.at(i+1));
		    std::cout <<" krok: 2, p 3" <<std::endl;
		    double skalar=c*(1+omega.at(i+1)*omega.at(i));
		    std::cout <<" krok: 2, p 4" <<std::endl;
		    cz3=mnozenie(mac,skalar);
		    std::cout <<" krok: 2, p 5" <<std::endl;
		    value=dodawanie(dodawanie(cz1,cz2),cz3);
		    std::cout <<" krok: 2, p 6" <<std::endl;
		    x.push_back(value);
		    std::cout <<" krok: 2, p 7" <<std::endl;
		    omega.push_back(1/(L-omega.at(i+1)));
		    krok=3;
		    break;
		}

		case 3:
			std::cout <<"iteracja: "<< iteracja<<" krok: 3" <<std::endl;
		    k++;
		    i++;
		    if(k<s_)
		    	krok=2;
		    else{
		    	x0=x.at(i+1);
		    	krok=1;
		    }
		    break;
		}
		iteracja++;
	}while (iteracja<10); //zmienić warunek na bardziej sensowny
	return;
}




