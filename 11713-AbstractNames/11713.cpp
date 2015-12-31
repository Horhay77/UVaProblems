/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//Variables globales

bool compare(string w1, string w2){
	if(w1.size() != w2.size())
		return false;
	else{
		bool resp = true;
		for(int i = 0; i < w1.size();i++){
			bool vocal1 = false; bool vocal2 = false;
			if(w1.at(i)=='a' || w1.at(i)=='e' || w1.at(i)=='i' || w1.at(i)=='o' || w1.at(i)=='u')
				vocal1 = true;
			if(w2.at(i)=='a' || w2.at(i)=='e' || w2.at(i)=='i' || w2.at(i)=='o' || w2.at(i)=='u')
				vocal2 = true;
			if(!vocal1 || !vocal2)
				if(w1.at(i)!=w2.at(i)){
					resp = false;
					break;
				}
		}
		return resp;
	}
}
//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int cases;
    cin >> cases;
    cin.ignore();
    stringstream output;
    string word1, word2;
    for(int actualCase = 1; actualCase <= cases; actualCase++){
    	getline(cin,word1);
    	getline(cin,word2);
    	output << (compare(word1,word2)?"Yes":"No")<<endl;
    }
    cout << output.str();
    return 0;
}