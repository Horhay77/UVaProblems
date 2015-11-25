/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>
#include <list>
using namespace std;

//Variables globales


//Procedimientos
int indiceEstado(char letra);

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int casoActual = 1,numCasos;
    string frase,frase2;
    getline(cin,frase);
	list<int> apariciones[52];//Cantidad de candidatos de cada uno de los estados
	list<int>::iterator listIt[52];
	int I, K , M;
  	for(I = 0; I < frase.size(); I++){
  		apariciones[indiceEstado(frase.at(I))].push_back(I);
  	}
    cin >> numCasos;
    cin.ignore();
    while(casoActual <= numCasos){
    	casoActual++;
    	getline(cin,frase2);
    	int minimo = -1, maximo = -1;
	    bool match = true;
	    int posActual = -1;
	    int indiceLetraActual;
	    for(I = 0; I < 52 ; I++)
	    	listIt[I] = apariciones[I].begin();
	    for(I = 0; I < frase2.size(); I++){
	    	indiceLetraActual = indiceEstado(frase2.at(I));
	    	//listIt = apariciones[indiceLetraActual].begin();
	    	while(listIt[indiceLetraActual] != apariciones[indiceLetraActual].end() && *listIt[indiceLetraActual] <= posActual){
	    		listIt[indiceLetraActual]++;
	    	}
	    	if(*listIt[indiceLetraActual] <= posActual || listIt[indiceLetraActual] == apariciones[indiceLetraActual].end()){
	    		match = false;
	    		break;
	    	}
	    	else{
	    		//cout << "Busco la letra " << frase2.at(I) << " y creo q esta en la posicion " <<
	    		//	*listIt << " y la prueba es:" << frase.at(*listIt) << endl;
	    		if(minimo == -1)
	    			minimo = *listIt[indiceLetraActual];
	    		maximo = *listIt[indiceLetraActual];
	    		posActual = *listIt[indiceLetraActual];
	    	}
	    }
	    if(!match)
	    	cout << "Not matched" << endl;
	    else
	    	cout << "Matched " << minimo << " " << maximo << endl; 

    }
    return 0;
}

int indiceEstado(char letra){
	int indice = int(letra);
	if(indice <= 90 )
		return indice - 65;
	else 
		return indice - 71;
}