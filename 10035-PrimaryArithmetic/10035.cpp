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
    long int1, int2;
    int carry;
    int numcarries;
    int tam1, tam2;
    stringstream output;
    while(true){
    	cin >> int1 >> int2;
    	numcarries = 0;
    	if(!int1 && !int2)
    		break;
    	carry = 0;
    	for(int i = 0; i <= 10; i++ ){
    		if(((int1%10)+(int2%10)+carry)>9){
    			numcarries++;
    			carry = 1;
    		}
    		else 
    			carry = 0;
    		int1 = int1/10;
    		int2 = int2/10;
    	}
    	if(!numcarries )
    		output << "No carry operation." <<endl;
    	else if(numcarries == 1)
    		output << "1 carry operation."<<endl;
    	else
    		output << numcarries << " carry operations."<<endl;
    }
    cout << output.str();
    return 0;
}