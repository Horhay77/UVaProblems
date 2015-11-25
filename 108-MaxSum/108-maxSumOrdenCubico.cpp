/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>

using namespace std;
int sumFilas[100][100][100];

int kadane(int izqCol, int numColumnas, int tamMatriz);


int main(int argc, char** argv) {
    /*Solución al problema 108: Max sum*/
    ios_base::sync_with_stdio(false);
    int N;
    int i,j,k,l;
    cin >> N;
    int M[N][N];
    //int sumFilas[N][N][N];
    for(i = 0; i< N ; i++)
        for (j = 0; j < N; j++)
            for ( k = 0; k < N ; k++)
                sumFilas[i][j][k]=0;

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            cin >> M[i][j];
            for(l = 0; l <= j; l++){
                for(k = (j-l); k < N-l;k++)
                    sumFilas[i][l][k]+=M[i][j]; // k es el numero de columnas 
            }
        }
    }
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            for(k = 0; k < N-j; k++){
                //cout << "Fila: " << i <<" Columna: " << j << " NumColumnas: "<< k+1 << " SumTotal: " << sumFilas[i][j][k] << endl;
            }
        }
    }
    int max = M[0][0];
    int result;
    for(i = 0; i < N; i++) //Desde la columna I
        for(j = i; j < N ; j++){ //Hasta la columna J
            //cout << "ColumnaIzquierda: " << i << " NumColumnas: " << j << endl;
            //cout << sumFilas[0][i][j-1]<< endl;
            result = kadane(i,j-i,N);
            //cout << result << endl;
            if(max < result )
                max = result;
        }
    cout << max << endl;
    return 0;
}

int kadane(int izqCol, int numColumnas, int tamMatriz){
    int maxAhora = sumFilas[0][izqCol][numColumnas];
    int maxHastaAqui = maxAhora;
    //cout << "ColumnaIzquierda: " << izqCol << " NumColumnas: " << numColumnas << " MaxAhora: " << maxAhora << endl;
    for(int i = 1; i < tamMatriz ; i++){
        if (maxHastaAqui + sumFilas[i][izqCol][numColumnas] < sumFilas[i][izqCol][numColumnas])
            maxHastaAqui = sumFilas[i][izqCol][numColumnas];
        else
            maxHastaAqui += sumFilas[i][izqCol][numColumnas];
        if (maxAhora < maxHastaAqui)
            maxAhora = maxHastaAqui;
    }
    return maxAhora;
}
