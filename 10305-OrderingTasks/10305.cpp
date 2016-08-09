/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <sstream>
#include <utility>
#include <map>
#include <queue>
#include <vector>
using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int nodes, edges;
	while(cin >> nodes >> edges){
		if (nodes == 0 && edges == 0) break;
		bool inc[nodes+1];
		map < int, vector< int > > edgelist; 
		for(int i = 1; i <= nodes; i++) inc[i]=false;
		for(int i = 0; i < edges; i++){
			int from, to;
			cin >> from >> to;
			inc[to]=true;
			edgelist[from].push_back(to);
		}
		//Kahn's algorithm
		vector<int> order;
		queue<int> visit;
		for(int i = 1; i <= nodes ; i++){
			if(inc[i]==false){
				visit.push(i);
			}
		}
		while(!visit.empty()){
			int i = visit.front();
			//cout << "El nodo "<< i << " es de comienzo"<<endl;
			visit.pop();
			order.push_back(i);
			// Delete all the outcoming edges
			vector<int>::iterator it;
			for(it = edgelist[i].begin(); it != edgelist[i].end(); ){
				int element = *it;
				//cout << "Recorro el hijo "<< element << endl;
				inc[element]=false;
				//Search if has another incoming edge
				for(int k = 1; k <= nodes;k++){
					if(k != i)
						for(int l = 0; l < edgelist[k].size(); l++)
							if(edgelist[k][l]==element){
								//cout << "Hay arista de " << k << " a " << element << endl;
								inc[element] = true;
							}
				}
				if (inc[element]==false){
					visit.push(element);
				}
				it = edgelist[i].erase(it);
			}
		}
		
		for (int i = 0; i < order.size()-1;i++){
			cout << order[i] << " ";
		}
		cout << order[order.size()-1] << endl;
	}
	
	
    return 0;
}