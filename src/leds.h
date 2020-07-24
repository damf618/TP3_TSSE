#include"stdbool.h"

/**
 *  Inicializacion de la biblioteca y apagado de los leds del puerto.
 *  La biblioteca funciona mediante la asociacion de un bloque de memoria de
 *  16 bit al estado de 16 GPIO correspondientes.

	@param puntero a direccion del puerto a 16 bit asociado a las GPIO
	@note Debe ser la primera funcion a utilizar.
	@see LedsTurnOn,LedsTurnOff .

**/
void LedsCreate(int * direccion);

/**
 *  Funcion para el encendido de un led. Recibe un numero entero el led que
 *  se desea encender. Retorna un '1' si el numero de led a encender es valido.

	@param led numero entero, indicador del led a enceder.
	@note Debe ser utilizada posterior a LedsCreate.
	@see LedsCreate.

**/
bool LedsTurnOn(int led);

/**
 *  Funcion para el apagado de un led. Recibe un numero entero el led que
 *  se desea apagar. Retorna un '1' si el numero de led a apagar es valido.

	@param led numero entero, indicador del led a apagar.
	@note Debe ser utilizada posterior a LedsCreate.
	@see LedsCreate.

**/
bool LedsTurnOff(int led);

/**
 *  Funcion para verificar el estado de un led. Recibe un numero entero el led que
 *  se desea verificar, retorna un '1' si el led se encuentra encendido.

	@param led numero entero, indicador del led a verificar.


**/
bool LedState(int led);

/**
 *  Funcion para el apagado de todos los leds del puerto.

	@see LedsCreate.

**/
void LedsTurnAllOff(void);

/**
 *  Funcion para el encendido de todos los leds del puerto.

	@see LedsCreate.

**/
void LedsTurnAllOn(void);
