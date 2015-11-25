/* 
 * File:   brainfuck.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int brainfuck(int argc, char** argv) {
    /*Solucion al problema 11956- Brainfuck*/
    unsigned char array[100];
    unsigned char pointer = 15;// -1 = 99
    string operations;
    int caso = 1;
    int numTotalCasos;
    int i;
    cin >> numTotalCasos;
    getline(cin,operations);
    while(caso <= numTotalCasos){
       for (i = 0; i< 100 ; i++) array[i]=0; //vaciamos el array
       pointer = 0; //apuntamos al primer byte
       getline(cin,operations); // leemo el conjunto de operaciones
       for(i = 0; i < operations.size();i++){
           switch(operations.at(i)){
               case '>': pointer++; pointer%=100;break;
               case '<': pointer--; if(pointer == 255) pointer = 99; break;
               case '+': array[pointer]++; break; 
               case '-': array[pointer]--; break;
               case '.':  break;
           }
       }
       cout << "Case " << caso << ":";
       for(i = 0; i < 100; i++){
           char i1 = (array[i]/16<10) ? array[i]/16 + 48 : array[i]/16 + 55;
           char i2 = (array[i]%16<10) ? array[i]%16 + 48 : array[i]%16 + 55;
           cout << ' '<< i1 << i2;
       }
       cout<<endl;
       caso++;
    }
    return 0;
}
