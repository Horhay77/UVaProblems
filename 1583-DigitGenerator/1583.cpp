/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int casoActual = 1,numCasos;
	string numero;
	int valorNumero;
	int cantidadCifras;
	int numeroAProbar;
	int solucion;
	int sumaActual;
	cin >> numCasos;
    while(casoActual <= numCasos){
    	cin >> numero;
    	valorNumero = atoi(numero.c_str());
    	cantidadCifras = numero.size();
    	solucion = 0;
    	numeroAProbar = valorNumero - 9*cantidadCifras;
    	for(int i = numeroAProbar; i < valorNumero;i++){
    		sumaActual= i;
    		int cifras = i;
    		for(int j = 0; j < cantidadCifras;j++){
    			sumaActual+=cifras%10;
    			cifras/=10;
    		}
    		if(valorNumero == sumaActual){
    			solucion = i;
    			break;
    		}
    	}
    	cout << solucion << endl;
    	casoActual++;
    }	
    return 0;
}