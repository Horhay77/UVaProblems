/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int parteDecimalLeida;
    int parteDecimalPorTres;
    string cadena;
    while(getline(cin,cadena)){
    	if(cadena=="END")
    		break;
    	int pos = cadena.find("0.");
    	if(pos == 0){
    		cadena=cadena.substr(2,cadena.size()); //nos quedamos solo con la parte decimal
    		parteDecimalLeida = atoi(cadena.c_str());
    		vector<int> restos; //vamos a ir guardando las partes decimales que salen
    		restos.push_back(parteDecimalLeida);
    	   	bool respuestaEncontrada=false;
	    	bool respuesta;
    	   	while(!respuestaEncontrada){
    	   		int tam = 1;
    	   		while(parteDecimalLeida/tam>10)
    	   			tam*=10;
    	   		tam*=10;
	    		parteDecimalPorTres=parteDecimalLeida*3;
	    		//cout<<parteDecimalLeida << " * 3 = " << parteDecimalPorTres << endl;
	    		//cout << "Tiene tantas cifras como cifras tiene " << tam << endl;
	    		int parteEntera = parteDecimalPorTres/tam;
	    		//cout << "Su parte entera es " << parteEntera << endl;
	    		if( parteEntera == 1 ){
	    			respuestaEncontrada=true;
	    			respuesta=false;
	    			break;
	    		}
	    		parteDecimalLeida = parteDecimalPorTres%tam; //nos cargamos la ultima
	    		//cout << "Su parte decimal es " <<  parteDecimalLeida<< endl;
	    		if(parteDecimalLeida == 0){
	    			respuestaEncontrada=true;
	    			respuesta = true;
	    			break;
	    		}
	    		for(int i = 0; i < restos.size();i++){
	    			//cout << "Comparo " << parteDecimalLeida << " con " << restos.at(i) << endl;
	    			if(parteDecimalLeida == restos.at(i)){
	    				respuestaEncontrada=true;
	    				respuesta=true;
	    				break;
	    			}
	    		}
				restos.push_back(parteDecimalLeida);
			}
			if(respuesta == true)
				cout << "MEMBER" << endl;
			else cout << "NON-MEMBER" <<endl;
	    
    	}
    	if(pos==-1){
    		cout << "MEMBER" <<endl;
    	}

	}
    return 0;
}