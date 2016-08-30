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
    int cases;
    int trains;
    cin >> cases;
    for(int actualCase = 1; actualCase <= cases; actualCase++){
    	cin >> trains;
    	int lengths[trains];
    	int maxtrains[trains];
    	for(int i = 0; i < trains; i++){
    		cin >> lengths[i];
    		maxtrains[i] = lengths[i];
    	}
    	for(int i = trains - 2; i >= 0;i--){
    		for(int j = trains - 1; j > i ; j--){
    			if(lengths[i] > lengths[j] && lengths[i] + maxtrains[j] > maxtrains[i]){
    				maxtrains[i] = lengths[i] + maxtrains[j];
    			}
    		}
    	}
    	int max = 0;
    	for(int i = 0; i < trains; i++){
    		if(maxtrains[i] > max) max = maxtrains[i];
    	}
    	cout << max << endl;
    }
    return 0;
}