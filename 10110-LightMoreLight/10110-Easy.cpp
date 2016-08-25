/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    unsigned int number;
    unsigned int sqr_root;
    while(cin >> number){
    	if(number == 0) break;
    	if(number == 1) cout << "yes" << endl;
    	else{
    		sqr_root = (unsigned int) sqrt(number);
    		if (sqr_root * sqr_root == number) cout << "yes" <<endl;
    		else cout << "no" << endl;
    	}
    }
    return 0;
}