/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>
#include <limits.h>
using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    
    int casoActual;
    int adyacenciaJoven[26][26];
    int adyacenciaViejo[26][26];
    bool verticesJoven[26];
    bool verticesViejo[26];
    char jovenes;
    char dirigido;
    char origen;
    char final;
    int coste;
    int comienzoJoven;
    int comienzoViejo;
    int numAristas;
    bool visitados[26]; //Para djikstra
    int aristaMinima;
    int minimo;
    int indiceMinimo;
    //cout << int('A') - 65 << " " << int('Z') -65 << endl;
    while(cin >> numAristas){
    	if(numAristas == 0) break;
    	for(int i =0 ; i < 26 ; i++){
    		verticesViejo[i]=false;
    		verticesJoven[i]=false;
    		for(int j=0; j < 26;j++)
    			if(i!=j){
    				adyacenciaJoven[i][j]=INT_MAX/2-1;
    				adyacenciaViejo[i][j]=INT_MAX/2-1;
    			}
    			/*else{
    				adyacenciaJoven[i][j]=0;
    				adyacenciaViejo[i][j]=0;
    			}*/
    	}
    	for(int i = 0 ; i < numAristas;i++){
    		cin >> jovenes >> dirigido >> origen >> final >> coste;
    		//cout << jovenes << " " << dirigido << " " << origen << " " << final << " " << coste << endl;
    		if(jovenes == 'Y'){
    			verticesJoven[int(origen)-65]=true;
    			verticesJoven[int(final)-65]=true;
    			adyacenciaJoven[int(origen)-65][int(final)-65] = coste;
    			if(dirigido == 'B')
    				adyacenciaJoven[int(final)-65][int(origen)-65] = coste;
    		}
    		else{
    			verticesViejo[int(origen)-65]=true;
    			verticesViejo[int(final)-65]=true;
    			adyacenciaViejo[int(origen)-65][int(final)-65] = coste;
    			if(dirigido == 'B')
    				adyacenciaViejo[int(final)-65][int(origen)-65] = coste;
    		}
    	}
    	for(int i = 0; i < 26;i++){
    		adyacenciaJoven[i][i]=0;
    		adyacenciaViejo[i][i]=0;
    	}

    	cin >> origen >> final; // En origen leo la posicion de dnde parte el joven, y en final
    	// la posicion de donde parte el viejo
    	comienzoJoven = int(origen)-65;
    	comienzoViejo = int(final)-65;
    	//HACEMOS DJIKSTRA PARA la matriz joven desde comienzo joven
    	for(int i = 0; i < 26; i++)
    		visitados[i]=false;
		while(true){
    		minimo = INT_MAX;
    		indiceMinimo=-1;
    		for(int i = 0; i < 26; i++){
    			if(verticesJoven[i] && visitados[i]==false ) //&& i != comienzoJoven)
  		  			if(minimo > adyacenciaJoven[comienzoJoven][i]){
  		  				indiceMinimo=i;
  		  				minimo = adyacenciaJoven[comienzoJoven][i];
    				}
  			}
  			if(indiceMinimo==-1) break;
  			visitados[indiceMinimo]=true;
  			for(int i = 0; i < 26;i++){
  				if(verticesJoven[i]) // && i != comienzoJoven)
  					if(adyacenciaJoven[comienzoJoven][i] >
  						 adyacenciaJoven[comienzoJoven][indiceMinimo] + adyacenciaJoven[indiceMinimo][i])
  						adyacenciaJoven[comienzoJoven][i] = adyacenciaJoven[comienzoJoven][indiceMinimo] + adyacenciaJoven[indiceMinimo][i];
  			}
    	}
    	/*for(int j = 0; j < 26 ; j++)
    		if(verticesJoven[j] )
    			cout << adyacenciaJoven[comienzoJoven][j] << " ";
    	cout << endl;*/
		/*for(int i = 0; i < 26; i++){
    		if(verticesJoven[i]){
	    		for(int j = 0; j < 26 ; j++)
    				if(verticesJoven[j] )
    					cout << adyacenciaJoven[i][j] << " ";
    			cout << endl;
    		}
    	}*/
		//HACEMOS DJIKSTRA PARA la matriz vieja desde donde comienza el viejo
    	for(int i = 0; i < 26; i++)
    		visitados[i]=false;
		while(true){
    		minimo = INT_MAX;
    		indiceMinimo=-1;
    		for(int i = 0; i < 26; i++){
    			if(verticesViejo[i] && visitados[i]==false)
  		  			if(minimo > adyacenciaViejo[comienzoViejo][i]){
  		  				indiceMinimo=i;
  		  				minimo = adyacenciaViejo[comienzoViejo][i];
    				}
  			}
  			if(indiceMinimo==-1) break;
  			visitados[indiceMinimo]=true;
  			for(int i = 0; i < 26;i++){
  				if(verticesViejo[i])
  					if(adyacenciaViejo[comienzoViejo][i] >
  						 adyacenciaViejo[comienzoViejo][indiceMinimo] + adyacenciaViejo[indiceMinimo][i])
  						adyacenciaViejo[comienzoViejo][i] = adyacenciaViejo[comienzoViejo][indiceMinimo] + adyacenciaViejo[indiceMinimo][i];
  			}
    	}
		
       	//Supuestamente ya sabemos las distancias mnimas
    	//Ahora veamos cuando solapan los camino
    	minimo = INT_MAX;
    	for(int i = 0; i < 26; i++){
    		if(adyacenciaJoven[comienzoJoven][i] != (INT_MAX/2-1) && adyacenciaViejo[comienzoViejo][i]!=(INT_MAX/2-1))
    			if(adyacenciaJoven[comienzoJoven][i]+adyacenciaViejo[comienzoViejo][i] < minimo)
    				minimo = adyacenciaJoven[comienzoJoven][i]+adyacenciaViejo[comienzoViejo][i];
    	}
    	if(minimo == INT_MAX)
   			cout << "You will never meet." <<endl;
   		else{
   			cout << minimo;
   			for(int i = 0; i < 26 ; i++){
   				if(adyacenciaJoven[comienzoJoven][i] != (INT_MAX/2-1) && adyacenciaViejo[comienzoViejo][i]!=(INT_MAX/2-1))
    				if(adyacenciaJoven[comienzoJoven][i]+adyacenciaViejo[comienzoViejo][i] == minimo)
    					cout << " " << char(i+65);
   			}
   			cout << endl;
   		}
    }
    return 0;
}