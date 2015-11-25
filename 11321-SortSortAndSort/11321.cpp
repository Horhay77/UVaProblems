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
int modulo;

//Procedimientos
bool cmp(long long a,long long b){
	//cout << a%modulo << " vs " << b%modulo<<endl; 
	if(!(a%modulo == b%modulo)){
		return a%modulo < b%modulo;
	}
	else{ //empate.
		//cout << a << " " << a%2<<endl;
		if((a%2)==0){ //a es par
			if(b%2==0){ //b es par, luego el pequenio va primero
				//cout << a <<" < " << b << endl;
				return a < b; 
			}
			else{ // b es impar
				return false; //el par va despues
			}
		}
		else{ //a es impar
			if(b%2==0){ // b es par
				return true;
			}
			else{ //b es impar, el grande va antes
				return a > b;
			}
		}

	}
}

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int numeros;
    while(cin >> numeros >> modulo){
    	vector<long long> a (numeros);
    	for(int i = 0; i < numeros;i++)
    		cin >> a[i];
    	sort(a.begin(),a.end(),cmp);
    	cout << numeros << " " << modulo << endl;
    	for(int i = 0; i < numeros; i++)
    		cout << a[i]<<endl;
    	if(numeros == 0 && modulo == 0)
    		break;
    }
    return 0;
}