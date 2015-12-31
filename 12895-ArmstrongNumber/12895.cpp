/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int cases;
    cin >> cases;
    cin.ignore();
    stringstream output;
    string num;
    int corresp;
    //cout << int('2')-48<<endl;
    for(int actualCase = 1; actualCase <= cases; actualCase++){
    	getline(cin,num);
    	corresp = atoi(num.c_str());
    	//cout << corresp<<endl;
    	int numeros [num.size()];
    	int productos [num.size()];
    	int tam = num.size();
    	for(int i = 0; i < tam; i++){
    		numeros[i]=int(num.at(i))-48;
    		productos[i]=numeros[i];
    	}
    	int sum = 0;
    	while(sum < corresp){
    		sum = 0;
    		for(int i = 0; i < tam;i++){
    			sum += numeros[i];
    			numeros[i]*=productos[i];
    		}
    	}
    	output << (sum == corresp ? "Armstrong" : "Not Armstrong")<<endl;
    }
    cout << output.str();
    return 0;
}