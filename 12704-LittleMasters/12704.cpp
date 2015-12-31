/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <sstream>
#include <math.h>
#include <cstdio>
using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int cases;
    cin >> cases;
    double x,y,r;
    double maxb,minb;
    for(int actualCase = 1; actualCase <= cases; actualCase++){
    	cin >> x>>y>>r;
    	maxb = r + sqrt(x*x+y*y);
    	minb = 2*r-maxb;
    	printf("%.2f %.2f\n",minb,maxb);
    }
    return 0;
}