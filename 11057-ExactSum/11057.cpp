/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int numLibros;
    int bajo;
    int alto;
    int solucion,suma;
    //int numCasos = -1;
    while(cin >> numLibros){
    	//numCasos++;
    	//if(numCasos>0)
    	//	cout << endl;
    	bajo = 0;
    	alto = numLibros-1;
    	vector<int> libros (numLibros);
    	for(int i = 0; i < numLibros ; i++){
    		cin >> libros[i];
    	}
    	cin >> suma;
    	sort(libros.begin(),libros.end());

    	while(bajo < alto){
    		if(libros[bajo]+libros[alto]==suma){
    			solucion=libros[bajo];
    			bajo++;
    			alto--;
    		}
    		else if(libros[bajo] + libros[alto] < suma){
    			bajo++;
    		}
    		else{
    			alto--;
    		}
		}
		cout << "Peter should buy books whose prices are "
			<< solucion << " and " << suma - solucion << "."<< endl << endl;
    }
    return 0;
}