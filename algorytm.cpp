#include "algorytm.h"


std::vector<double> Algorytm::mnozenie(double** macierz,std::vector<double> wektor){
	std::vector<double> wynik(rozmiar_macierzy_,0);
	if (rozmiar_macierzy_==(int)wektor.size()){
		//wynik.resize(rozmiar_macierzy_);
		//shared(wynik) private(macierz,wektor)
		#pragma omp parallel for schedule(static)
		for (int i=0;i<rozmiar_macierzy_;i++){
			for (int j=0;j<rozmiar_macierzy_;j++){
				//std::cout<<"i="<<i<<" j="<<j<<std::endl;
				wynik[i]+=macierz[i][j]*wektor[j];
			}
		}
	}
	else{
		std::cout << "[ERROR]: mnozenie macierzy razy wektor, rozmiar wektora i macierzy jest rozny"<<std::endl;
	}
	return wynik;
}


std::vector<double> Algorytm::mnozenie(std::vector<double> wektor,double skalar){
	std::vector<double> wynik;
	for(int i=0; i<(int)wektor.size(); i++){
		wynik.push_back(wektor.at(i)*skalar);
	}
	return wynik;

}

std::vector<double> Algorytm::odejmowanie(std::vector<double> odjemna,std::vector<double> odjemnik){
	std::vector<double> wynik;
	if(odjemnik.size()==odjemnik.size()){
		wynik.resize(odjemna.size());
		#pragma omp parallel shared(wynik,odjemna,odjemnik)
		{
			#pragma omp for
			for (int i=0;i<(int)odjemna.size();i++){
						wynik[i]=odjemna.at(i)-odjemnik.at(i);
			}
		}
	}
	else
		std::cout << "[ERROR]: odejmowanie wektorow, rozmiar wektorow jest rozny"<<std::endl;
		return wynik;
}

std::vector<double> Algorytm::dodawanie(std::vector<double> skladnik1,std::vector<double> skladnik2){
	std::vector<double> wynik;
	if(skladnik1.size()==skladnik2.size()){
		wynik.resize(skladnik1.size());
		#pragma omp parallel shared(wynik,skladnik1,skladnik2)
		{
			#pragma omp for
			for (int i=0;i<(int)skladnik1.size();i++){
				wynik[i]=skladnik1.at(i)+skladnik2.at(i);
			}
		}
	}else
		std::cout << "[ERROR]: dodawanie wektorow, rozmiar wektorow jest rozny. skladnik1.size()="<<skladnik1.size()<<" skladnik2.size()="<<skladnik2.size()<<std::endl;
//	std::cout<<"dodawanie:";
//	wypiszWektor(skladnik1);
//	std::cout<<"+";
//	wypiszWektor(skladnik2);
//	std::cout<<"=";
//	wypiszWektor(wynik);
	return wynik;
}


bool Algorytm::warunekCauchego(std::vector<double> wektor_n,std::vector<double> wektor_n_plus_1, double epsilon){
	double maxRoznica=0;
	if ( wektor_n.size()==wektor_n_plus_1.size()){
		for (int i=0; i<wektor_n.size(); i++){
			double roznica=wektor_n_plus_1.at(i)-wektor_n.at(i);
			if (roznica<0)
				roznica*=-1; // modul z roznicy
			if (roznica>epsilon)
				return false;
		}
	}else{
		std::cout << "[ERROR]: warunek Cauchego, rozmiar wektorow jest rozny"<<std::endl;
		return NULL;
	}
	return true;

}

void Algorytm::wypiszWektor(std::vector<double> wektor)
{
	std::cout <<std::endl<<"[";
	for (int i=0;i<wektor.size();i++)
		std::cout <<wektor.at(i)<<";";
	std::cout <<"]"<<std::endl;
}
