/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <cstdio>
 using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int cases;
    char numbers[16];
    int num;
    int result;
    int pos;
    //cin >> cases;
    scanf("%d\n",&cases);
    for(int actualCase = 1; actualCase <= cases; actualCase++){
    	pos = -1;
    	result = 0;
    	for(int i= 0; i < 19; i++){
    		if (i != 4 && i != 9 && i != 14){
    			pos++;
    			scanf("%c",numbers+pos);
    			num = int(numbers[pos])-48;
    			if(pos%2){
    				result += num;
    			}
    			else{
    				if(num < 5){
    					result +=2*num;
    				}
    				else{
    					result += 2*(num-5)+1;
    				}
    			}
    		}
    		else
    			scanf(" ");
    	}
    	scanf("\n");
    	if(!(result%10)) printf("Valid\n");
    	else printf("Invalid\n");
    }
    return 0;
}