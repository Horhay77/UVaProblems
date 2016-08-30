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
    int cases, max, trains;
    cin >> cases;
    for(int actualCase = 1; actualCase <= cases; actualCase++){
    	cin >> trains;
    	int weights[trains];
    	int lis[trains];
        int lds[trains];
    	for(int i = 0; i < trains; i++){
    		cin >> weights[i];
    		lis[i] = 1;
            lds[i] = 1;
    	}
        /* Hay que calcular la LIS y la LDS de cada elemento y coger el que tenga suma mayor*/
        /* Pero hay que hacerlo al reves de como nos vienen los camiones xD */
        for(int i = trains - 2; i >= 0; i--){
    		for(int j = trains - 1; j > i ; j--){
    			if(weights[i] > weights[j] && 1 + lds[j] > lds[i]){
    				lds[i] = 1 + lds[j];
    			}
                if(weights[i] < weights[j] && 1 + lis[j] > lis[i]){
                    lis[i] = 1 + lis[j];
                }
    		}
    	}
    	max = 0;
    	for(int i = 0; i < trains  ; i++){
    		if(lds[i] + lis[i] -1 > max) max = lds[i] + lis[i] -1;
    	}
    	cout << max << endl;
    }
    return 0;
}