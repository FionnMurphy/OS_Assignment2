//#include <stdio.h>
#include "lib.h"
#include "pictures.h"

//top right is 0,0
int get_bit(unsigned int row, int col){
    return (row >> (31-col) & 0x01);
}

//top left is 0,0
void invert_bit(unsigned int *brd, int row, int col){
    brd[row] = brd[row] ^ (0x1 << (31-col));
}

void set_bit(unsigned int *brd, int row, int col, int value){
    if(value ==1){
        brd[row] = brd[row] | (0x1 << (31-col));
    }else{
        brd[row] = brd[row] & ~(0x1 << (31-col));
    }
}
/*void printRow(int row, int board[32]){
    for (int j = 0; j < 32; ++j) {
        //printf("%d",get_bit(board[row], j));
        printf("%c",get_bit(board[row], j)==1?'X':'.');
    }
    printf("\n");
}

void printBoard(int board[32]){
    for (int i = 0; i < 32; ++i) {
        printRow(i, board);
    }
}*/

int main() {

    volatile int *buttonUp = (volatile int *) 0xffff1000;
    volatile int *buttonDown = (volatile int *) 0xffff1020;
    volatile int *buttonPlace = (volatile int *) 0xffff1040;
    volatile int *buttonStart = (volatile int *) 0xffff1060;
    unsigned int *brd = (unsigned int *)0xffff8000;

    int *row = (int *) 0xffff1080;
    int *row = (int *) 0xffff1080;
    int *row = (int *) 0xffff1080;

    printstr("Shown board\n");

    int yOffset = 0;

    *buttonUp = 0;
    *buttonDown = 0;
    *buttonPlace = 0;
    *buttonStart = 0;
    int placedValue = 0;

    while(*buttonStart == 0){
        invert_bit(brd, yOffset, 31);
        if(*buttonDown == 1){
            if(yOffset<31){
                //set bit we leave
                set_bit(brd, yOffset, 31, placedValue);
                //get value were moving to
                //store in placed value
                yOffset++;
                placedValue = get_bit(brd[yOffset], 31);
            }
            printstr("Going down...\n");
            *buttonDown = 0;
        }
        if(*buttonUp == 1){
            if(yOffset>0){
                //set bit we leave
                set_bit(brd, yOffset, 31, placedValue);
                //get value were moving to
                //store in placed value
                yOffset--;
                placedValue = get_bit(brd[yOffset], 31);
            }
            printstr("Going up...\n");
            *buttonUp = 0;
        }
        if(*buttonPlace == 1){
            placedValue = 1^placedValue;
            printstr("Placing...\n");
        }
        //showpic(board);
    }
    set_bit(brd, yOffset, 31, placedValue);
    printstr("Starting...\n");
    int ur, lr;
    //i = column
    for(int col = 30; col>=0; col--){
        //j = row
        for(int row = 0; row<32; row++){
            //check upper right bit
            if(row==0){
                ur = 1;
            }else{
                ur = get_bit(brd[row-1], col+1);
            }
            //check lower right bit
            if(row==31){
                lr = 1;
            }else{
                lr = get_bit(brd[row+1], col+1);
            }
            //this = ur xor lr
            set_bit(brd, row, col, ur^lr);
        }
    }
    //printBoard(board);
    //showpic(board);
}
