/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>

using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int casoActual = 1,numCasos;
    cin >> numCasos;
    unsigned long int valorMonedas[1000];
    int numMonedas;
    int suma;
    int maxMonedas;
    while(casoActual <= numCasos){
    	cin >> numMonedas;
    	for(int i = 0; i < numMonedas ; i++)
    		cin>> valorMonedas[i]; //Leemos los valores de las monedas
    	suma = 1;
    	maxMonedas = 1;
    	for(int i = 1; i < numMonedas ; i++){
    		if(suma >= valorMonedas[i]){ //desechar la antepenultima moneda
    			suma -= valorMonedas[i-1];
    		}
    		else{
    			maxMonedas++;
    		}
			suma +=valorMonedas[i];
    	}
    	cout << maxMonedas<<endl;
    	casoActual++;
    }
    return 0;
}