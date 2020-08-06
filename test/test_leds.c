/*
 **===== Casos de Prueba ---¡COMPLETADAS!---=====
 * -- Al iniciar la biblioteca todos los leds deben estar apagados.
 * -- Encender un LED.
 * -- Apagar un LED.
 * -- Encender un LED y ver que no afecte a otros LEDs.
 * -- Apagar un LED y ver que no afecte a otros LEDs.-
 * -- Encender todos los LEDs.
 * -- Apagar todos los LEDs.
 * -- Consultar estado de un LED.
 * -- Apagado de leds en borde (Parametros de borde).
 * -- Encendido de leds en borde (Parametros de borde).
 * -- Indicar error al indicar leds fuera del rango (1-16).
 * -- No tomar acciones al encender un led fuera de rango.
 * -- No tomar acciones al apagar un led fuera de rango.
 *
 **===== Casos de Prueba ---¡PENDIENTES!---=====
 *
 *
*/

#include "unity.h"
#include "leds.h"

int virtuales=0xFFFF;

void setUp(void){
	LedsCreate(&virtuales);
}

//! @test Todos empiezan apagados_
void test_todos_los_leds_inician_apagados(void){
	int virtuales =0xFFFF;
	LedsCreate(&virtuales);
	TEST_ASSERT_EQUAL(0x0000,virtuales);
}

//! @test encender un led
void test_encender_un_led(void){
	LedsTurnOn(1);
	TEST_ASSERT_EQUAL(0x0001,virtuales);
}

//! @test encender y apagar un led
void test_encender_un_led_y_apagar_un_led(void){
	LedsTurnOn(1);
	LedsTurnOff(1);
	TEST_ASSERT_EQUAL(0x0000,virtuales);
}

//! @test encender y apagar un led
void test_encender_y_apagar_varios_leds(void){
	LedsTurnOn(3);
	LedsTurnOn(5);
	LedsTurnOff(3);
	TEST_ASSERT_EQUAL(0x0010,virtuales);
}

//! @test lectura de estado de un led
void test_Read_Leds_Port_State(){
   LedsTurnOn(8);
   LedsTurnOn(2);
   LedsTurnOn(14);
   TEST_ASSERT_EQUAL_HEX16(1, LedState(8));
   TEST_ASSERT_EQUAL_HEX16(1, LedState(2));
   TEST_ASSERT_EQUAL_HEX16(1, LedState(14));
   TEST_ASSERT_EQUAL_HEX16(0, LedState(6));
   TEST_ASSERT_EQUAL_HEX16(0, LedState(13));
}

//! @test encender todos los leds
void test_encender_todos_los_leds(void){
	LedsTurnAllOn();
	TEST_ASSERT_EQUAL(0xFFFF, virtuales);
}

//! @test apagar todos los leds
void test_apagar_todos_los_leds(void){
	LedsTurnAllOn();
	LedsTurnAllOff();
	TEST_ASSERT_EQUAL_HEX16(0, virtuales);
}



//! @test prueba de encendido de leds de bordes
void test_encender_los_leds_de_los_extremos(void){
   LedsTurnOn(1);
   LedsTurnOn(16);
   TEST_ASSERT_EQUAL(0x8001, virtuales);
}

//! @test prueba de apagado de leds de bordes
void test_apagar_los_leds_de_los_extremos(void){
   LedsTurnAllOn();
   LedsTurnOff(1);
   LedsTurnOff(16);
   TEST_ASSERT_EQUAL_HEX16(0x7FFE, virtuales);
}

//! @test encendido de led, fuera del rango
void test_encendido_valor_fuera_de_rango(void){
	TEST_ASSERT_EQUAL_HEX16(0, LedsTurnOn(17));
	TEST_ASSERT_EQUAL_HEX16(0, LedsTurnOn(0));
	TEST_ASSERT_EQUAL_HEX16(0x00, virtuales);
}

//! @test apagado de led, fuera del rango
void test_apagado_valor_fuera_de_rango(void){
	LedsTurnAllOn();
	TEST_ASSERT_EQUAL_HEX16(0, LedsTurnOff(25));
	TEST_ASSERT_EQUAL_HEX16(0, LedsTurnOff(-15));
	TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtuales);
}
