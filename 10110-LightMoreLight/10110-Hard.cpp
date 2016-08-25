/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <sstream>
#include <climits>
#include <vector>

using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    unsigned int number;
    unsigned int i;
    unsigned int divisores;
    while(cin >> number){
    	if(number == 0) break;
    	if(number == 1) cout << "yes" << endl;
    	else{
    		//vector< unsigned int > divisor;
    		vector< int > times;
    		for(int i = 2; i <= number ;i++){
    			if(i*i > number){
    				times.push_back(1);
    				break; //el numero es primo, es su propio divisor
    			}
    			else if(!(number % i)){
    				//divisor.push_back(i);
    				times.push_back(0);
    				while(!(number%i)){
    					number /= i;
    					times[times.size()-1]++; 
    				}
    			}
    		}
    		divisores = 1; //1 siempre divide :D
    		for(int i = 0; i < times.size();i++){
    			//cout << times[i]<< " ";
    			divisores *= times[i]+1;
    		}
    		if(!(divisores %2))
    			cout << "no" << endl;
    		else
    			cout << "yes" << endl;
    	}
    }
    return 0;
}