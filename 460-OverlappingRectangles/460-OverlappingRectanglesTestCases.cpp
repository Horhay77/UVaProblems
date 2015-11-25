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
    /*Solución al problema 460: Overlapping rectangles*/
    ios_base::sync_with_stdio(false);
    int x11,y11,x21,y21; // esq inf izq y sup derecha del rectangulo 1
    int x12,y12,x22,y22; // esq inf izq u sup derecha del rectangulo 2
    int casoActual=1;
    int numCasos;
    cin >> numCasos;

    while(casoActual <= numCasos){
    	cin >> x11 >> y11 >> x21 >> y21;
    	cin >> x12 >> y12 >> x22 >> y22; //Si no, leemos el segundo rectangulo
    	//Primero, detectar overlap:
    	if(x11 < x22 && x12 < x21 && y11 < y22 && y12 < y21){//Hay Overlap
    		//Buscamos el rectangulo de overlap:
    		//el lado izq es el maximo entre los dos lados izquierdos?
			cout << (x11 >= x12 ? x11 : x12) << " " << (y11 >= y12 ? y11 : y12) << " ";

			cout << (x21 <= x22 ? x21 : x22) << " " << (y21 <= y22 ? y21 : y22) << endl;
    	}
    	else
    		cout << "No Overlap"<< endl;
    	if(casoActual< numCasos) cout << endl;
    	casoActual++;
    }
    return 0;
}