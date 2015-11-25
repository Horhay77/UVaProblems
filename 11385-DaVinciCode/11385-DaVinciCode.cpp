/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>
#include <map>
#include <cstdio>


using namespace std;

int main(int argc, char** argv) {
	//ios_base::sync_with_stdio(false);
	int i,j;	
	map<int,int> fibo;
	fibo[1]=0;
	fibo[2]=1;
	int num1 = 1, num2 = 2,temp;
	for(i = 2; i < 100; i++){
		fibo[num1+num2] = i;
		temp = num1;
		num1 = num2;
		num2 += temp;
	}
	//cout << fibo[377] << endl;
	int testCases,N,fiboNumber;
	int finalPos[100];
	string texto;
	int contador;
	int max ;
	scanf("%d\n",&testCases);
	//cout << testCases << endl;
	for(i = 0; i < testCases; i++){
		scanf("%d\n",&N);
		//cout << N << endl;
		max = 0;
		for(j = 0; j < N-1; j++){
			scanf("%d ",&fiboNumber);
			finalPos[j] = fibo[fiboNumber];
			if(max < finalPos[j])
				max = finalPos[j];
			//cout << finalPos[j]<< " - ";
		}
		scanf("%d\n",&fiboNumber);
		finalPos[N-1]=fibo[fiboNumber];
		if(max < finalPos[N-1])
			max = finalPos[N-1];
		//cout << "Maximo hallado: " << max << endl;
		getline(cin,texto);
		//scanf("\n");
		contador = 0;
		char solucion[max+2];
		for(j = 0; j < max; j++)
			solucion[j]=' ';
		for(j = 0; j<texto.length();j++){
			//cout<< "caracter: " << texto.at(i);
			if(isalpha(texto.at(j)))
				if(isupper(texto.at(j))){
					//cout << " va a la posicion "<< finalPos[contador];
					solucion[finalPos[contador]]=texto.at(j);
					contador++;
					if(contador == N)
						break;
				}

			//cout << endl;
		}
		solucion[max+1]='\0';
		cout << solucion << endl;
	}
	return 0;
}
