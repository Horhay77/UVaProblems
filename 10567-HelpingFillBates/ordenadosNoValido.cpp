/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>

using namespace std;

//Variables globales


//Procedimientos
int indiceEstado(char letra);

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int casoActual = 1,numCasos;
    string frase;
    getline(cin,frase);

    //cout << indiceEstado('A') << " " << indiceEstado('Z') << " " << indiceEstado('a') << " " << indiceEstado('z');
    int frecuencias[52];//Cantidad de candidatos de cada uno de los estados
    for(int i = 0; i < 52;i++)
    	frecuencias[i]=0;
    for(int i = 0; i < frase.size();i++)
    	frecuencias[indiceEstado(frase.at(i))]++;
    /*for(int i = 0; i < 52;i++)
    	if(frecuencias[i])
 		   	cout << i << " " << frecuencias[i] << endl;*/
    int frecuenciasAcumuladas[52];
    frecuenciasAcumuladas[0]=frecuencias[0];
    for(int i = 1; i < 52;i++){
    	frecuenciasAcumuladas[i]=frecuenciasAcumuladas[i-1]+frecuencias[i];
    }
    int frecuenciasActuales[52];
    cin >> numCasos;
    cin.ignore();
    while(casoActual <= numCasos){
    	casoActual++;
    	getline(cin,frase);
    	for(int i = 0; i < 52; i++)
    		frecuenciasActuales[i]=0;
	    for(int i = 0; i < frase.size();i++)
	    	frecuenciasActuales[indiceEstado(frase.at(i))]++;
	    /*for(int i = 0; i < 52;i++)
    		if(frecuenciasActuales[i])
 		   		cout << i << " " << frecuenciasActuales[i] << endl;*/
	    int minimo = -1, maximo = -1,penultimomaximo = -1;
	    bool match = true;
	    for(int i = 0; i < 52; i++){
	    	if(frecuenciasActuales[i] > frecuencias[i]){
	    		match = false;
	    		break;
	    	}
	    	else{
	    	 	if(minimo ==-1){
	    	 		minimo = i;
	    	 		maximo = i;
	    	 		penultimomaximo = i;
	    	 	}
	    	 	if(frecuencias[i]>0){
		    	 	penultimomaximo = maximo;
		    		maximo = i;
		    	}
	    	}
	    }
	    if(!match)
	    	cout << "Not matched" << endl;
	    else
	    	cout << "Matched " << frecuenciasAcumuladas[minimo]-frecuencias[minimo]
	    	     << " " << frecuenciasAcumuladas[penultimomaximo] + frecuenciasActuales[maximo] << endl; 

    }
    return 0;
}

int indiceEstado(char letra){
	int indice = int(letra);
	if(indice <= 90 )
		return indice - 65;
	else 
		return indice - 71;
}