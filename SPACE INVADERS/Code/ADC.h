#include "..//tm4c123gh6pm.h"

//SLIDE POT
//PE2

void ADC_INIT(void);
unsigned long ADC0_INPUT_SET_X_POS(void);

//PLAYER SHIP IS 18 PIXELS WIDE 
//AND THE LCD IS 84 PIXELS WIDE
//SO THE PLAYER SHIP HAS AVAILABLE X-AXIS VALUE POINTS FROM 0-66 (84-18)
//AND THE ADC INPUTS ARE 0-4095
//SO WE MAKE EACH 409 ADC VALUES REPRESENT 7 PIXELS
//THE PLAYER SHIP HAS 10 POSITIONS TO MOVE ON X-AXIS



/*

ADC VALUE        PIXEL X-POSITION

 0-409                0
 410-819              7
 820-1229             14
 1230-1639            21
 1640-2049            28
 2050-2459            35
 2460-2869            42
 2870-3279            49
 3280-3689            58
 3690-4095            66
 
*/
