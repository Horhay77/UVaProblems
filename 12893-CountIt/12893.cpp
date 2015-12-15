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
    int cases, response;
    long long int query;
    cin >> cases;
    stringstream output;
    for(int actualCase = 1; actualCase <= cases; actualCase++){
    	cin >> query;
    	response = 0;
    	while(query > 0){
    		response += query%2;
    		query = query/2;
    	}
    	output<< response<<endl;
    }
    cout << output.str();
    return 0;
}