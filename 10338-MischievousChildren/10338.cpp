#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <list>
#include <string.h>
#include <cmath>
#include <stack>
#include <cstdlib>
#include <map>
#include <set>
#include <utility>
#include <queue>

using namespace std;

#define FOR(a,b) for(i=(a);i<(b);i++)
#define RESET(a,b) memset((a),(b),sizeof((a)))
#define ARRAY_SIZE(a) (sizeof((a))/sizeof((a[0])))
#define ORDENAR(a,b) qsort((a),ARRAY_SIZE((a)),sizeof((a[0])),compare)
#define BUSQUEDA_BINARIA(a,b) (int*) bsearch(&(b),(a),ARRAY_SIZE(a),sizeof((a[0])), compare)

#define NO false
#define SI true

int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int main () {
  ios_base::sync_with_stdio(false);
  int exponentes[19][8]={{ 1, 0, 0, 0, 0, 0, 0, 0}, //2
						 { 0, 1, 0, 0, 0, 0, 0, 0}, //3
						 { 2, 0, 0, 0, 0, 0, 0, 0}, //4
						 { 0, 0, 1, 0, 0, 0, 0, 0}, //5
						 { 1, 1, 0, 0, 0, 0, 0, 0}, //6
						 { 0, 0, 0, 1, 0, 0, 0, 0}, //7
						 { 3, 0, 0, 0, 0, 0, 0, 0}, //8
						 { 0, 2, 0, 0, 0, 0, 0, 0}, //9
						 { 1, 0, 1, 0, 0, 0, 0, 0}, //10
						 { 0, 0, 0, 0, 1, 0, 0, 0}, //11
						 { 2, 1, 0, 0, 0, 0, 0, 0}, //12
						 { 0, 0, 0, 0, 0, 1, 0, 0}, //13
						 { 1, 0, 0, 1, 0, 0, 0, 0}, //14
						 { 0, 1, 1, 0, 0, 0, 0, 0}, //15
						 { 4, 0, 0, 0, 0, 0, 0, 0}, //16
						 { 0, 0, 0, 0, 0, 0, 1, 0}, //17
						 { 1, 2, 0, 0, 0, 0, 0, 0}, //18
						 { 0, 0, 0, 0, 0, 0, 0, 1}, //19
						 { 2, 0, 1, 0, 0, 0, 0, 0}}; //20
	int primos[8]={2,3,5,7,11,13,17,19};
	int numCasos;
	int casoActual=1;
	while(cin >> numCasos){
		string palabra;
		int frecuencias[26];
		int longitud;
		unsigned long long int resultado;
		int exponentesFinales[8];
		while( casoActual <= numCasos){
			cin >> palabra;
			resultado = 1;
			longitud = palabra.size();
			if(longitud > 1){
				for(int i = 0; i < 26; i++)
					frecuencias[i]=0;
				for(int i = 0; i < 8 ;i++)
					exponentesFinales[i]=0;
				for(int i = 0; i < longitud;i++)
					frecuencias[int(palabra.at(i))-65]++;
				for(int i = 0; i < longitud -1 ; i++){
					for(int j = 0; j < 8 ; j++)
						exponentesFinales[j]+=exponentes[i][j];
				}
				for(int i = 0; i < 26; i++)
					if(frecuencias[i]>1)
						for(int k = 0; k < frecuencias[i]-1;k++)
							for(int j = 0; j < 8; j++)
								exponentesFinales[j]-=exponentes[k][j];
						
				for(int i = 0; i < 8 ; i++)
					for(int j = 0; j < exponentesFinales[i] ; j++)
						resultado*=primos[i];
			}
			cout << "Data set " << casoActual << ": " << resultado <<endl;
			casoActual++;
		}
	}
	return (0);
}
