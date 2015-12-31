/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//Variables globales

typedef struct{
	int entero;
	string real;
}
par;
//Procedimientos
bool comparaPares(par p1, par p2){
	return p1.entero < p2.entero;
}
int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int cases;
    cin >> cases;
    cin.ignore();
    stringstream output;
    string leerEnteros,leerReales;
    for(int actualCase = 1; actualCase <= cases; actualCase++){
    	//Saco los enteros
    	getline(cin,leerEnteros);
    	getline(cin,leerEnteros);
    	stringstream sacaInts(leerEnteros);
    	getline(cin,leerReales);
    	stringstream sacaFloats(leerReales);
    	int enteroLeido;
    	string floatLeido;
    	vector< par > pares; 
    	while(sacaInts>>enteroLeido && sacaFloats >> floatLeido){
    		par p;
    		p.entero = enteroLeido;
    		p.real = floatLeido;
    		pares.push_back(p);
    	}
    	//Ordeno el primero a la vez que ordeno el segundo:
    	sort(pares.begin(), pares.end(), comparaPares);
    	for(int i = 0; i < pares.size(); i++){
    		output << pares[i].real << endl;
    	}
    	if(actualCase < cases)
    		output << endl;
    }
    cout << output.str();
    return 0;
}