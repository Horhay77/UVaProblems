/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>
#include <algorithm>

using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int b1,g1,c1,b2,g2,c2,b3,g3,c3;
    int bcg,bgc,cgb,cbg,gcb,gbc;
    //int posibilidades[6];
    int min;
    while(cin >> b1){
    	cin >> g1 >> c1 >> b2 >> g2 >> c2 >> b3 >> g3 >> c3;
    	bgc = b2+b3+g1+g3+c1+c2;
    	bcg = b2+b3+c1+c3+g1+g2;
    	cgb = c2+c3+g1+g3+b1+b2;
    	cbg = c2+c3+b1+b3+g1+g2;
    	gcb = g2+g3+c1+c3+b1+b2;
    	gbc = g2+g3+b1+b3+c1+c2;
    	int q[6] = {bcg,bgc,cgb,cbg,gcb,gbc};
    	sort(q,q+6);
    	min = q[0];
    	if(min == bcg) cout << "BCG ";
    	else if(min == bgc) cout << "BGC ";
    	else if(min == cbg) cout << "CBG ";
    	else if(min == cgb) cout << "CGB ";
    	else if(min == gbc) cout << "GBC ";
    	else cout << "GCB ";
    	
    	cout << min << endl;
    }
    return 0;
}