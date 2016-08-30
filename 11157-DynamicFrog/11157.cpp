/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int cases;
    cin >> cases;
    int max;
    char rock_type;
    int rocks, totaldist;
    for(int actualCase = 1; actualCase <= cases; actualCase++){
    	cin >> rocks >> totaldist;
    	if (rocks == 0)
    		cout << "Case "<< actualCase << ": "<< totaldist << endl;
    	else{
    		int dists[rocks+2];
    		bool big[rocks+2];
    		dists[0]=0;
    		big[0]=true;
    		for(int i = 1; i <= rocks; i++){
    			cin >> rock_type;
    			if (rock_type == 'B') big[i]= true;
    			else big[i]=false;
    			cin >> rock_type >>  dists[i];
    		}
    		dists[rocks+1] = totaldist;
    		big[rocks+1] = true;
    		max = 0;
    		for(int i = 0; i < rocks + 1; i++){
    			int j = i +1 ; // Next big rock
    			while( !big[j]) j++;
    			/* i = 0, j = primera roca grande*/
    			// si son adyacentes, es la distancia.
    			if(i == j -1 && max < dists[j]-dists[i])
    				max = dists[j]-dists[i];
    			if(i != j -1){
    				if(max < dists[i+1]-dists[i])
    					max = dists[i+1]-dists[i];
    				if(max < dists[j] - dists[j-1])
    					max = dists[j] - dists[j-1];
    				for(int k = i; k < j -1 ; k++)
    					if(max < dists[k+2]-dists[k])
    						max = dists[k+2]-dists[k];
    			}
    			
    		}
    		cout << "Case "<< actualCase << ": "<< max << endl;
    	}
    }
    return 0;
}