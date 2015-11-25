/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>
#include <vector>
using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int numCabezas ,numCaballeros;
    int coste;
    int encontrado;
	while(cin >> numCabezas >> numCaballeros){
		coste = 0;
		if(numCabezas == 0 && numCaballeros == 0)
			break;
		vector < int> cabezas (numCabezas);
    	for(int i = 0; i < numCabezas;i++)
    		cin>> cabezas[i];
    	vector<int> caballeros (numCaballeros);
    	for(int i = 0; i < numCaballeros;i++)
    		cin >> caballeros[i];
		if(numCabezas <= numCaballeros){
	    	//Recorrido de las cabezas
    		for(int i = 0; i < numCabezas;i++){
    			encontrado = -1;
    			int minimo = 0x7FFFFFFF;
    			for(int j = 0 ; j < numCaballeros - i;j++){ //es el num de elemntos restantes en numCaballeros
    				if(caballeros[j]>=cabezas[i] && caballeros[j]<minimo){
    					encontrado = j;
    					minimo = caballeros[j];
    					if(minimo==cabezas[i])
    						break;
    				}
				}
				if(encontrado == -1) //Loowater is doomed
					break;
				else{ //Si no eliminamos el caballero que acabamos de gastar
					coste +=minimo;
					caballeros.erase(caballeros.begin() +encontrado);
				}
    		}
    		if(encontrado == -1)
    			cout << "Loowater is doomed!" << endl;
    		else
    			cout << coste << endl;
    	}
    	else
    		cout << "Loowater is doomed!" << endl;

    }
    return 0;
}