/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <sstream>
#include <vector>
 #include <stack>
using namespace std;

//Variables globales


//Procedimientos
typedef struct{
	int nodos;
	vector< vector<int> > ady;
} grafo;

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int nodos,aristas;
    stringstream output;
    while(cin>>nodos>>aristas){
    	int grados[nodos];
    	for(int i = 0; i <nodos;i++)
    		grados[i]=0;
    	int nodo1,nodo2;
    	grafo g;
    	g.nodos = nodos;
    	vector< vector <int> > adya (nodos);
    	g.ady = adya;
    	bool marcado[nodos];
    	for(int i = 0; i < nodos;i++)
    		marcado[i]=false;
    	for(int i = 0; i < aristas;i++){
    		cin >> nodo1 >> nodo2;
    		grados[nodo1]++;
    		grados[nodo2]++;
    		marcado[nodo1]=true;
    		marcado[nodo2]=true;
    		g.ady[nodo1].push_back(nodo2);
    		g.ady[nodo2].push_back(nodo1);
    	}
    	int numImp = 0;
    	for(int i = 0; i <nodos;i++)
    		if(grados[i]%2)
    			numImp++;
		if(numImp > 0 || !aristas)    	
    		output << "Not Possible"<<endl;
    	else{
    		//Hay que comprobar que el grafo sea conexo para los que salieron, osea, basta hacer una busqueda en anchura
    		bool visitados[nodos];
    		int marcados=0;
    		stack<int> recorrido;
    		for(int i = 0; i < nodos; i++)
    			visitados[i]=false;
    		for(int i = 0; i < nodos; i++)
    			if(marcado[i]){
    				visitados[i]=true;
    				recorrido.push(i);
    				marcados++;
    				break;
    			}
    		while(!recorrido.empty()){
    			int ahora = recorrido.top();
    			recorrido.pop();
    			for(int i = 0; i < g.ady[ahora].size();i++){
    				int hijo = g.ady[ahora][i];
    				if(!visitados[hijo]){
						visitados[hijo]=true;
						marcados++;
						recorrido.push(hijo);    					
    				}
    			}
    		}
    		int sum=0;
    		for(int i = 0; i < nodos;i++)
    			if(marcado[i]) sum++;
    		if(marcados == sum)
    			output << "Possible"<<endl;
    		else
    			output << "Not Possible"<<endl;
    	}
    }
    cout << output.str();
    return 0;
}