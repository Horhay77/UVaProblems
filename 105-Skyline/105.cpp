/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    /*Solución al problema 105: SKYLINE*/
    ios_base::sync_with_stdio(false);
    int h[10000]; //VECTOR DE ALTURAS
    for(int i = 0; i < 10000; i++)
    	h[i]=0;
    int x1,y,x2;
    int primerX, ultimoX;
    cin >> x1 >> y >>x2;
    primerX = x1;
    ultimoX = x2;
    for(int i = x1; i < x2;i++)
			h[i]=y;
    while(cin >> x1 >> y >> x2){
    	for(int i = x1; i < x2;i++){
    		if(y > h[i])
    			h[i]=y;
			if(x2 > ultimoX)
				ultimoX = x2;
    	}
    }
    int alturaAnterior;
    alturaAnterior = h[primerX];
    cout << primerX << " "<<alturaAnterior << " ";
    for(int i = primerX; i < ultimoX;i++){
    	if(h[i]!=alturaAnterior){
    		cout << i << " " << h[i] << " ";
    		alturaAnterior = h[i];
    	}
    }
    cout <<ultimoX << " " << 0 << endl;
    return 0;
}