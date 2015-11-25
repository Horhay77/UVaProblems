/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int m,n,t;
    int minimo, maximo;
    int maximoActual;
    int x,y;
    bool encontrado;
    int tiempoDesperdiciado;
    while(cin >> m >> n >> t){
    	minimo = min(t/m,t/n);
    	maximo = max(t/m,t/n);
    	tiempoDesperdiciado=0;
    	encontrado = false;
    	while(!encontrado){
	    	maximoActual=maximo;
	    	//cout << "El tiempo desperdiciado actual es " << tiempoDesperdiciado  << endl;
	    	for(x = 0, y = maximoActual; x<=maximoActual;x++,y--){
	    		//cout << "X: " << x << " Y: " << y <<endl;
	    		//cout << m*x+n*y << " vs " << t-tiempoDesperdiciado<<endl;
	    		if(m*x+n*y==(t-tiempoDesperdiciado)){
	    			//cout << "Salgo con x=" << x << " , y=" << y <<endl;
	    			encontrado=true;
	    			break;
	    		}
	    		if(x == maximoActual && maximoActual > minimo){ //Reiniciar el bucle
	    			x = -1;
	    			maximoActual--;
    				//cout << "El maximo actual es " << maximoActual<<endl;
	    			y = maximoActual+1;
	    		}
	    	}
	    	if(maximoActual < minimo){
	    		x = 0; y = 0;
	    		break;
	    	}
	    	if(!encontrado)
	    		tiempoDesperdiciado++;
		}
		cout << x+y;
		if(tiempoDesperdiciado>0)
			cout << " " << tiempoDesperdiciado;
		cout << endl;
    }
    return 0;
}