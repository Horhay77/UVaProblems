/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int rocks(int argc, char** argv) {
    /*Solución al problema 10443: ROCKS*/
    string readString;
    int caso = 0;
    int numTotalCasos;
    int i,j,k;
    int filas, columnas, dias;
    cin >> numTotalCasos;
    getline(cin,readString);
    
    while(caso < numTotalCasos){
        string matriz[100];
        cin >> filas >> columnas >> dias;
        char tomorrow[filas][columnas+1];
        if (dias > 0){
            for(i = 0; i < filas; i++)
                cin >> matriz[i]; // leemo el conjunto de operaciones
        }
        if(filas==0){
                getline(cin,readString);
        }
        if(columnas == 0){
            caso++;
            break;
        }
        for(i = 0; i< dias; i++){
            for(j = 0; j < filas; j++){
                for(k = 0; k < columnas; k++){
                    switch(matriz[j].at(k)){
                        case 'R':
                            if(k != 0)
                                if(matriz[j].at(k-1) == 'P'){
                                    tomorrow[j][k]='P';
                                    break;
                                }
                            if(k != columnas-1)
                                if(matriz[j].at(k+1) == 'P'){
                                    tomorrow[j][k]='P';
                                    break;
                                }
                            if(j != 0)
                                if(matriz[j-1].at(k) == 'P'){
                                    tomorrow[j][k]='P';
                                    break;
                                }
                            if(j != filas-1)
                                if(matriz[j+1].at(k) == 'P'){
                                    tomorrow[j][k]='P';
                                    break;
                                }
                            tomorrow[j][k] = 'R';
                            break;
                        case 'P':
                            if(k != 0)
                                if(matriz[j].at(k-1) == 'S'){
                                    tomorrow[j][k]='S';
                                    break;
                                }
                            if(k != columnas-1)
                                if(matriz[j].at(k+1) == 'S'){
                                    tomorrow[j][k]='S';
                                    break;
                                }
                            if(j != 0)
                                if(matriz[j-1].at(k) == 'S'){
                                    tomorrow[j][k]='S';
                                    break;
                                }
                            if(j != filas-1)
                                if(matriz[j+1].at(k) == 'S'){
                                    tomorrow[j][k]='S';
                                    break;
                                }
                            tomorrow[j][k] = 'P';
                            break;
                        case 'S':
                            if(k != 0)
                                if(matriz[j].at(k-1) == 'R'){
                                    tomorrow[j][k]='R';
                                    break;
                                }
                            if(k != columnas-1)
                                if(matriz[j].at(k+1) == 'R'){
                                    tomorrow[j][k]='R';
                                    break;
                                }
                            if(j != 0)
                                if(matriz[j-1].at(k) == 'R'){
                                    tomorrow[j][k]='R';
                                    break;
                                }
                            if(j != filas-1)
                                if(matriz[j+1].at(k) == 'R'){
                                    tomorrow[j][k]='R';
                                    break;
                                }
                            tomorrow[j][k] = 'S';
                            break;                               
                    }
                }
                tomorrow[j][columnas]='\0';
            }
            if(i < dias -1){
                for(j = 0; j < filas; j++)
                    matriz[j] = tomorrow[j];
            }
        }
        for(i = 0; i < filas; i++){
            cout << tomorrow[i] << endl;
        }
        if(filas > 0 && caso < numTotalCasos -1) cout << endl;
        caso++;
    }
    return 0;
}

