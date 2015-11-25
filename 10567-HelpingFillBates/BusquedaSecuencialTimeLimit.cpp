/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>

using namespace std;

//Variables globales

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int casoActual = 1,numCasos;
    string frase,frase2;
    getline(cin,frase);
	cin >> numCasos;
    cin.ignore();
    int minimo, maximo;
    int i , j;
    while(casoActual <= numCasos){
    	casoActual++;
    	getline(cin,frase2);
    	minimo = -1;
    	maximo = -1;
    	int coincidencias= 0;
    	for(i = 0; i < frase2.size();i++){
	    	for(j = maximo +1 ;j < frase.size();j++)
	    		if(frase2.at(i)==frase.at(j)){
	    			maximo = j;
	    			coincidencias++;
	    			if(minimo==-1)
	    				minimo = j;
	    			break;
	    		}
	    	if(frase.size()-maximo < frase2.size()-i)
	    		break;
    	}
		if(coincidencias == frase2.size())
			cout << "Matched " << minimo << " " << maximo << endl;
	    else
	    	cout << "Not matched" << endl;
	}
    return 0;
}