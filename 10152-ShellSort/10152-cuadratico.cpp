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
    		aparecidos[i] = false;
    		baja[i]= false;
    	}
    	/*for(int i = 0; i < numTurtles;i++){
    		cout << i << "   " << ordenados[i]<<endl;
    	}*/
    	for(int i = 0; i< numTurtles;i++){
    		int posTortuga = ordenados[i];
    		//cout << "Arriba esta la tortuga " << posTortuga<<endl;
    		aparecidos[posTortuga] = true;
    		for(int j = 0; j < posTortuga ; j++){
    			if(aparecidos[j]==false){
    				//cout << "Baja la tortuga "<< posTortuga<<endl;
    				baja[posTortuga]=true;
    				break;
    			}
			}
    	}
    	int ultimoQueBaja = -1;
    	for(int i = 0 ; i < numTurtles;i++){
    		if(baja[ordenados[i]]==true){
    			ultimoQueBaja = i;
    		}
    	}
    	//cout << "El ultimo en bajar ha sido " << ultimoQueBaja<<endl;
    	//if(casoActual!=0)
    	for(int i = ultimoQueBaja; i >= 0;i--)
    		cout << nombres[ordenados[i]] <<endl;
		cout << endl;
    }
    return 0;
}