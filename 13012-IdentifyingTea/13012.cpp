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
    int tipoTe,res1,res2,res3,res4,res5;
    int coinc;
    stringstream output;
    while(cin >> tipoTe>> res1 >> res2 >> res3 >> res4 >> res5){
    	coinc = 0;
    	if(res1 == tipoTe) coinc++;
    	if(res2 == tipoTe) coinc++;
    	if(res3 == tipoTe) coinc++;
    	if(res4 == tipoTe) coinc++;
    	if(res5 == tipoTe) coinc++;
    	output << coinc << endl;
    }
    cout << output.str();
    return 0;
}