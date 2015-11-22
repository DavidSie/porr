#include "algorytm.h"


std::vector<double> Algorytm::mnozenie(double** macierz,std::vector<double> wektor){
	std::vector<double> wynik;
	if (rozmiar_macierzy_==(int)wektor.size()){
		for (int i=0;i<rozmiar_macierzy_;i++){
		        for (int j=0;j<rozmiar_macierzy_;j++){
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