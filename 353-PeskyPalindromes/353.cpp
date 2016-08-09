/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <set>
using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    string word;
    int len = 0;
    int index = 0;

    while(cin >> word){
    	len = word.size();
    	set<string> found;
    	// Odd palindromes
    	for(int i = 0; i < len; i++){
    		index = 0;
    		while((i-index) >= 0 && (i+index) < len && word.at(i-index) == word.at(i+index)){
    			//cout << word.substr(i-index, 2*index+1) << endl;
    			found.insert(word.substr(i-index, 2*index+1));
    			index++;
    		}
    	}
    	// Even palindromes
    	for(int i = 0; i < len -1; i++){
    		index = 0;
    		while((i-index) >= 0 && (i+1+index) < len && word.at(i-index) == word.at(i+1+index)){
    			//cout << word.substr(i-index, 2*(index+1)) << endl;
    			found.insert(word.substr(i-index, 2*(index+1)));
    			index++;
    		}
    	}
		cout << "The string '" << word << "' contains " << found.size() << " palindromes."<< endl;
    }
    return 0;
}