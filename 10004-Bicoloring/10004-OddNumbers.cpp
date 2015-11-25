/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char** argv) {
    /*Solución al problema 913: Joanna and odd numbers*/
    int numNodos;
    int numAristas;
    int i,j;
    int posible;
    int nodo1, nodo2;
    bool primeraVez = false;
    int ultColorAsignado;
    int numCaso = 1;
    while(true){
        //cout << "Grafo con "<< numNodos << " nodos y " << numAristas << " aristas." << endl; 
        //cout << "Caso numero " << numCaso <<endl;
        scanf("%d\n",&numNodos);
        if(numNodos == 0)
        	break;
        scanf("%d\n",&numAristas);
        int colorNodo[numNodos];
        int colorOpuesto[numNodos];
        for(i=0; i < numNodos; i++){
        	colorNodo[i]=-1;
        	colorOpuesto[i] = -1;
        }
        /*for(i=0; i < numNodos; i++)
        	cout << "Nodo: " << i << " ColorNodo: " << colorNodo[i]<< endl;
		*/
        posible = true;
        ultColorAsignado = 2;
        colorNodo[0]=0;
        colorOpuesto[0]=1;
        for(i=0 ; i < numAristas; i++){
        	scanf("%d %d\n",&nodo1,&nodo2);
        	/*if(numCaso == 84){
        		cout << "Arista de nodos " << nodo1 << " y " << nodo2 << ".        	" << endl;
        		cout << "Color de los nodos: " << colorNodo[nodo1] << " y " << colorNodo[nodo2] << "." << endl;
        	}*/
        	if(posible){
	        	if(colorNodo[nodo1]!=-1){
	        		//cout << "Entro en 1" << endl;
	        		if(colorNodo[nodo2]==-1){
	        			colorNodo[nodo2]= colorOpuesto[nodo1];
	        			colorOpuesto[nodo2] = colorNodo[nodo1];
	        		}
	        		else if(colorOpuesto[nodo1]!=colorNodo[nodo2] && colorNodo[nodo1]!=colorNodo[nodo2]){ 
	        			/*Reemplazar los colores del nodo 2 por los del nodo1*/
	        			int colNodo2 = colorNodo[nodo2], colOpuestoNodo2 = colorOpuesto[nodo2];
	        			for(j = 0; j < numNodos ; j++){
	        				if(colorNodo[j] == colNodo2){
	        					colorNodo[j] = colorOpuesto[nodo1];
	        					colorOpuesto[j] = colorNodo[nodo1];
	        				}
	        				else if(colorNodo[j] == colOpuestoNodo2){
	        					colorNodo[j] = colorNodo[nodo1];
	        					colorOpuesto[j] = colorOpuesto[nodo1];
	        				}
	        			}
	           		}
	           		else if(colorNodo[nodo1]==colorNodo[nodo2]){
	           			posible = false; //Tienen el mismo color los dos nodos adyacentes.
	           		}
	        	}
	        	else if(colorNodo[nodo2]!=-1){
	        		//cout << "Entro en 2" << endl;
	        		if(colorNodo[nodo1]==-1){
	        			colorNodo[nodo1]= colorOpuesto[nodo2];
	        			colorOpuesto[nodo1] = colorNodo[nodo2];
	        		}
					else if(colorOpuesto[nodo2]!=colorNodo[nodo1] && colorNodo[nodo1]!=colorNodo[nodo2]){ /*Reemplazar colores*/
	        			/*Reemplazar los colores del nodo 1 por los del nodo2*/
	        			int colNodo1 = colorNodo[nodo1], colOpuestoNodo1 = colorOpuesto[nodo1];
	        			for(j = 0; j < numNodos ; j++){
	        				if(colorNodo[j] == colNodo1){
	        					colorNodo[j] = colorOpuesto[nodo2];
	        					colorOpuesto[j] = colorNodo[nodo2];
	        				}
	        				else if(colorNodo[j] == colOpuestoNodo1){
	        					colorNodo[j] = colorNodo[nodo2];
	        					colorOpuesto[j] = colorOpuesto[nodo2];
	        				}
	        			}
	           		}
	           		else if(colorNodo[nodo1]==colorNodo[nodo2]){
	           			posible = false; //Tienen el mismo color los dos nodos adyacentes.
	           		}
	           	}
	           	else{
	           		//cout << "Entro en 3" << endl;
	           		colorNodo[nodo1] = ultColorAsignado;
	           		colorOpuesto[nodo1] = ultColorAsignado +1;
	        		colorNodo[nodo2] = ultColorAsignado+1;
	        		colorOpuesto[nodo2] = ultColorAsignado ;
	        		ultColorAsignado += 2;
	           	}
            }
            /*if(numCaso == 84){
            	for(j = 0; j < numNodos;j++){
            		cout << " , " << colorNodo[j];
            	}
            	cout << endl;
            	for(j = 0; j < numNodos;j++){
            		cout << " , " << colorOpuesto[j];
            	}
            	cout << endl;
        	}*/
        	//cout << "Color de los nodos: " << colorNodo[nodo1] << " y " << colorNodo[nodo2] << "." << endl;
        }
        cout << (posible ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
        numCaso++;
    }
    return 0;
}

