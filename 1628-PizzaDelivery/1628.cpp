/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//Variables globales

typedef struct{
	int indiceActual;
	int indiceIzquierdoMinimo;
	int indiceDerechaMaximo;
	int ganancia;
	int tiempo;
} estado;
//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int casoActual = 1,numDeCasos;
    cin >> numDeCasos;
    int numCasas;
    int indiceNegativo,indicePositivo;
    int maximaGanancia;
    while(casoActual <= numDeCasos){
    	cin >> numCasas;
    	vector<int> distancias (numCasas);
    	vector<int> beneficios (numCasas);
    	indiceNegativo=-1;
    	indicePositivo= numCasas;
    	for(int i = 0; i < numCasas;i++){
    		cin >> distancias[i];
    		if(distancias[i]<0)
    			indiceNegativo=i;
    		if(distancias[i]>0 && indicePositivo==numCasas)
    			indicePositivo=i;
    	}
    	for(int i = 0; i < numCasas;i++)
    		cin >> beneficios[i];
    	//Ahora ya se de que dos estados puedo partir:
    	queue<estado> estadosPosibles;
    	//Busqueda del primer punto a la izquierda donde gano pasta
    	while(indiceNegativo != -1 && beneficios[indiceNegativo]+distancias[indiceNegativo]<0 )
    		indiceNegativo--;
    	if(indiceNegativo != -1){
    		estado estadoIzq = {indiceNegativo,indiceNegativo,indiceNegativo,
    							beneficios[indiceNegativo]+distancias[indiceNegativo],
    							-distancias[indiceNegativo]};
    		estadosPosibles.push(estadoIzq);
    	}
    	//Busqueda del primer punto a la derecha donde gano pasta
    	while(indicePositivo != numCasas && beneficios[indicePositivo]-distancias[indicePositivo]<0 )
    		indicePositivo++;
    	if(indicePositivo != numCasas){
    		estado estadoDer = {indicePositivo,indicePositivo,indicePositivo,
    							beneficios[indicePositivo]-distancias[indicePositivo],
    							distancias[indicePositivo]};
			estadosPosibles.push(estadoDer);
    	}
    	maximaGanancia = 0;
    	while(!estadosPosibles.empty()){
    		estado estadoActual = estadosPosibles.front();
    		//La idea es sacado un estado, mirar cual es la primera casa a la izq y a la der donde gano pasta
    		//de entre las que no he ido aun
    		indiceNegativo=estadoActual.indiceIzquierdoMinimo-1;
    		while(indiceNegativo != -1){
    			//Calculo del tiempo en llegar hasta el punto q esta a mi izquierda, q sera un punto negativo
    			int tiempoGastado = estadoActual.tiempo + distancias[estadoActual.indiceActual] - distancias[indiceNegativo];
    			if(beneficios[indiceNegativo] < tiempoGastado)
	    			indiceNegativo--;
	    		else{
	    			estado estadoIzq = {indiceNegativo, indiceNegativo, estadoActual.indiceDerechaMaximo,
	    								estadoActual.ganancia+beneficios[indiceNegativo]-tiempoGastado,
	    								tiempoGastado};
					estadosPosibles.push(estadoIzq);
	    			break;
	    		}
    		}
    		//Primera casa a la derecha dodne ganare algo:
			indicePositivo=estadoActual.indiceDerechaMaximo+1;
    		while(indicePositivo != numCasas){
    			//Calculo del tiempo en llegar hasta el punto q esta a mi izquierda, q sera un punto negativo
    			int tiempoGastado = estadoActual.tiempo + distancias[indicePositivo] - distancias[estadoActual.indiceActual];
    			if(beneficios[indicePositivo] < tiempoGastado)
	    			indicePositivo++;
	    		else{
	    			estado estadoDer = {indicePositivo, estadoActual.indiceIzquierdoMinimo, indicePositivo,
	    								estadoActual.ganancia+beneficios[indicePositivo]-tiempoGastado,
	    								tiempoGastado};
					estadosPosibles.push(estadoDer);
	    			break;
	    		}
    		}
    		if(indiceNegativo == -1 && indicePositivo == numCasas){
    			if(estadoActual.ganancia > maximaGanancia)
    				maximaGanancia = estadoActual.ganancia;
    		}
    		estadosPosibles.pop();
    	}
    	cout << maximaGanancia << endl;
    	casoActual++;
    }
    return 0;
}