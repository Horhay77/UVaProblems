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
    long long terminoActual;
    long long suma,cont;
    long long primerElementoDiagonal;
    long long diferencia;
    while(cin >> terminoActual){
    	suma = 0;
    	cont = 1;
    	while(suma+cont <terminoActual){
    		suma+=cont;
    		cont++;
    	}
    	//cout<< suma << "  " << cont<<endl;
    	primerElementoDiagonal=suma+1;
    	diferencia = terminoActual - primerElementoDiagonal;
    	//cout << "Cont: "<<cont << " Dif: " << diferencia<< endl;
    	if(!(cont%2))
    		cout << "TERM " << terminoActual << " IS " << 1+diferencia << "/" << cont -diferencia<<endl;
    	else
    		cout << "TERM " << terminoActual << " IS " << cont - diferencia << "/" << 1 + diferencia<<endl;
    }
    return 0;
}