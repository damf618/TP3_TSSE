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

bool LedsTurnOn(int led){
	bool val=0;
	if((1<=led)&&(16>=led)){
		*puerto |=BitMask(LedToBit(led));
		val=1;
	}
	return val;
}

bool LedsTurnOff(int led){
	bool val=0;
	if((1<=led)&&(16>=led)){
		*puerto &=~BitMask(LedToBit(led));
			val=1;
		}
	return val;
}

void LedsTurnAllOff(void){
	*puerto =LEDS_ALL_OFF;
}

void LedsTurnAllOn(void){
	*puerto =LEDS_ALL_ON;
}

bool LedState(int led){
	uint32_t val;
	bool value;

	val=*puerto&BitMask(LedToBit(led));
	value= val>>(led-1);

	return value;
}



