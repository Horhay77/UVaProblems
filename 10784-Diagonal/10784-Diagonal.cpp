/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>
#include <cmath>
 
using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema 10874: Diagonal*/
    ios_base::sync_with_stdio(false);
    unsigned long int diagonales;
    unsigned long int minimo;
    int casoActual = 1;
    while(cin >> diagonales){
    	if(diagonales == 0)
    		break;
    	minimo = int(floor(sqrt(2*diagonales)));
    	while((minimo*minimo-3*minimo)/2 < diagonales)
    		minimo++;
    	if(minimo < 4)
    		minimo = 4;
    	cout << "Case " << casoActual<< ": " <<minimo<<endl;
    	casoActual++;
    }
    return 0;
}