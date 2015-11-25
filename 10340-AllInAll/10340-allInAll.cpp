/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>

using namespace std;

int allInAll(int argc, char** argv) {
    /*Solución al problema 10340: All in All*/
    stop:
    while(!cin.fail()){
        int indice = 0;
        string texto1, texto2;
        cin >> texto1 >> texto2;
        //cout <<"1: "<< texto1 << " 2: " << texto2 << endl;
        if(texto1.size()== 0 || texto2.size() == 0)
            goto stop;
        if(texto1.size() > texto2.size()){
            cout << "No" <<endl;
            goto stop;
        }
        for(int i = 0; i < texto2.size(); i++){
            //cout << "1: " << indice << " - " << texto1.at(indice) << " 2: " << i << " - " << texto2.at(i) << endl;
            if(texto1.at(indice)==texto2.at(i)){
                indice++;
                //cout << "nuevo indice: " << indice << endl;
            }
            if(indice == texto1.size()){
                cout << "Yes" << endl;
                goto stop;
            }
        }
        cout << "No" << endl;
    }
    return 0;
}