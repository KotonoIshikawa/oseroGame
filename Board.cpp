#include "Board.h"
#include <iostream>

#define B 10      


void Board::showBoard(int square[][10])
{
    int i, j;
	
    printf("   a   b   c   d   e   f   g   h \n");
    printf(" +---+---+---+---+---+---+---+---+\n");
            
    for (i = 1; i <= 8; i++) {
       printf("%d",i);
       for(j = 1; j<= 8; j++) {
           printf("|");
           if(square[j][i]==1){
               printf("● ");
           }else if(square[j][i]==2){
               printf("○ ");
           }else if(square[j][i]==0){
               printf("   ");
           }

           

           

       }
       printf("|\n");

       printf(" +---+---+---+---+---+---+---+---+\n");
    }
    
}