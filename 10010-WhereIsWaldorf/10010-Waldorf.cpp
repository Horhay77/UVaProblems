/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

//Variables globales


//Procedimientos
void leerSopaDeLetras(char sopaDeLetras[51][51],int numFilas);

int main(int argc, char** argv) {
    /*Solución al problema 10010:  WHERE IS WALDORF?*/
    ios_base::sync_with_stdio(false);
    int casoActual = 1,numCasos;
    scanf("%d\n",&numCasos);
    char sopaDeLetras[51][51]; //Sopa de letras
    int numFilas, numColumnas; //Para almacenar el tamaño
    int numPalabras; //Cuantas palbras toca buscar
    int tamPalabra;
    char palabra[51];
    int coincidencias;
    //string palabra;
    int i,j,k; // Para recorrer la sopaDeLetras
    while(casoActual <= numCasos){
    	scanf("\n%d %d\n",&numFilas, &numColumnas);
    	//cout << numFilas << " "  << numColumnas << endl;
    	leerSopaDeLetras(sopaDeLetras,numFilas);
    	scanf("%d\n",&numPalabras);
    	//cout << numPalabras << endl;
    	for(i = 0; i < numPalabras; i++){
    		scanf("%s\n",palabra);
    		tamPalabra = strlen(palabra);
    		for(j = 0; j < tamPalabra;j++)
    			palabra[j]= toupper(palabra[j]);
    		//cout << palabra << endl;
    		//Busqueda de la palabra
    		for(j = 0; j < numFilas; j++){
    			for(k = 0; k < numColumnas ; k++){
    				//cout << "Fila: " << j+1 << " Colu: " << k+1 << endl;
	    			//Coincidencia hacia la derecha
	    			if(k+tamPalabra<= numColumnas){
	    				coincidencias=0;
	    				while(palabra[coincidencias] == sopaDeLetras[j][k+coincidencias] && coincidencias < tamPalabra)
	    					coincidencias++;
	    				if(coincidencias == tamPalabra){
	    					printf("%d %d\n",j+1,k+1);
	    					j = numFilas;
	    					k = numColumnas;
	    					break;
	    				}
	    			}
		    		//Hacia la izquierda
		    		if(k>=tamPalabra-1){
	    				coincidencias=0;
	    				while(palabra[coincidencias] == sopaDeLetras[j][k-coincidencias] && coincidencias < tamPalabra)
	    					coincidencias++;
	    				if(coincidencias == tamPalabra){
	    					printf("%d %d\n",j+1,k+1);
	    					j = numFilas;
	    					k = numColumnas;
	    					break;
	    				}
	    			}
		    		//Hacia abajo
		    		if(j+tamPalabra<= numFilas){
	    				coincidencias=0;
	    				while(palabra[coincidencias] == sopaDeLetras[j+coincidencias][k] && coincidencias < tamPalabra)
	    					coincidencias++;
	    				if(coincidencias == tamPalabra){
	    					printf("%d %d\n",j+1,k+1);
	    					j = numFilas;
	    					k = numColumnas;
	    					break;
	    				}
	    			}
		    		//Hacia arriba
		    		if(j>=tamPalabra -1){
	    				coincidencias=0;
	    				while(palabra[coincidencias] == sopaDeLetras[j-coincidencias][k] && coincidencias < tamPalabra)
	    					coincidencias++;
	    				if(coincidencias == tamPalabra){
	    					printf("%d %d\n",j+1,k+1);
	    					j = numFilas;
	    					k = numColumnas;
	    					break;
	    				}
	    			}
		    		//Hacia abajo derecha
		    		if(k+tamPalabra<= numColumnas && j+tamPalabra <= numFilas){
						coincidencias=0;
	    				while(palabra[coincidencias] == sopaDeLetras[j+coincidencias][k+coincidencias] && coincidencias < tamPalabra)
	    					coincidencias++;
	    				//cout << coincidencias << endl;
	    				if(coincidencias == tamPalabra){
	    					printf("%d %d\n",j+1,k+1);
	    					j = numFilas;
	    					k = numColumnas;
	    					break;
	    				}		    			
		    		}
		    		//Hacia arriba derecha
		    		if(k+tamPalabra<= numColumnas && j>tamPalabra -1){
						coincidencias=0;
	    				while(palabra[coincidencias] == sopaDeLetras[j-coincidencias][k+coincidencias] && coincidencias < tamPalabra)
	    					coincidencias++;
	    				if(coincidencias == tamPalabra){
	    					printf("%d %d\n",j+1,k+1);
	    					j = numFilas;
	    					k = numColumnas;
	    					break;
	    				}		    			
		    		}
		    		//Hacia abajo izquierda
		    		if(k>=tamPalabra-1 && j + tamPalabra <= numFilas){
						coincidencias=0;
	    				while(palabra[coincidencias] == sopaDeLetras[j+coincidencias][k-coincidencias] && coincidencias < tamPalabra)
	    					coincidencias++;
	    				if(coincidencias == tamPalabra){
	    					printf("%d %d\n",j+1,k+1);
	    					j = numFilas;
	    					k = numColumnas;
	    					break;
	    				}		    			
		    		}		    	
		    		//Hacia arriba izquierda
		    		if(k>=tamPalabra-1 && j>=tamPalabra -1){
						coincidencias=0;
	    				while(palabra[coincidencias] == sopaDeLetras[j-coincidencias][k-coincidencias] && coincidencias < tamPalabra)
	    					coincidencias++;
	    				if(coincidencias == tamPalabra){
	    					printf("%d %d\n",j+1,k+1);
	    					j = numFilas;
	    					k = numColumnas;
	    					break;
	    				}		    			
		    		}
    			}
    		}	    		
    		//cout << palabra << " Size: "<< strlen(palabra) << endl;
    	}
    	if(casoActual < numCasos) 
    		printf("\n");
    	casoActual++;
    }
    return 0;
}

void leerSopaDeLetras(char sopaDeLetras[51][51],int filas){
	for(int i = 0; i< filas; i++){
		scanf("%s\n",sopaDeLetras[i]);
		for(int j = 0; j < strlen(sopaDeLetras[i]);j++)
			sopaDeLetras[i][j] = toupper(sopaDeLetras[i][j]);
	}

}