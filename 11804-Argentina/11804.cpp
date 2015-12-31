/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

//Variables globales

typedef struct{
	string nombre;
	int ataque;
	int defensa;
} jugador;
//Procedimientos
bool ordena(jugador j1, jugador j2){
	if(j1.ataque != j2.ataque)
		return j1.ataque < j2.ataque;
	else if(j1.defensa != j2.defensa)
		return j1.defensa > j2.defensa;
	else return j1.nombre > j2.nombre;
}

bool ordenaNombre(jugador j1, jugador j2){
	return j1.nombre < j2.nombre;
}

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int cases;
    cin >> cases;
    stringstream output;
    for(int actualCase = 1; actualCase <= cases; actualCase++){
    	vector<jugador> players (10);
    	string nombre;
    	int att,def;
    	for(int i = 0; i < 10; i++)
    		cin >> players[i].nombre >> players[i].ataque >> players[i].defensa;
    	sort(players.begin(),players.end(),ordena);
    	sort(players.begin(), players.begin()+5,ordenaNombre);
    	sort(players.begin()+5, players.end(),ordenaNombre);
    	output << "Case "<<actualCase<<":"<<endl;
    	//atacantes
    	output<< "(" << players[5].nombre;
    	for(int i = 6 ; i < 10; i++)
    		output << ", "<< players[i].nombre;
    	output << ")"<<endl;
		//defensores
    	output<< "(" << players[0].nombre;
    	for(int i = 1 ; i < 5; i++)
    		output << ", "<< players[i].nombre;
    	output << ")"<<endl;
		
    }
    cout << output.str();
    return 0;
}