/*
 * Example software running in Logisim RISC-V Computer System model by Pavel Gladyshev
 * licensed under Creative Commons Attribution International license 4.0
 *
 * This example shows how graphics display data can be specified using integer array initialisers and binary constants.
 */

#include "pictures.h"

// Given below is an array of two arrays, where each of the sub-arrays contains a 32x32 picture for the graphics dislay 
// that can be displayed using showpic() function.

// Please note that because of the way demo.lds is written, .data section will be placed in ROM, 
// which effectively makes all *initialised* global variables *constant*, even if they are not declared as such!

int board[32]=
{
    
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000000,     
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000000,     
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000000,     
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000000,     
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000000,     
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000000,     
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000000,     
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000000,     
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000000,     
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000000,     
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000000,
        0b00000000000000000000000000000000  
    
};