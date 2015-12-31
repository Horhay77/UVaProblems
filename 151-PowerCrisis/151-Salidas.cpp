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
    stringstream output;
    output << "{";
    for(int actualCase = 13; actualCase <= 100; actualCase++){
    	//cout << "Calculo para "<< actualCase << " regiones"<<endl;
    	int i = 1;
    	while(true){
    		//cout << "Compruebo con salto "<< i <<endl;
			bool region[actualCase];
			for(int j = 0; j < actualCase;j++)
				region[j]=true;
			int posicion = 0;
			region[0]=false;
			int apagados = 1;
			while(posicion!=12){
				int saltados=0;
				while(saltados < i){ // i es el numero minimo q hay q encontrar
					posicion++;
					posicion%=actualCase;
					if(region[posicion]==true){
						saltados++;
					}
				}
				//cout << "apago la region "<<posicion+1<<endl;
				region[posicion]=false;
				apagados++;
			}
			if(apagados == actualCase){ // hemos encontrado el num minimo
				output << i << " ,";
				//cout << "me basta con salto "<< i<<endl;
				break;
			}
			else
				i++;			
    	}
    }
    cout << output.str();
    return 0;
}