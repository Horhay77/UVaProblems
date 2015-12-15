/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    //ios_base::sync_with_stdio(false);
    long long int n,m;
    stringstream salida;
    while(cin >> n >> m){
    	if(m > 1 && n > 1){
    		long long int p= 1;
    		long long int lastp=0;
	    	stack<long long int> seq;
	    	seq.push(p); //meto el 1
	    	while(p < n && lastp<p){
	    		lastp = p;
	    		p*=m;
	    		seq.push(p); //metere m,m^2, m^3, m^4, hasta que me pase de n.
	    	}
	    	if(p == n){ //si n era una potencia de m, que es el unico caso posible, right?
	    		salida << seq.top();
	    		seq.pop();
	    		while(!seq.empty()){
	    			salida<< " "<< seq.top();
	    			seq.pop();
	    		}
			}
			else salida << "Boring!";
			salida << endl;
		}
		else
			salida << "Boring!"<<endl;
    }
    cout << salida.str();
    return 0;
}