#include "build/temp/_test_leds.c"
#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"


int virtuales=0xFFFF;



void setUp(void){

 LedsCreate(&virtuales);

}





void test_todos_los_leds_inician_apagados(void){

 int virtuales =0xFFFF;

 LedsCreate(&virtuales);

 UnityAssertEqualNumber((UNITY_INT)((0x0000)), (UNITY_INT)((virtuales)), (

((void *)0)

), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

}





void test_encender_un_led(void){

 LedsTurnOn(1);

 UnityAssertEqualNumber((UNITY_INT)((0x0001)), (UNITY_INT)((virtuales)), (

((void *)0)

), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_INT);

}





void test_encender_un_led_y_apagar_un_led(void){

 LedsTurnOn(1);

 LedsTurnOff(1);

 UnityAssertEqualNumber((UNITY_INT)((0x0000)), (UNITY_INT)((virtuales)), (

((void *)0)

), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_INT);

}





void test_encender_y_apagar_varios_leds(void){

 LedsTurnOn(3);

 LedsTurnOn(5);

 LedsTurnOff(3);

 UnityAssertEqualNumber((UNITY_INT)((0x0010)), (UNITY_INT)((virtuales)), (

((void *)0)

), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_INT);

}





void test_Read_Leds_Port_State(){

   LedsTurnOn(8);

   LedsTurnOn(2);

   LedsTurnOn(14);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((LedState(8))), (

  ((void *)0)

  ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_HEX16);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((LedState(2))), (

  ((void *)0)

  ), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_HEX16);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((LedState(14))), (

  ((void *)0)

  ), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_HEX16);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((LedState(6))), (

  ((void *)0)

  ), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_HEX16);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((LedState(13))), (

  ((void *)0)

  ), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_HEX16);

}





void test_encender_todos_los_leds(void){

 LedsTurnAllOn();

 UnityAssertEqualNumber((UNITY_INT)((0xFFFF)), (UNITY_INT)((virtuales)), (

((void *)0)

), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_INT);

}





void test_apagar_todos_los_leds(void){

 LedsTurnAllOn();

 LedsTurnAllOff();

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((virtuales)), (

((void *)0)

), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_HEX16);

}









void test_encender_los_leds_de_los_extremos(void){

   LedsTurnOn(1);

   LedsTurnOn(16);

   UnityAssertEqualNumber((UNITY_INT)((0x8001)), (UNITY_INT)((virtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(90), UNITY_DISPLAY_STYLE_INT);

}





void test_apagar_los_leds_de_los_extremos(void){

   LedsTurnAllOn();

   LedsTurnOff(1);

   LedsTurnOff(16);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x7FFE)), (UNITY_INT)(UNITY_INT16)((virtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(98), UNITY_DISPLAY_STYLE_HEX16);

}





void test_encendido_valor_fuera_de_rango(void){

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((LedsTurnOn(17))), (

((void *)0)

), (UNITY_UINT)(103), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((LedsTurnOn(0))), (

((void *)0)

), (UNITY_UINT)(104), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x00)), (UNITY_INT)(UNITY_INT16)((virtuales)), (

((void *)0)

), (UNITY_UINT)(105), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apagado_valor_fuera_de_rango(void){

 LedsTurnAllOn();

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((LedsTurnOff(25))), (

((void *)0)

), (UNITY_UINT)(111), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((LedsTurnOff(-15))), (

((void *)0)

), (UNITY_UINT)(112), UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((virtuales)), (

((void *)0)

), (UNITY_UINT)(113), UNITY_DISPLAY_STYLE_HEX16);

}
