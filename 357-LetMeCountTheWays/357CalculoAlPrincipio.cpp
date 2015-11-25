/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>
//#include <cstdio>
using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int mayorNumCalculado = 0;
    unsigned long long formasDevolverCambio[5][30001];
    int valorMonedas[5]={1,5,10,25,50};
    int cambioActual;
    unsigned long long suma;
    unsigned long long formasDistintas;
    for(int i = 0; i < 5; i++)
    	formasDevolverCambio[i][0]=1;
    for(int i = 1; i <30001;i++){
        formasDevolverCambio[0][i]=1;
        for(int j = 1; j < 5; j++){
            suma = 0;
            if(i-valorMonedas[j]>=0)
                suma = formasDevolverCambio[j][i-valorMonedas[j]];
            formasDevolverCambio[j][i] = formasDevolverCambio[j-1][i] + suma;
        }
    }
    while(cin>>cambioActual){
    	formasDistintas = formasDevolverCambio[4][cambioActual];
    	if(formasDistintas==1)
    		cout << "There is only 1 way to produce " << cambioActual << " cents change." <<endl;
    		//printf("There is only 1 way to produce %d cents change.\n",cambioActual);
    	else
    		cout << "There are " << formasDistintas << " ways to produce " << cambioActual << " cents change." <<endl;
    		//printf("There are %llu ways to produce %d cents change.\n", formasDistintas, cambioActual);
    }
    return 0;
}