#include "algorytm.h"


std::vector<double> Algorytm::mnozenie(double** macierz,std::vector<double> wektor){
	std::vector<double> wynik;
	if (rozmiar_macierzy_==(int)wektor.size()){
		for (int i=0;i<rozmiar_macierzy_;i++){
		        for (int j=0;j<rozmiar_macierzy_;j++){
		        	if (wynik.size()<=i)
		        		wynik.push_back(macierz[i][j]*wektor.at(j));
		        	else
		        		wynik.at(i)+= macierz[i][j]*wektor.at(j);
		        }
		    }
		return wynik;
	}
	else{
		std::cout << "[ERROR]: mnozenie macierzy razy wektor, rozmiar wektora i macierzy jest rozny"<<std::endl;
		return wynik;
	}
}


std::vector<double> Algorytm::mnozenie(std::vector<double> wektor,double skalar){
	std::vector<double> wynik;
	for(int i=0; i<(int)wektor.size(); i++)
		wynik.push_back(wektor.at(i)*skalar);
	return wynik;

}

std::vector<double> Algorytm::odejmowanie(std::vector<double> odjemna,std::vector<double> odjemnik){
	std::vector<double> wynik;
	if(odjemnik.size()==odjemnik.size())
		for (int i=0;i<(int)odjemnik.size();i++)
			wynik.push_back(odjemna.at(i)-odjemnik.at(i));
	else
		std::cout << "[ERROR]: odejmowanie wektorow, rozmiar wektorow jest rozny"<<std::endl;
		return wynik;
}

std::vector<double> Algorytm::dodawanie(std::vector<double> skladnik1,std::vector<double> skladnik2){
	std::vector<double> wynik;
	if(skladnik1.size()==skladnik2.size())
		for (int i=0;i<(int)skladnik1.size();i++)
			wynik.push_back(skladnik1.at(i)+skladnik2.at(i));
	else
		std::cout << "[ERROR]: dodawanie wektorow, rozmiar wektorow jest rozny"<<std::endl;
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
