/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    /*Solución al problema 272: Tex Quotes*/
    string linea;
    int i;
    char c;
    int queToca = 0;
    while(getline(cin,linea)){
        //Lectura de datos
        for(i = 0; i < linea.length(); i++){
            c = linea.at(i);
            if( !queToca && c == '"'){
                cout << "``";
                queToca = 1;
            }
            else if(queToca && c == '"'){
                cout << "''";
                queToca =0;
            }
            else
                cout << c;
            
        }
        cout << endl;
    }
    return 0;
}

