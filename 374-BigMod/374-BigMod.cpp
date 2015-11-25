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
//int mcd(int a, int b); //Maximo comun divisor, para saber si dos numeros son coprimos o no
//bool coprimos(int a, int b); //Devuelve si dos num son coprimos
//void cribaEratostenes(bool primos[], int tam); // Rellena la tabla de primos de 0 hasta tam -1
//int phiEuler(int modulo, bool primos[], int tam); // conocidos los primos, calcula el valor de phi(modulo)
int elevaModulo(int base,int potencia,int modulo); //Eleva aprovechandose de las cualidades de modulo

int main(int argc, char** argv) {
    /*Solución al problema 374: Big mod*/
    // La idea es usar la funcion phi de Euler para simplificar los calculos
    // ya que los exponentes funcionan como modulo phi(n) - 1. Solo vale si los numeros son
    // coprimos...
    // Como los divisores de n son cmo mucho de raiz(n) y el modulo maximo es 45k, solo necesitamos
    // calcular los primos menores que 250
    ios_base::sync_with_stdio(false);
    int base, potencia, modulo, phi;
   	//bool primos[250]; //Vamos a ver q numeros menores q 250 son primos. Posicion i == true indica q el num i es primo
   	//cribaEratostenes(primos,250);
   	//int caso=0;
    while(cin >> base >> potencia >> modulo){
    	//cout << "Base: "<<base << " Potencia: "<< potencia << " Modulo: " << modulo << endl;
    	/*if(caso !=0)
    		cout << endl;
    	
    	//cout << "Base: "<<base << " Potencia: "<< potencia << " Modulo: " << modulo << endl;
    	/*if(coprimos(base,modulo)){
    		phi = phiEuler(modulo,primos,250);
    		cout << "Funcion Phi de " << modulo << " : " << phi << endl;
    		potencia %= phi-1;
    		cout << "Base: "<<base << " Potencia: "<< potencia << " Modulo: " << modulo << endl;
    	}
    	//Hacer la potenciacion teniendo en cuenta q a^n = ((a^⁽n/2))^2)*a^(n%2)*/
    	base %= modulo;
    	if(base != 0 && potencia != 0)
    		cout << elevaModulo(base,potencia,modulo) << endl;
    	else if(base == 0)
    		cout << 0 << endl;
    	else
    		cout << 1 << endl;
    	//caso++;
    }
    return 0;
}

/*int mcd(int a, int b){ //Maximo comun divisor, para saber si dos numeros son coprimos o no
	int temp;
	while(a!=b && a!= 1 && b!=1){
		while(a > b){
			a-=b;
		}
		while(b > a){
			b-=a;
		}
	}
	if(a==b)
		return a;
	else
		return 1;
}

bool coprimos(int a, int b){ //Devuelve si dos num son coprimos 
	if(mcd(a,b)==1) return true;
	else return false;
}
void cribaEratostenes(bool primos[], int tam){ // Rellena la tabla de primos de 0 hasta tam -1
	for(int i = 0; i<tam; i++)
		primos[i] = true;
	primos[0]=false;
	primos[1]=false;
	for(int i = 2; i < tam; i++){
		if(primos[i]){
			for(int j=2*i;j < tam; j+=i)
				primos[j]=false;
		}
	}
}
int phiEuler(int modulo, bool primos[], int tam){ // conocidos los primos, calcula el valor de phi(modulo)
	bool esPrimo = true;
	int divisiblePrimos[tam];
	for(int i = 0; i < tam; i++){
		divisiblePrimos[i]=0;
		if(primos[i]) //Si es un num primo, comprobamos si es parte de la factorizacion
			while(modulo%i==0){
				esPrimo = false;
				divisiblePrimos[i]++;
				modulo/=i;
			}
	}
	if(esPrimo)
		return modulo-1;
	else{
		int res=1;
		for(int i = 0 ; i < tam; i++){
			while(divisiblePrimos[i]>1)
				res*=i;
			if(divisiblePrimos[i]==1)
				res*=(i-1);
		}
		return res;
	}
}*/

int elevaModulo(int base,int potencia, int modulo){
	if(potencia>=2){
		int res = elevaModulo(base,potencia/2,modulo);
		res *=res;
		res %=modulo;
		if(potencia%2){
			res*=base;
			res%=modulo;
		}
		return res;
	}
	else if(potencia == 1)
		return base;
	else
		return 1;
}