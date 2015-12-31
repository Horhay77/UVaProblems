/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    //ios_base::sync_with_stdio(false);
    //cout << int('A')-55 << " " << int('B') << " "<<int('F')-55<< endl;
    string line;
    while(getline(cin,line)){
    	if(line.at(0)=='-')
    		break;
    	if(line.at(0)=='0'){ //Pasar de hexadecimal a decimal
    		int decimal=0;
    		int base = 1;
    		for(int i = 0 ; i < line.size()-2;i++){
    			int num = int(line.at(line.size()-i-1));
    			if(num < 58)
    				num -=48;
    			else 
    				num -=55;
    			decimal+=num*base;
    			base*=16;
    		}
    		printf("%d\n",decimal);
    	}
    	else{ //pasar de dcimal a hexadecimal
    		printf("0x%X\n",atoi(line.c_str()));
    	}
    }
    return 0;
}