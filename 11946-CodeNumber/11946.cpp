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
    cin >> cases;
    cin.ignore();
    stringstream output;
    //cout << int('0') << int('9')<<int('A')<<endl;
    
    string cad;
    string lista = "OIZEASGTBP"; 
    for(int actualCase = 1; actualCase <= cases; actualCase++){
    	while(getline(cin,cad)){
	    	if(cad.size()>0){
	    		for(int i = 0; i < cad.size();i++){
	    			if(int(cad.at(i))>47 && int(cad.at(i))<58)
	    				output << lista[int(cad.at(i))-48];
	    			else 
	    				output << cad.at(i);
	    		}
	    		output << endl;
	    	}
    		else{//fin del caso;
    			if(actualCase<cases)
    				output << endl;
    			break;
    		}
    	}
    }
    cout << output.str();
    return 0;
}