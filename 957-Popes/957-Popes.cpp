/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>

using namespace std;

int popes(int argc, char** argv) {
    /*Solución al problema 957: Popes*/
    int totalPopes, distanceYears;
    int minYear, maxYear, maxPopes;
    int indice;
    int j;
    while(true){
        //Lectura de datos
        cin >> distanceYears;
        if(cin.eof())break;
        cin >> totalPopes;
        int years[totalPopes];
        for(int i = 0; i < totalPopes;i++)
            cin >> years[i];
        //Calculo del mayor num de papas
        indice = 0;
        maxPopes = 0;
        while(indice + maxPopes < totalPopes){
            while(years[indice+maxPopes]-years[indice]<distanceYears){
                minYear = years[indice];
                maxYear = years[indice+maxPopes];
                maxPopes++;
                if(indice+maxPopes == totalPopes)
                    break;
            }
            j = 0;
            while(years[indice+maxPopes] - years[indice+j] >= distanceYears)
                j++;
            indice+=j;
        }
        cout << maxPopes << " "<< minYear << " " << maxYear<<endl;
    }
    return 0;
}

