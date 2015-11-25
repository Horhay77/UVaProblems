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
    
    int filas,columnas;
    int pesos[10][100]; //maximo matriz 10 filas x 100 columnas
    string caminoHastaAqui[10][100];
    int costeHastaAqui[10][100];
    while(cin >> filas >> columnas){
    	for(int I = 0; I < filas; I++){
    		for(int K = 0; K < columnas ; K++){
    			cin >> pesos[I][K];
    			if(K == 0){
    				costeHastaAqui[I][0] = pesos[I][0];
    				caminoHastaAqui[I][0] = char(I);
    			}
    		}
    	}
    	//Recorrido por columnas
    	for(int C = 1; C < columnas;C++){
    		for(int F = 0; F < filas; F++){ //Buscamos el minimo hasta este nodo
    			//cout << "Elijo entre las filas " << ((F-1)%filas) << ", " << F << " y " << (F+1)%filas << endl;
	    		int minimo = (F+filas-1)%filas;
	    		if(costeHastaAqui[minimo][C-1] > costeHastaAqui[F][C-1]){
	    			minimo = F;
	    		}
	    		else if(costeHastaAqui[minimo][C-1] == costeHastaAqui[F][C-1]){
	    			if(caminoHastaAqui[minimo][C-1]>caminoHastaAqui[F][C-1]){
	    				minimo = F;
	    			}

	    		}
				if(costeHastaAqui[minimo][C-1]> costeHastaAqui[(F+1)%filas][C-1]){
		    		minimo = (F+1)%filas;
	    		}
	    		else if(costeHastaAqui[minimo][C-1] == costeHastaAqui[(F+1)%filas][C-1]){
	    			if(caminoHastaAqui[minimo][C-1]>caminoHastaAqui[(F+1)%filas][C-1]){
	    				minimo = (F+1)%filas;
	    			}
	    		}
	    		//cout << "El minimo para ("<< F << "," << C << ") es " << minimo <<endl;
	    		costeHastaAqui[F][C] = costeHastaAqui[minimo][C-1] + pesos[F][C];
	    		caminoHastaAqui[F][C] = caminoHastaAqui[minimo][C-1] + char(F);
    		}
	    }
	    /*for(int i = 0; i < filas; i++){
	    	for (int j = 0; j < columnas ; j++)
	    		cout << pesos[i][j] << " ";
	    	cout << endl;
	    }
	    cout << endl << endl;
	    for(int i = 0; i < filas; i++){
	    	for (int j = 0; j < columnas ; j++)
	    		cout << costeHastaAqui[i][j] << " ";
	    	cout << endl;
	    }*/
	    //Busqueda del minimo en la ultima columna
	    int minimo = 0;
	    for(int F= 1; F<filas ; F++){
	    	//cout << costeHastaAqui[minimo][columnas-1] << " vs " << costeHastaAqui[F][columnas-1] << endl;
	    	if(costeHastaAqui[minimo][columnas-1] > costeHastaAqui[F][columnas-1])
	    		minimo=F;
	    	else if(costeHastaAqui[minimo][columnas-1] == costeHastaAqui[F][columnas-1])
	    		if(caminoHastaAqui[minimo][columnas-1] > caminoHastaAqui[F][columnas-1])
	    			minimo = F;

	    }
	    cout << int(caminoHastaAqui[minimo][columnas-1].at(0))+1;
	    for(int C = 1; C < columnas ; C++)
	    	cout << " "<< int(caminoHastaAqui[minimo][columnas-1].at(C))+1;
	    cout << endl << costeHastaAqui[minimo][columnas-1] <<endl;
	}
    return 0;
}