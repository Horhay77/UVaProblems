/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

//Variables globales


//Procedimientos
typedef struct{
	int f,c;
} posicion;
int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int filas, columnas;
    stringstream output;
    while(cin >> filas >> columnas){
    	if(!filas) break;
    	string matriz[filas];
    	cin.ignore();
    	for(int i = 0; i < filas; i++)
    		getline(cin, matriz[i]);
    	// * es vacio, @ significa petroleo.
    	int oilpockets = 0;
    	for(int f = 0; f < filas; f++){
    		for(int c = 0; c < columnas; c++){
    			if(matriz[f].at(c)=='@'){
    				//cout << "hay un oil pocket a partir de la pos "<< f+1 << ", "<<c+1<<endl;
    				matriz[f].at(c)='*';
    				oilpockets++;
    				stack<posicion> pila;
    				posicion p = {f,c};
    				pila.push(p);
    				while(!pila.empty()){
    					posicion p1,p2;
    					p1 = pila.top();
    					//cout << "Saco de la pila la pos " << p1.f+1 << ", "<< p1.c+1 << endl;
    					pila.pop();
    					if(p1.f>0){
    						if(matriz[p1.f-1].at(p1.c)=='@'){
    							p2.f=p1.f-1;
    							p2.c=p1.c;
    							matriz[p1.f-1].at(p1.c)='*';
    							pila.push(p2);
    						}
    						if(p1.c >0){
								if(matriz[p1.f-1].at(p1.c-1)=='@'){
    								p2.f=p1.f-1;
    								p2.c=p1.c-1;
    								matriz[p1.f-1].at(p1.c-1)='*';
    								pila.push(p2);
    							}
    						}
    						if(p1.c < columnas-1){
								if(matriz[p1.f-1].at(p1.c+1)=='@'){
    								p2.f=p1.f-1;
    								p2.c=p1.c+1;
    								matriz[p1.f-1].at(p1.c+1)='*';
    								pila.push(p2);
    							}
    						}
    					}
						if(p1.f<filas-1){
    						if(matriz[p1.f+1].at(p1.c)=='@'){
    							p2.f=p1.f+1;
    							p2.c=p1.c;
    							matriz[p1.f+1].at(p1.c)='*';
    							pila.push(p2);
    						}
    						if(p1.c>0){
								if(matriz[p1.f+1].at(p1.c-1)=='@'){
	    							p2.f=p1.f+1;
	    							p2.c=p1.c-1;
	    							matriz[p1.f+1].at(p1.c-1)='*';
	    							pila.push(p2);
	    						}
    						}
    						if(p1.c< columnas-1){
								if(matriz[p1.f+1].at(p1.c+1)=='@'){
	    							p2.f=p1.f+1;
	    							p2.c=p1.c+1;
	    							matriz[p1.f+1].at(p1.c+1)='*';
	    							pila.push(p2);
	    						}
    						}
    					}
    					if(p1.c>0)
    						if(matriz[p1.f].at(p1.c-1)=='@'){
    							p2.f=p1.f;
    							p2.c=p1.c-1;
    							matriz[p1.f].at(p1.c-1)='*';
    							pila.push(p2);
    						}
						if(p1.c<columnas-1)
    						if(matriz[p1.f].at(p1.c+1)=='@'){
    							p2.f=p1.f;
    							p2.c=p1.c+1;
    							matriz[p1.f].at(p1.c+1)='*';
    							pila.push(p2);
    						}
					}
				}
    		}
    	}
    	output << oilpockets<<endl;
    }
    cout << output.str();
    return 0;
}