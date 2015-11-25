/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    long a,b;
    while(cin >> a >> b) {
        if(a > b)
            cout <<  a -b<<endl;
        else
            cout <<  b - a <<endl;
    }
    return 0;
}