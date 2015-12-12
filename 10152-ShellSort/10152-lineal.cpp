/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int casoActual = 0,numCasos;
    int numTurtles;
    string nombreLeido;
    cin >> numCasos;
    for(casoActual = 0; casoActual < numCasos; casoActual++){
 		cin >> numTurtles;
 		cin.ignore();
 		map<string, int> numNombre;
 		vector<string> nombres;
    	for(int i = 0; i < numTurtles ; i++){
    		getline(cin,nombreLeido);
    		numNombre[nombreLeido]=i;
    		//cout << "Aparece la tortuga: " << nombreLeido<<endl;
    		nombres.push_back(nombreLeido);
    	}
    	int ordenados[numTurtles];
    	bool aparecidos[numTurtles];
    	bool baja[numTurtles];

    	for(int i = 0; i < numTurtles;i++){
    		getline(cin,nombreLeido);
    		//cout << nombreLeido<< " es el "<< numNombre[nombreLeido] << " y ahora esta el " << i << endl;
    		ordenados[i] = numNombre[nombreLeido];
    	}

    	for(int i = numTurtles-1; i>=0; i--){
    		
    	}


    	for(int i = ultimoQueBaja; i >= 0;i--)
    		cout << nombres[ordenados[i]] <<endl;
		cout << endl;
    }
    return 0;
}