/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>

using namespace std;

int S[100][100][100][100];
bool T[100][100][100][100];
int M[100][100];
int i,j,k,l;

int max(int fila, int columna, int numFilas, int numColumnas);

int main(int argc, char** argv) {
    /*Solución al problema 108: Max sum*/
    int N;
    cin >> N;	
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            cin >> M[i][j];
            for(k = 0; k < N ; k++)
            	for( l = 0; l < N; l++)
            		T[i][j][k][l]=false;
        }
    }
    //cout << N << endl;
    cout << max(0,0,N,N) << endl;
	
    return 0;
}

int max(int fila, int columna, int numFilas, int numColumnas){
    int suma=0;
    int a;
    if(T[fila][columna][numFilas-1][numColumnas-1])
    	return S[fila][columna][numFilas-1][numColumnas-1];
    for(i = fila; i < fila+numFilas; i++){
        for(j = columna; j< columna+numColumnas;j++){
            suma+=M[i][j];
        }
    }
    if(numFilas > 1){
        if(suma < max(fila,columna,numFilas-1,numColumnas))
            suma = S[fila][columna][numFilas-2][numColumnas-1];
        if(suma < max(fila+1,columna,numFilas-1,numColumnas))
            suma = S[fila+1][columna][numFilas-2][numColumnas-1];
    }
    if(numColumnas > 1){
        if(suma < max(fila,columna,numFilas,numColumnas-1))
            suma = S[fila][columna][numFilas-1][numColumnas-2];
        if(suma < max(fila,columna+1,numFilas,numColumnas-1))
            suma = S[fila][columna+1][numFilas-1][numColumnas-2];
    }
    T[fila][columna][numFilas-1][numColumnas-1] = true;
    S[fila][columna][numFilas-1][numColumnas-1] = suma;
    //cout << fila << " " << columna << " " << numFilas << " " << numColumnas << " "<< suma <<endl;
    return suma;
}
