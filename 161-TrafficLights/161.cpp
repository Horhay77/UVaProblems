/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int number;
    int zeroes = 0;
    int timer, quotient;
    int hour, minute, second;
    int index;
    bool move_timer_forward;
    cout <<  setfill('0');
    while(true){
    	vector<int> cycles;
    	while(cin >> number){
    		//cout << "Read "<< number << endl;
    		if (number == 0){
    			zeroes++;
    			break;
    		}
    		zeroes = 0;
    		cycles.push_back(number);
    	}
    	if(zeroes==2) break;
    	// Work with the cycles:
    	sort(cycles.begin(), cycles.end(), greater<int>());
    	timer = cycles[cycles.size()-1];
    	index = 0;
    	while(timer <= 18000){
    		if (index == cycles.size()) break;
    		quotient = timer / cycles[index];
    		//cout << "Checking at "<< timer << " Quotient: " << quotient << endl;
    		move_timer_forward = true;
    		if ( !(quotient % 2)){ // if even, the light can be green or orange
    			//cout << timer % cycles[index] << " < " << cycles[index] - 5 << endl;
    			if ((timer % cycles[index]) < (cycles[index] -5)) // the light is green
    				move_timer_forward = false;
    		}
    		if (!move_timer_forward) index++;
    		else{ timer = (quotient +1) * cycles[index];
    			index = 0;
    		}
    	}
    	second = timer % 60;
    	minute = (timer / 60)%60;
    	hour = timer /3600;
    	if (timer <= 18000)
	    	cout << setw(2) << hour<< ':'<< setw(2) << minute << ':' << setw(2) << second << endl;
	    else
	    	cout << "Signals fail to synchronise in 5 hours"<< endl;
    }
    return 0;
}