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
    int month, day;
    stringstream output;
    string dias[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    int mes[12]={4,0,0,3,5,1,3,-1,2,4,0,2};
    for(int actualCase = 1; actualCase <= cases; actualCase++){
    	cin >> month >> day;
    	int coso = (mes[month-1]+day)%7;
    	output << dias[coso]<<endl;
    }
    cout << output.str();
    return 0;
}