/* 
 * File:   main.cpp
 * Author: jorhern
 *
 * Created on 13 de octubre de 2015, 20:43
 */

//#include <iostream>
#include <cstdio>
#include <cmath>
#include <string.h>
using namespace std;

//Variables globales


//Procedimientos

int main(int argc, char** argv) {
    /*Solución al problema ---: -------*/
    //ios_base::sync_with_stdio(false);
    int distanciaATierra,angulo;
    int distanciaTotal;
    double pi = 2*acos(0);
    //printf("PI: %f\n",pi);
    double longitudArco,longitudCuerda;
    double anguloEnRadianes;
    double x,y;
    char tipo[4];
    int radioTierra = 6440;
    while(scanf("%d %d %s\n",&distanciaATierra,&angulo,tipo)==3){
    	distanciaTotal=radioTierra+distanciaATierra;
    	//printf("La distancia del satelite al centro de la tierra es %d\n",distanciaTotal);
    	//Calculo de la longitud del arco
    	if(strcmp(tipo,"deg")==0){
    		anguloEnRadianes=angulo*pi/180.;
    	}
    	else{
    		anguloEnRadianes=angulo*pi/10800.;
    	}
    	//printf("%d %s en radianes son %.2f\n",angulo,tipo,anguloEnRadianes);
    	if(anguloEnRadianes<=pi)
    		longitudArco=distanciaTotal*anguloEnRadianes;
    	else
    		longitudArco = distanciaTotal*(2*pi - anguloEnRadianes);
    	//Calculo de l alogintud e la cuerda:
    	//printf("El coseno de dicho angulo es: %f\n",cos(anguloEnRadianes));
    	//printf("Y el seno de dicho angulo es: %f\n",sin(anguloEnRadianes));
    	//x=distanciaTotal;
    	x= distanciaTotal*cos(anguloEnRadianes);
    	y=distanciaTotal*sin(anguloEnRadianes);
    	//printf("El segundo punto es (%.2f,%.2f)\n",x,y);
    	x-=distanciaTotal;
    	longitudCuerda = y*y+x*x;
    	longitudCuerda = sqrt(longitudCuerda);
    	//printf("Distancia: %d %.6f\n",distanciaTotal,distanciaTotal*anguloEnRadianes);
    	printf("%.6f %.6f\n",longitudArco,longitudCuerda);

    }
    return 0;
}