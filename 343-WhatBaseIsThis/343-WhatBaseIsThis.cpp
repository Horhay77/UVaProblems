/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>

using namespace std;

//Variables globales


//Procedimientos
int valorCaracter(char caracter);

unsigned long int convertir(string entero, int base);
int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    string entero1, entero2;
    int base1, base2;
    unsigned long int valor1Base1, valor2Base2;
    while(cin >> entero1 >> entero2){
    	base1 = 2; base2 = 2;
    	for(int i = 0; i < entero1.size(); i++)
    		if(valorCaracter(entero1.at(i))>=base1)
    			base1 = valorCaracter(entero1.at(i))+1;
    	for(int i = 0; i < entero2.size(); i++)
    		if(valorCaracter(entero2.at(i))>=base2)
    			base2 = valorCaracter(entero2.at(i))+1;
    	valor1Base1 = convertir(entero1, base1);
    	valor2Base2 = convertir(entero2, base2);
    	while(valor1Base1 != valor2Base2 && base1 < 37 && base2 < 37){
    		//cout << entero1 << " en base1= " << base1 << " valor " << valor1Base1 <<endl;
    		//cout << entero2 << " en base2= " << base2 << " valor " << valor2Base2 <<endl;
    		if(valor1Base1 < valor2Base2){
    			base1++;
    			valor1Base1 = convertir(entero1, base1);
    		}
    		else{
    			base2++;
    			valor2Base2 = convertir(entero2, base2);
    		}    		
    	}
    	if(base1 < 37 && base2 <37){
    		cout << entero1 << " (base " << base1 << ") = " << entero2 << " (base " << base2 << ")" << endl;
    	}
    	else{
    		cout << entero1 << " is not equal to " << entero2 << " in any base 2..36"<<endl;
    	}
    }
    return 0;
}

int valorCaracter(char caracter){
	if(caracter <= '9')
		return int(caracter) -48;
	else return int(caracter) - 55;
}

unsigned long int convertir(string entero, int base){
	unsigned long int resultado = 0 ;
	int potencia = 1;
	for(int i = entero.size()-1; i >= 0; i--){
		resultado+=valorCaracter(entero.at(i))*potencia;
		potencia*=base;
	}
	return resultado;
}