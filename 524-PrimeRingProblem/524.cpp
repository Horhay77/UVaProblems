/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int ringsize;
    int actualCase = 1;
    int last;
    bool isPrime[] = {
    	// 0 , 1   , 2   , 3   ,     4
    	false, true, true, true, false,
		// 5,    6,     7,     8,     9,
		true, false, true, false, false,
		// 10,   11,     12,  13,    14
		false, true, false, true, false,
		// 15,    16,   17,    18,   19,
		false, false, true, false, true,
		// 20,    21,    22,   23,    24,
		false, false, false, true, false,
		//  25,   26,    27,    28,   29,
		false, false, false, false, true,
		// 30,   31,    32,    33,    34
		false, true, false, false, false
    };
  	vector< vector < vector < int > > > buenos;
  	vector < vector < int> > ph;
  	for(int i = 0; i < 17; i++){
  		buenos.push_back(ph);
  	}

    while(cin >> ringsize){
    	if (actualCase != 1) cout << endl;
    	if(buenos.at(ringsize).size() == 0){
	    	queue < vector < int> > anillos;
	    	vector<int> ring;
	    	ring.push_back(1);
	    	anillos.push(ring);
	    	while(!anillos.empty()){
	    		vector<int> coso = anillos.front();
	    		anillos.pop();
	    		/*for (int i = 0; i < coso.size() ; i++){
	    			cout << coso.at(i)<< " ";
	    		}
	    		cout << endl;*/
	    		if(coso.size() < ringsize -1){
		    		last = coso.back();
		    		for (int i = 1; i <= ringsize; i++){
		    			if (isPrime[last+i]){
		    				bool encontrado = false;
		    				for(int j = 0; j < coso.size(); j++){
		    					if( coso.at(j)== i){
		    						encontrado = true;
		    						break;
		    					}
		    				}
		    				if(!encontrado){
		    					//cout << "Añado "<< i << endl;
		    					vector < int > newcoso;
		    					for (int j = 0; j < coso.size(); j++)
		    						newcoso.push_back(coso.at(j));
		    					newcoso.push_back(i);
		    					anillos.push(newcoso);
		    				}
		    			}

		    		}
		    	}
		    	else{
		    		last = coso.back();
		    		for (int i = 1; i <= ringsize; i++){
		    			if (isPrime[last+i] && isPrime[1+i]){
		    				bool encontrado = false;
		    				for(int j = 0; j < coso.size(); j++){
		    					if( coso.at(j) == i){
		    						encontrado = true;
		    						break;
		    					}
		    				}
		    				if(!encontrado){
		    					vector < int > newcoso;
		    					for (int j = 0; j < coso.size(); j++)
		    						newcoso.push_back(coso.at(j));
		    					newcoso.push_back(i);
		    					buenos.at(ringsize).push_back(newcoso);
		    				}
		    			}
		    		}	
		    	}
	    	}
		}
    	cout << "Case " << actualCase << ":" << endl;
    	for(int i = 0; i < buenos.at(ringsize).size();i++){
    		vector<int> imprime = buenos.at(ringsize).at(i);
    		for(int j = 0; j < imprime.size()-1;j++)
    			cout << imprime.at(j) << " ";
    		cout << imprime.at(imprime.size()-1)<< endl;
    		
    	}
    	actualCase++;
    }
    return 0;
}