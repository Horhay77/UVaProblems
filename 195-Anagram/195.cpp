/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

//Variables globales


//Procedimientos
bool comparaTexto(char c1, char c2){ //65 y otro 97
	int n1 = int (c1);
	int n2 = int (c2);
	if(n1<91)
		n1-=65;
	else n1-=97;
	if(n2<91)
		n2-=65;
	else n2-=97;
	if(n1==n2)
		return int(c1)<int(c2);
	else
		return n1 < n2;
}
int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int cases;
    cin >> cases;
    cin.ignore();
    stringstream output;
    string line;
    for(int actualCase = 1; actualCase <= cases; actualCase++){
    	getline(cin, line);
    	vector<char> letras;
    	for(int i = 0; i < line.size();i++)
    		letras.push_back(line.at(i));
    	sort(letras.begin(),letras.end(),comparaTexto);
    	do {
    		for(int i = 0; i < line.size(); i++){
    			output << letras[i];
    		}
    		output << endl;
  		} while ( next_permutation(letras.begin(),letras.end(),comparaTexto) );
    }
    cout << output.str();
    return 0;
}