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
    int cases,fieldLength, scarecrows;
    cin >> cases;;
    stringstream output;
    string field;
    for(int actualCase = 1; actualCase<= cases;actualCase++){
    	scarecrows = 0;
    	cin >> fieldLength;
    	cin.ignore();
    	getline(cin,field);
    	for(int i = 0; i < fieldLength;i++){
    		if(field.at(i)=='.'){
    			scarecrows++;
    			if(i < fieldLength-2){
    				field.at(i+1)='#';
    				field.at(i+2)='#';
    			}
    			else if(i < fieldLength -1)
    				field.at(i+1)='#';
    		}
    	}
    	output << "Case "<< actualCase <<": "<<scarecrows<<endl;
    }
    cout<< output.str();
    return 0;
}