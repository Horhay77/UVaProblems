/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>
#include <cmath>
using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int casoActual = 1,numCasos;
    int numBloques;
    int primeraDivision;
    int cubeRoot;
    int sqrRoot;
    int minArea;
    int nuevaArea;
    int i,j,k;
    cin >> numCasos;
    while(casoActual <= numCasos){
    	cin >> numBloques;
    	minArea = 10000;
    	cubeRoot = 1;
    	while(cubeRoot*cubeRoot*cubeRoot<numBloques)
    		cubeRoot++;
    	for(i = 1; i <= cubeRoot;i++){
    		if(numBloques%i==0){
    			primeraDivision = numBloques/i;
    			sqrRoot = 1;
    			while(sqrRoot*sqrRoot<primeraDivision)
    				sqrRoot++;
    			for(j = i; j <= sqrRoot;j++){
    				if(primeraDivision%j==0){
    					k = primeraDivision/j;
    					//cout << numBloques << " = " << i << " * " << j << " * " << k <<endl;
    					nuevaArea = 2*i*j+2*i*k+2*k*j;
    					if(minArea > nuevaArea)
    						minArea = nuevaArea;
    				}
    			}
    		}
    	}
    	cout << minArea << endl;
    	casoActual++;
    }
    return 0;
}