#include <iostream>

using namespace std;

//Variables globales


//Procedimientos
long matches(long players){
	//cout << "Entro con " << players << " players"<<endl;
	if(players <2)
		return 0;
	else{
		if((players%2)==1)
			return players/2+matches(1+players/2);
		else
			return players/2+matches(players/2);
	}
}

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    long players;
    // NO FUNCIONA CON NUMEROS GRANDES XD
    while(cin >> players){
    	cout << matches(players) << endl;
    }
    return 0;
}