#include <iostream>


#include "Referee.h"

bool Referee::con(int square[][10]){

  int i,j,n=0;

  for(i=1;i<=8;i++){
    for(j=1;j<=8;j++){
      if(square[i][j]==0){
        n=1;
        
      }
    }
  }

  if(n==0){
    return 1;//継続不可
  }else {
    return 0;//継続可
  }

  

}


int Referee::winner(int square[][10]){

  int i=1,j=1;
  int player1=0,player2=0;
  for(i=1;i<=8;i++){
    for(j=1;j<=8;j++){

      if(square[i][j] == 1){
        player1++;
      }else if(square[i][j] == 2){
	      player2++;
      }
    }
  }
  if(player1>player2){
    return 1;
  }else if(player2>player1){
    return 0;
  }else if(player1 == player2){
    return -1;
  }

}


bool Referee::pass(int square[][10],int nNumber){

   int n=0,count=0,Number,atNumber,ch,a,hg=0,ok=0,err=0;
   if(nNumber == 1){
     atNumber = 1;
     Number = 2;
   }else{
     atNumber = 2;
     Number = 1;
   }
   for(int i = 1; i <= 8; i++){
     for(int j = 1; j <= 8; j++){
       if(square[i][j]==0){
          
         for(int k = 1; k <= 8; k++){
           if(square[i][j-k] == Number){
             ch = 1;
           }else if(square[i][j-k] == atNumber){
             ch = 2;
           }else if (square[i][j-k] == 0){
             ch = 0;
           }else {
             ch = -1;
           }
            switch(ch){
              case 1://me
                n++;
                goto loopend1;
              case 2://you
                count++;
                break;
              case 0:
                goto loopend1;//kuuhaku 
              case -1:
                goto loopend1;//wakugai
              
              
            }
            



         }
         loopend1:
         if((n > 0) && (count>0) ){
           //printf("\nhaita1\n");
           //printf("n=%d,",n);
           //printf("count=%d\n",count);
           goto loopend;
         }else {
           hg++;
         }
         n=0;
         count=0;

         for(int k = 1; k <= 8; k++){
           if(square[i+k][j-k] == Number){
             ch = 1;
           }else if(square[i+k][j-k] == atNumber){
             ch = 2;
           }else if (square[i+k][j-k] == 0){
             ch = 0;
           }else {
             ch = -1;
           }
            switch(ch){
              case 1:
                n++;
                goto loopend2;
              case 2:
                count++;
                break;
              case 0:
                goto loopend2;
              case -1:
                goto loopend2;
              
              
            }
            



         }
         loopend2:
         if((n > 0) && (count>0) ){
              //printf("\nhaita2\n");
              //printf("n=%d,",n);
              //printf("count=%d\n",count);
              goto loopend;
         }else {
              hg++;
         }
         n=0;
         count=0;

         for(int k = 1; k <= 8; k++){
           if(square[i+k][j] == Number){
             ch = 1;
           }else if(square[i+k][j] == atNumber){
             ch = 2;
           }else if (square[i+k][j] == 0){
             ch = 0;
           }else {
             ch = -1;
           }
            switch(ch){
              case 1:
                n++;
                goto loopend3;
              case 2:
                count++;
                break;
              case 0:
                goto loopend3;
              case -1:
                goto loopend3;
              
              
            }
            



         }
         loopend3:
         if((n > 0) && (count>0) ){
            // printf("\nhaita3\n");
            // printf("n=%d,",n);
             //rintf("count=%d\n",count);
              goto loopend;
         }else {
              hg++;
         }
         n=0;
         count=0;

         for(int k = 1; k <= 8; k++){
           if(square[i+k][j+k] == Number){
             ch = 1;
           }else if(square[i+k][j+k] == atNumber){
             ch = 2;
           }else if (square[i+k][j+k] == 0){
             ch = 0;
           }else {
             ch = -1;
           }
            switch(ch){

              
              case 1:
                n++;
                goto loopend4;
              case 2:
                count++;
                break;
              case 0:
                goto loopend4;
              case -1:
                goto loopend4;
              
              
            }
            



         }
         loopend4:
         if((n > 0) && (count>0) ){
             // printf("\nhaita4\n");
              //printf("n=%d,",n);
              //printf("count=%d\n",count);
              goto loopend;
         }else {
              hg++;
         }
         n=0;
         count=0;

         for(int k = 1; k <= 8; k++){
           if(square[i][j+k] == Number){
             ch = 1;
           }else if(square[i][j+k] == atNumber){
             ch = 2;
           }else if (square[i][j+k] == 0){
             ch = 0;
           }else {
             ch = -1;
           }
            switch(ch){
              case 1:
                n++;
                goto loopend5;
              case 2:
                count++;
                break;
              case 0:
                goto loopend5;
              case -1:
                goto loopend5;
              
              
            }
            



         }
         loopend5:
         if((n > 0) && (count>0) ){
             // printf("\nhaita5\n");
             // printf("n=%d,",n);
             // printf("count=%d\n",count);
              goto loopend;
         }else {
              hg++;
         }
         n=0;
         count=0;


         for(int k = 1; k <= 8; k++){
           if(square[i-k][j+k] == Number){
             ch = 1;
           }else if(square[i-k][j+k] == atNumber){
             ch = 2;
           }else if (square[i-k][j+k] == 0){
             ch = 0;
           }else {
             ch = -1;
           }
            switch(ch){
              case 1:
                n++;
                goto loopend6;
              case 2:
                count++;
                break;
              case 0:
                goto loopend6;
              case -1:
                goto loopend6;
              
              
            }
            



         }
         loopend6:
         if((n > 0) && (count>0) ){
             // printf("\nhaita6\n");
             // printf("n=%d,",n);
             // printf("count=%d\n",count);
              goto loopend;
         }else {
              hg++;
         }
         n=0;
         count=0;

         for(int k = 1; k <= 8; k++){
           if(square[i-k][j] == Number){
             ch = 1;
           }else if(square[i-k][j] == atNumber){
             ch = 2;
           }else if (square[i-k][j] == 0){
             ch = 0;
           }else {
             ch = -1;
           }
            switch(ch){
              case 1:
                n++;
                goto loopend7;
              case 2:
                count++;
                break;
              case 0:
                goto loopend7;
              case -1:
                goto loopend7;
              
              
            }
            



         }
         loopend7:
         if((n > 0) && (count>0) ){
             //printf("\nhaita7\n");
              //printf("n=%d,",n);
              //printf("count=%d\n",count);
              goto loopend;
         }else {
              hg++;
         }
         n=0;
         count=0;

         for(int k = 1; k <= 8; k++){
           if(square[i-k][j-k] == Number){
             ch = 1;
           }else if(square[i-k][j-k] == atNumber){
             ch = 2;
           }else if (square[i-k][j-k] == 0){
             ch = 0;
           }else {
             ch = -1;
           }
            switch(ch){
              case 1:
                n++;
                goto loopend8;
              case 2:
                count++;
                break;
              case 0:
                goto loopend8;
              case -1: 
                goto loopend8;  
              
              
            }
            
         }
         loopend8:
         if((n > 0) && (count>0) ){
             // printf("\nhaita8\n");
             // printf("n=%d,",n);
             // printf("count=%d\n",count);
              goto loopend;
         }else {
              hg++;
         }


         n=0;
         count=0;
   
         loopend:
         if(hg==8){
          //printf("\nhg\n");
          err++;
          hg=0;
          n=0;
          count=0;
         }else{
         // printf("%d\n",hg);
         // printf("\nok\n");
          ok++;
          hg=0;
          n=0;
          count=0;
         }   
        }
        
      }













   
   }
   if(ok > 0){
     return 0;
   }else{
     return 1;
   }
   
  
}




 
