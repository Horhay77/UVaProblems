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
	long vueltas[22][10000];
	int pos;
	// Fill matrix of ways to pay
	vueltas[0][0]=1;
	for(int col = 1; col < 10000; col++)
		vueltas[0][col] = 0;
	for(int col = 0; col < 10000; col++)
		vueltas[1][col] = 1;
	for (int row = 2; row < 22; row++){
		for (int col = 0; col < 10000; col++){
			int cube = row*row*row;
			if (col == 0)
				vueltas[row][col] = 1;
			if(col >= cube)
				vueltas[row][col] = vueltas[row-1][col] + vueltas[row][col-cube];
			else
				vueltas[row][col] = vueltas[row-1][col];

		}
	}
	while(cin >> pos)
		cout << vueltas[21][pos] << endl;
    return 0;
}