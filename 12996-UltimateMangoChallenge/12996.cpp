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
    int tiposDeMango;
    int limite;
    int cantidadMangos[10];
    int limiteMangos[10];
    int mangosEnMesa;
    cin >> numCasos;
    while(casoActual <= numCasos){
    	cin >> tiposDeMango >> limite;
    	mangosEnMesa = 0;
    	for(int i = 0; i < tiposDeMango ; i++){
    		cin >> cantidadMangos[i];
    		mangosEnMesa += cantidadMangos[i];
    	}
    	bool posible = true;
    	for(int i = 0; i < tiposDeMango ; i++){
    		cin >> limiteMangos[i];
    		if(limiteMangos[i] < cantidadMangos[i])
    			posible = false;
    	}
    	if(mangosEnMesa > limite)
    		posible = false;

    	cout << "Case " << casoActual << ": " <<(posible ? "Yes" : "No") << endl;
    	casoActual++;
    }
    return 0;
}