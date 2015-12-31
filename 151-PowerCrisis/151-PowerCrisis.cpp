/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <sstream>
using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int caso;
    int salidas[] = {1 ,18 ,10 ,11 ,7 ,17 ,11 ,15 ,29 ,5 ,21 ,13 ,26 ,14 ,11 ,23 ,22 ,9 ,73 ,17 ,42 ,7 ,98 ,15 ,61 ,22 ,84 ,24 ,30 ,9 ,38 ,15 ,54 ,27 ,9 ,61 ,38 ,22 ,19 ,178 ,38 ,53 ,79 ,68 ,166 ,20 ,9 ,22 ,7 ,21 ,72 ,133 ,41 ,10 ,82 ,92 ,64 ,129 ,86 ,73 ,67 ,19 ,66 ,115 ,52 ,24 ,22 ,176 ,10 ,57 ,137 ,239 ,41 ,70 ,60 ,116 ,81 ,79 ,55 ,102 ,49 ,5 ,22 ,54 ,52 ,113 ,15 ,66};
    stringstream output;
    while(cin >> caso){
    	if(caso == 0)
    		break;
    	else 
    		output << salidas[caso -13]<<endl;
    }
    cout << output.str();
    return 0;
}