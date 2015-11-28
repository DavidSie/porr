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

std::vector<double> AlgorytmCzebyszew::obliczMacierzRownan(){
	int krok=0;
	int iteracja=0; //zamienic na warunek cauchego
	int i,c,L,k;
	std::vector<double> omega;
	std::vector<double> x0;
	std::vector<double> zeroVector;
	bool warunekWhile=true;

	for (int j=0; j<rozmiar_macierzy_; j++){
		x0.push_back(x0_);
		zeroVector.push_back(0);
	}
	std::vector<std::vector<double> > x;
	do{
		switch( krok)
		{
		case 0:
		    i=0;
		    omega.push_back(0); // w i-1 
		    omega.push_back((beta_-alfa_)/(beta_+alfa_)); // w 0
		    c=2/(beta_+alfa_);
		    L=2*(beta_+alfa_)/(beta_-alfa_);
		    x.push_back(zeroVector); // x dla i=-1
		    krok=1;
		    break;
		    
		case 1:
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
		    std::vector<double> cz1;
		    std::vector<double> cz2;
		    std::vector<double> cz3;
		    std::vector<double> value;
		    cz1=x.at(i+1);
		    cz2=mnozenie( odejmowanie(x.at(i+1),x.at(i)), omega.at(i+1)*omega.at(i)  );
		    std::vector<double> mac=mnozenie(macierz_,x.at(i+1));
		    double skalar=c*(1+omega.at(i+1)*omega.at(i));
		    cz3=mnozenie(mac,skalar);
		    value=dodawanie(dodawanie(cz1,cz2),cz3);
		    x.push_back(value);
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
		std::cout <<" rozmiar x: " << x.size()<< " i "<< i<<std::endl;

		if (iteracja< 32) // trzeba dojsc do kroku 2
			warunekWhile=true;
		else
			warunekWhile=!warunekCauchego( x.at(i),x.at(i+1),0.000000001 );

	}while ( warunekWhile); //wykonywac dopoki nie jest spelniony warunek cauchego
	return x.at(i+1);
}




