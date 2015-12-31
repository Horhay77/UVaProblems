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
    int actualCase=1;
    int tam;
    stringstream output;
    while(true){
    	cin >> tam;
    	if(!tam)break;
    	int mat[tam][tam];
    	output << "Case "<<actualCase<<":";// << actualCase;
    	for(int i = 0; i < tam; i++)
    		for(int j = 0; j < tam ; j++)
    			cin >>mat[i][j];
    	for(int col = 0; col < (tam+1)/2;col++){
    		int sum = 0;
    		//sumar columna 0 + col, tam -1 -col desde la fila 0+col hasta la fila tam-1-col
    		for(int i = col; i < tam -col;i++){ //fila
    			if(i == col) //primera fila
    				for(int j = col; j < tam - col; j++)
    					sum+= mat[i][j];
    			else if(i == tam - 1 - col) //ultima fila
    				for(int j = col; j < tam - col; j++)
    					sum+=mat[i][j];
    			else
    				sum+=mat[i][col]+mat[i][tam-1-col];
    		}
    		output << " " << sum;
		}
		output << endl;
		actualCase++;
    }
    cout << output.str();
    return 0;
}