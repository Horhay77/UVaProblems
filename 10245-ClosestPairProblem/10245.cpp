/* 
 * Author: JORGE HERNANDEZ DE BENITO
 *
 */

#include <iostream>
#include <sstream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

//Variables globales


//Procedimientos
bool cmp(pair<double,double> a, pair<double,double> b){
	if(a.first < b.first) return true;
	return false;
}
int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    ios_base::sync_with_stdio(false);
    int points;
    double x,y, x2,y2;
    cout << fixed << setprecision(4);
    while(cin >> points){
    	if (points == 0) break;
    	vector < pair <double, double > > pointSet;
    	for(int i = 0; i < points ; i++){
    		cin >> x >> y;
    		pointSet.push_back(make_pair(x,y));
    	}
    	sort(pointSet.begin(), pointSet.end(), cmp);
    	double closest = 10000;    	
    	for(int i = 0; i < pointSet.size();i++){
    		x = pointSet[i].first;
    		y = pointSet[i].second;
    		for(int j = i+1; j < pointSet.size(); j++){
    			x2 = pointSet[j].first;
    			if(x2-x > 10000)
    				break;
    			y2 = pointSet[j].second;
    			double distance = sqrt( (x-x2)*(x-x2) + (y-y2)*(y-y2));
    			/*cout << "Comparing "<< x << ", " << y << " with "<< x2 << ", "<< y2 << endl;
    			cout << "Distance: " << distance << endl;*/
    			if (distance < closest)
    				closest = distance;
    		}
    	}
    	if (closest < 10000) cout << closest << endl;
    	else cout << "INFINITY" << endl;
    }
    return 0;
}