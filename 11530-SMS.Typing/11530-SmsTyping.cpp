/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>

using namespace std;

int sms(int argc, char** argv) {
    /*Solución al problema 11530: SMS typing*/
    int textos;
    int tam[123];
    for(int i = 0; i < 123; i++) tam[i]=0;
    tam[32]=1;
    for(int i = 97; i < 115 ; i++)
        tam[i]=((i-1)%3)+1;
    tam[115]=4;
    tam[116]=1;tam[117]=2;tam[118]=3;
    tam[119]=1;tam[120]=2;tam[121]=3;tam[122]=4;
    cin >> textos;
    string frase;
    getline(cin,frase);
    int leidos = 0;
    while(leidos < textos){
        int suma = 0;
        getline(cin, frase);
        //cout << "Caso " << leidos <<" " << frase;
        for(int i = 0; i< frase.size();i++){
            suma +=tam[frase.at(i)];
            //cout << tam[frase.at(i)];
        }
        cout<<"Case #"<<(leidos+1)<<": " << suma;
        if(leidos < textos)
            cout << endl;
        leidos++;
    }
    return 0;
}

