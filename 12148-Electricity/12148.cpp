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
    long totalConsumption;
    long totalDays;
    long day1, month1, year1, consumption1;
    long day2, month2, year2, consumption2;
    while(cin >> cases){
    	if(cases == 0)
    		break;
    	totalDays = 0;
    	totalConsumption = 0;
    	cin >> day1 >> month1 >> year1 >> consumption1;
    	for(int i = 1; i < cases; i++){
    		cin >> day2 >> month2 >> year2 >> consumption2;
    		if (year2 == year1){
    			if(month2 == month1){
    				if(day2 == day1+1){
    					totalDays++;
    					totalConsumption+=(consumption2-consumption1);
    				}
    			}
    			else if(month2 == month1 +1){
    				if(day2 == 1){
    					if(day1 == 31 && 
    					  (month1 == 1 || month1 == 3 || month1 == 5 || month1 == 7 || month1 == 8 || month1 == 10 || month1 == 12)){
    						totalDays++;
    						totalConsumption+=(consumption2-consumption1);
    					}
    					else if(day1 == 30 &&
    						(month1 == 4 || month1 == 6 || month1 == 9 || month1 == 11)){
    						totalDays++;
    						totalConsumption+=(consumption2-consumption1);
    					}
    					else if( month1 == 2){
    						//cout << day1<<"/"<<month1<<"/"<<year1 << endl;
    						//cout << day2<<"/"<<month2<<"/"<<year2 << endl;
    						//cout<<"Buscando en febrero ";
    						if((!(year1%4) && year1%100) || !year1%400){
    							//cout << "bisiesto" << endl;
    							if(day1==29){
    								totalDays++;
    								totalConsumption+=(consumption2-consumption1);
    							}
    						}
    						else{
      							//cout << "no bisiesto" << endl;
								if (day1 == 28){
    								//cout << "28 de febrero en año no bisiesto" << endl;
    								totalDays++;
    								totalConsumption+=(consumption2-consumption1);
    							}
    						}
    					}
    				}
    			}
    		}
    		else if(year2 == year1+1)
    			if(month2 == 1 && month1 == 12)
    				if(day2 == 1 && day1 == 31){
    					totalDays++;
    					totalConsumption+=(consumption2-consumption1);
    				}
    		day1 = day2;
    		month1 = month2;
    		year1 = year2;
    		consumption1 = consumption2;
    	}
    	cout << totalDays << " " << totalConsumption << endl;
    }
    return 0;
}