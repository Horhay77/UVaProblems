/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <sstream>
using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int cases,tam;
    cin >> cases;
    char quita;
    stringstream output;
    for(int actualCase = 1; actualCase <= cases; actualCase++){
    	cin >> quita >> quita >> tam;
    	long mat[tam][tam];
    	for(int i = 0; i < tam; i++)
    		for(int j = 0; j < tam; j++)
    			cin >> mat[i][j];
    	bool resp = true;
    	for(int fila = 0; fila < tam/2 && resp ; fila++){
    		for(int columna = 0; columna < tam; columna++){
    			if(mat[fila][columna]!=mat[tam-1-fila][tam-1-columna])
    				resp = false;
    			if(mat[fila][columna]<0 || mat[tam-1-fila][tam-1-columna]<0)
    				resp = false;
    		}
    	}
    	if(tam%2){//es impar
    		for(int columna = 0; columna < tam/2+1 && resp; columna++){
    			if(mat[tam/2][columna]!=mat[ tam/2][tam-1-columna])
    				resp = false;
    			if(mat[tam/2][columna]<0 || mat[tam/2][tam-1-columna]<0)
    				resp = false;
    		}
    	}
    	output << "Test #"<<actualCase<<": "<< (resp?"Symmetric.":"Non-symmetric.")<<endl;
    }
    cout << output.str();
    return 0;
}