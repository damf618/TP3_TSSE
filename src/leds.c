/*
 * leds.c
 *
 *  Created on: Jul 15, 2020
 *      Author: daniel
 */
#include "leds.h"
#include"stdint.h"
#include"stdbool.h"

//NO TENER CODIGO REPETIDO
// 3 soluciones,
/* funciones
 *
*/

#define LEDS_ALL_OFF 0x0000
#define LEDS_ALL_ON 0xFFFF
#define LEDS_TO_BITS_OFFSET 1
#define LEDS_BIT_ON 1

static int * puerto;

//2 funciones
//uint8_t
int LedToBit(int led){
	return led-LEDS_TO_BITS_OFFSET;
}

//uint16_t  arg uint8_t
int BitMask(int bit){
	return (LEDS_BIT_ON<<bit);
}

void LedsCreate(int * direccion){
	puerto=direccion;
	*puerto =LEDS_ALL_OFF;
}

bool Address_Check(int led){
	bool retorno=FALSE;
	if((FIRST_GPIO<=led)&&(LAST_GPIO>=led)){
		retorno=TRUE;	
	}
	return retorno;
}

int Assign_Port(int led){
	int retorno;	
	retorno=BitMask(LedToBit(led));	
	return retorno;
}

bool LedsTurnOn(int led){
	bool retorno=FALSE;
	if(Address_Check(led)){
		*puerto |=Assign_Port(led);
		retorno=TRUE;
	}
	return retorno;
}

bool LedsTurnOff(int led){
	bool retorno=FALSE;
	if(Address_Check(led)){
		*puerto &=~Assign_Port(led);
		retorno=TRUE;
	}
	return retorno;
}

void LedsTurnAllOff(void){
	*puerto =LEDS_ALL_OFF;
}

void LedsTurnAllOn(void){
	*puerto =LEDS_ALL_ON;
}

bool LedState(int led){
	uint32_t val;
	bool retorno;

	val=*puerto&Assign_Port(led);
	retorno= val;

	return retorno;
}



