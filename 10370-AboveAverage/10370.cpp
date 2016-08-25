/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>

using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int cases;
    int students;
    int values[101];
    double sum, roundedsum;
    double percentage;
    int read;
    cout << fixed << setprecision(3);
    cin >> cases;
    for(int actualCase = 1; actualCase <= cases; actualCase++){
    	cin >> students;
    	sum = 0;
    	for(int i = 0; i <= 100; i++) values[i]=0;
    	for(int i = 0; i < students; i++){
    		cin >> read;
    		values[read]++;
    		sum += read;
    	}
    	sum /= students;
    	roundedsum = ceil(sum);
    	if (roundedsum == sum)
    		roundedsum+=1;
    	//cout << sum <<" "<< roundedsum << endl;
    	percentage = 0;
    	for(int i = roundedsum; i <= 100;i++)
    		percentage += values[i];
    	percentage *= 100;
    	percentage /= students;
    	cout << percentage << "%"<<endl;
    }
    return 0;
}