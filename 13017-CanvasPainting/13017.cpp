/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

//Variables globales
//Procedimientos
int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int casoActual,numCasos;
    long int numCanvas,tamCuadro;
    long long int minimo;
    long long int a,b;
    while(cin >> numCasos){
        casoActual = 1;
        while(casoActual <= numCasos){
        	priority_queue<long long int , vector<long long int >, greater<long long int> > myQ;
        	cin >> numCanvas;
        	for(int i = 0; i < numCanvas;i++){
        		cin>>tamCuadro;
        		myQ.push(tamCuadro); 
        	}
        	//cout << "He leido " << numCanvas << " cuadros"<<endl;
        	minimo=0;
        	if(numCanvas==1){
        		cout << 0 <<endl;
            }
        	else{
        		while(!myQ.empty()){
        			//cout << "Hay " << myQ.size() << " elementos en la cola."<<endl;
        			a = myQ.top();
        			myQ.pop();
        			//cout << "Saque "<< a << ". Hay " << myQ.size() << " elementos en la cola."<<endl;
        			b = myQ.top();
        			myQ.pop();
        			//cout << "Saque "<< b << ". Hay " << myQ.size() << " elementos en la cola."<<endl;
        			minimo+=a+b;
        			if(myQ.size()>0){
    	    			myQ.push(a+b);
        				//cout << "Meti " << a+b<<". Hay " << myQ.size() << " elementos en la cola."<<endl;
        			}
        		}
        		cout << minimo <<endl;
        	}
        	casoActual++;
        }
    }
    return 0;
}