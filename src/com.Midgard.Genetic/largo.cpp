/*
 * largo.cpp
 *
 *  Created on: May 01, 2015
 *      Author: Mauricio
 */
#include "largo.cpp"

int largo::tamano(uint16_t numero){
	int n=0;
	for(int i=0;i<=16;i++){
		if (numero>2**n){
			n=n+1;
			break;
		}
	}
	return n;
}