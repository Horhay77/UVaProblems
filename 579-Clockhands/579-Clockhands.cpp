/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>
#include <cstdio>



using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int hora,min;
	char c;
 	float resta;
	while(cin >> hora >> c >> min){
 	/*while(scanf("%d:%d",&hora,&min)){*/
		if(hora == 0 && min == 0)
			break;
		resta = (60*(hora%12)-11*min)*0.5;
		if(resta <0)
			resta*=-1;
		if(resta > 180)
			resta = 360 - resta;
		printf("%.3f\n",resta);
	}
	return 0;
}
