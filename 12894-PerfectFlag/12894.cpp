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
    int cases;
    cin >> cases;
    stringstream output;
    float x0,y0,x1,y1,cx,cy,r,length,width;
    for(int actualCase = 1; actualCase <= cases; actualCase++){
    	cin >> x0 >> y0 >> x1 >> y1 >> cx >> cy >> r;
    	length = x1 -x0;
    	width = y1 - y0;
    	cx-=x0;
    	cy-=y0;
    	bool resp = true;
    	//cout << "Caso "<<actualCase<<endl;
    	if( width *10 != length * 6) resp = false;
    	//else cout << "Bien proporcion ancho largo"<<endl;
    	if( length != 5*r) resp = false;
    	//else cout << "Bien proporcion del radio con el largo"<<endl;
    	if(cx*20 != length*9) resp = false;
    	//else cout << "Bien situacion horizontal del centro"<<endl;
    	if(2*cy != width) resp = false;
    	//else cout << "Bien situacin vertical del centro"<<endl;
    	output << (resp ? "YES": "NO")<<endl;
    }
    cout << output.str();
    return 0;
}