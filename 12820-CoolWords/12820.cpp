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


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int wordsNumber, wordSize, lastNumber;
    int response,nletters;
    stringstream output;
    string word;
    int actualCase = 1;
    while(cin>> wordsNumber){
		cin.ignore();
		response = 0;
    	for(int i = 0; i < wordsNumber; i++){
    		getline(cin,word);
    		wordSize = word.size();
    		vector<int> appearing (26);
	    	for(int i = 0; i < 26 ; i++)
	    		appearing[i]=0;
	    	for(int i = 0; i < wordSize; i++)
	    		appearing[(int) (word.at(i)-'a')]++;
	    	sort(appearing.begin(),appearing.end());
	    	lastNumber = 0;
	    	nletters = 0;
	    	response++;
	    	for(int i = 0; i < 26; i++){
	    		if(appearing[i]>0 ){
	    			nletters++;
	    			if(lastNumber == appearing[i]){
	    				response--;
	    				break;
	    			}
    				lastNumber = appearing[i];
    			}
	    	}
	    	if(nletters < 2) response--;
	    }
	    output<< "Case "<<actualCase<<": " << response << endl;
	    actualCase++;
    }
    cout << output.str();
    return 0;
}