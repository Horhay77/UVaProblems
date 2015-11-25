/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>

using namespace std;

int joanna(int argc, char** argv) {
    /*Solución al problema 913: Joanna and odd numbers*/
    unsigned long long N;
    unsigned long long sol;
    while(true){
        //Lectura de datos
        cin >> N;
        if(cin.eof()) break;
        if(N == 1)
            sol = 1;
        else
            sol =  6*(N+1)*(N+1)/4-9;
        cout << sol << endl;
    }
    return 0;
}

