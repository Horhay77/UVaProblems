/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int cases;
    int bachelors, spinters, total, last, min;
    int actualCase = 1;
    while(cin >> bachelors >> spinters){
    	//cout << "B: " << bachelors << " S:" << spinters << endl;
    	if (bachelors == 0 && spinters == 0) break;    	
    	total = bachelors + spinters;
    	if (bachelors <= spinters){
    		for (int i = 0; i < total; i++)
    			cin >> min;
    		cout << "Case "<< actualCase<< ": 0"<<endl;
    	}
    	else{
    		min = 61;
    		for (int i = 0; i < bachelors; i++){
    			cin >> last;
    			if (last < min)	min = last;
    		}
    		for (int i = 0; i < spinters; i++)
    			cin >> last;
    		cout << "Case "<< actualCase<< ": "<< bachelors - spinters << " " << min << endl;	
    	}
    	actualCase++;
    }
    return 0;
}