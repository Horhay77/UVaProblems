/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Variables globales


//Procedimientos
bool cmp(string s1 , string s2){
	char c1=s1.at(0);
	char c2=s2.at(0);
	char c3= tolower(c1);
	char c4= tolower(c2);
    if(isupper(c1) && islower(c2)){
		return true;
	}
	else if(islower(c1) && isupper(c2)){
		return false;
	}
	else{
        if(c3 == c4){
			if(s1.size()>1 && s2.size()>1)
                return cmp(s1.substr(1,s1.size()),s2.substr(1,s2.size()));
            else if(s1.size()==1)
                return true;
            else if(s2.size()==1)
                return false;
        }
        else
            return c3 < c4;

	} 
}

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    
    vector<vector<int> > letrasPalabras;
    vector<string> palabras;
    vector<bool> ananagram;
    
    string palaLeida;

    while(cin >> palaLeida){

        if(palaLeida.compare("#")==0)
            break;

    	vector<int> letras (26);

    	for(int i = 0;i < 26;i++) letras[i]=0;

        for(int i = 0; i < palaLeida.size(); i++){
            char l = palaLeida.at(i);
            l = tolower(l);
            (letras[int(l)-97])++;
        }

    	bool encontrado = false;

    	for(int i = 0; i < letrasPalabras.size();i++){
    		int coinc=0;
            //cout <<"Comparo "<< palabras[i] << ((ananagram[i]==true)? "(A)": "") << " y " << palaLeida<< endl;
    		for(int j = 0; j < 26;j++){
    			if(letrasPalabras[i][j]==letras[j])
    				coinc++;
                else
                    break;
    		}
    		if(coinc==26){
    			//ANAGRAM SPOTTED
    			encontrado = true;
                ananagram[i] = true; //el que encontre era un ananagrama
    			break;
    		}
    	}
    	if(!encontrado){
    		palabras.push_back(palaLeida);
    		letrasPalabras.push_back(letras);
            ananagram.push_back(false); ///no es un ananagrama 
    	}
    }

    vector<string> impr;
    for(int i = 0; i < palabras.size();i++){
        if(ananagram[i]==false){
            impr.push_back(palabras[i]);
        }
    }

    sort(impr.begin(),impr.end(),cmp);
    for(int i = 0; i < impr.size();i++)
            cout << impr[i] << endl;
    return 0;
}