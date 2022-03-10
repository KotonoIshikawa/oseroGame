#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Player.h"
#include "Board.h"
#include "Referee.h"



void Player::run(){

  int i=2;
  int passco1=0,passco2=0,phg1=0,phg2=0;
  
  

  initPlace();

    
  
   

  while(1){
    if(i%2 == 0){
      //setName(Player1);
      setNumber(1);
    }else{
      //setName(Player2);
      setNumber(2);
    }
    if((phg1==1)&&(getNumber()==2)){
      setNumber(1);
      phg1=0;
    }else if((phg2==1)&&(getNumber()==1)){
      setNumber(2);
      phg2=0;
    }

    /*if(getNumber() == 1){
      setColor(black);
    }else if(getNumber() == 2){
      setColor(white);
    }*/
    
    board.showBoard(square);

    input(getNumber());

    flipOver(square);

   

   
    
    //board.showBoard(square);

    if(referee.pass(square,getNumber()) == 1){
      if(getNumber()==1){
        passco1++;
        if(referee.con(square) == 1){
          break;
        }
        printf("player2,パス%d回\n",passco1);
        if(passco1 == 3){
          break;
        }
        phg1=1;
      }else if(getNumber()==2){
        passco2++;
        if(referee.con(square) == 1){
          break;
        }
        

        printf("player1,パス%d回\n",passco2);
        if(passco2 == 3){
          break;
        }
        phg2=1;
      }

    }

    

    i++;
  }
  board.showBoard(square);

  if(passco1==3){
    printf("パス３回使ったのでplayer2の負け\n");
  }else if(passco2 == 3){
    printf("パス３回使ったのでplayer1の負け\n");
  }
  else if(referee.winner(square) == 1){
    printf("Player1の勝ち\n");
  }else if(referee.winner(square) == 0){
    printf("Player2の勝ち\n");
  }else{
    printf("ドロー\n");
  }
  
}

int Player::flipOver(int square[][10]){

  int count=0,y,t,d,e,i,j,Number,atNumber,ch;

  Number = getNumber();
  if(Number == 1){
    atNumber = 2;
  }else{
    atNumber = 1;
  }

  y=board.getYoko();
  t=board.getTate();

  //上方向
  if(square[y][t-1] == atNumber){
    
  

    for(d=1;d<=8;d++){
      if(square[y][t-d] == Number){
        ch = 1;
      }else if (square[y][t-d] == atNumber){
        ch = 2;
      }else if(square[y][t-d] == 0){
        ch = 0;
      } else {
        ch = -1;
      }
      switch(ch){
        case 1:
           for(e = 1; e <= count; e++){
             board.setSquare(y,t-e,Number,square);
           }
           break;
        case 2:
           count++;
           break;
        case 0:
           goto loopend1;
        case -1:
           goto loopend1;
      }
    }
   
  }
  loopend1:
  count=0;
  //右上方向
  if(square[y+1][t-1] == atNumber){
    for(d=1;d<=8;d++){
      if(square[y+d][t-d] == Number){
        ch = 1;
      }else if (square[y+d][t-d] == atNumber){
        ch = 2;
      }else if(square[y+d][t-d] == 0){
        ch = 0;
      } else {
        ch = -1;
      }
      switch(ch){
        case 1:
           for(e = 1; e <= count; e++){
             board.setSquare(y+e,t-e,Number,square);
           }
           break;
        case 2:
           count++;
           break;
        case 0:
           goto loopend2;
        case -1:
           goto loopend2;
      }
    }
    
  }
  loopend2:
  count=0;
  //右方向
  if(square[y+1][t] == atNumber){
    for(d=1;d<=8;d++){
      if(square[y+d][t] == Number){
        ch = 1;
      }else if (square[y+d][t] == atNumber){
        ch = 2;
      }else if(square[y+d][t] == 0){
        ch = 0;
      } else {
        ch = -1;
      }
      switch(ch){
        case 1:
           for(e = 1; e <= count; e++){
             board.setSquare(y+e,t,Number,square);
           }
           break;
        case 2:
           count++;
           break;
        case 0:
           goto loopend3;
        case -1:
           goto loopend3;
      }
    }
    
  }
  loopend3:
  count=0;
  //右下方向
  if(square[y+1][t+1] == atNumber){
    for(d=1;d<=8;d++){
      if(square[y+d][t+d] == Number){
        ch = 1;
      }else if (square[y+d][t+d] == atNumber){
        ch = 2;
      }else if(square[y+d][t+d] == 0){
        ch = 0;
      } else {
        ch = -1;
      }
      switch(ch){
        case 1:
           for(e = 1; e <= count; e++){
             board.setSquare(y+e,t+e,Number,square);
           }
           break;
        case 2:
           count++;
           break;
        case 0:
           goto loopend4;
        case -1:
           goto loopend4;
      }
    }
    
  }
  loopend4:
  count=0;
  //下
  if(square[y][t+1] == atNumber){
    for(d=1;d<=8;d++){
      if(square[y][t+d] == Number){
        ch = 1;
      }else if (square[y][t+d] == atNumber){
        ch = 2;
      }else if(square[y][t+d] == 0){
        ch = 0;
      } else {
        ch = -1;
      }
      switch(ch){
        case 1:
           for(e = 1; e <= count; e++){
             board.setSquare(y,t+e,Number,square);
           }
           break;
        case 2:
           count++;
           break;
        case 0:
           goto loopend5;
        case -1:
           goto loopend5;
      }
    }
    
  }
  loopend5:
  count=0;
  //左下
  if(square[y-1][t+1] == atNumber){
    for(d=1;d<=8;d++){
      if(square[y-d][t+d] == Number){
        ch = 1;
      }else if (square[y-d][t+d] == atNumber){
        ch = 2;
      }else if(square[y-d][t+d] == 0){
        ch = 0;
      } else {
        ch = -1;
      }
      switch(ch){
        case 1:
           for(e = 1; e <= count; e++){
             board.setSquare(y-e,t+e,Number,square);
           }
           break;
        case 2:
           count++;
           break;
        case 0:
           goto loopend6;
        case -1:
           goto loopend6;
      }
    }
    
  }
  loopend6:
  count=0;
  //左
  if(square[y-1][t] == atNumber){
    for(d=1;d<=8;d++){
      if(square[y-d][t] == Number){
        ch = 1;
      }else if (square[y-d][t] == atNumber){
        ch = 2;
      }else if(square[y-d][t] == 0){
        ch = 0;
      } else {
        ch = -1;
      }
      switch(ch){
        case 1:
           for(e = 1; e <= count; e++){
             board.setSquare(y-e,t,Number,square);
           }
           break;
        case 2:
           count++;
           break;
        case 0:
           goto loopend7;
        case -1:
           goto loopend7;
      }
    }
    
  }
  loopend7:
  count=0;
  //左上
  if(square[y-1][t-1] == atNumber){
    for(d=1;d<=8;d++){
      if(square[y-d][t-d] == Number){
        ch = 1;
      }else if (square[y-d][t-d] == atNumber){
        ch = 2;
      }else if(square[y-d][t-d] == 0){
        ch = 0;
      } else {
        ch = -1;
      }
      switch(ch){
        case 1:
           for(e = 1; e <= count; e++){
             board.setSquare(y-e,t-e,Number,square);
           }
           break;
        case 2:
           count++;
           break;
        case 0:
           goto loopend8;
        case -1:
           goto loopend8;
      }
    }
    
  }
  loopend8:
  count=0;

  
  

  
}

int Player::initPlace(){ 
  int i,j;

   for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            board.setSquare(i,j,-1,square);
            

        }
    }
    for (i = 1; i <= 8; i++) {
        for (j = 1; j <= 8; j++) {
            board.setSquare(i,j,0,square);
          
        }
    }

  board.setSquare(4,4,1,square);
  board.setSquare(5,5,1,square);
  board.setSquare(4,5,2,square);
  board.setSquare(5,4,2,square);
}

int Player::input(int Number){
  int y=0,t,n=0,e;
  char buf[256],k[1],s[1];//,ys[8]={'a','b','c','d','e','f','g','h'};
  
  /*enum yok{
    a,
    b,
    c,
    d,
    e,
    f,
    g,
    h,

  };*/

  //enum yok yo;
  //yo=0;
  if(Number == 1){
    printf("●のターンです\n");

  }else if(Number == 2){
    printf("○のターンです\n");
  }
  while(1){
    

    printf("何行目に置きますか(abc)？\n");
    printf("-->");
    while(1){
      rewind(stdin);
      scanf("%s",&k);
      if((k[0]=='a')||(k[0]=='b')||(k[0]=='c')||(k[0]=='d')||(k[0]=='e')||(k[0]=='f')||(k[0]=='g')||(k[0]=='h')){
        s[0]=k[0];
        break;
      }else{
        printf("a,b,c,d,e,f,g,hのいずれかを入力してください\n");
        printf("-->");
      }
    }
    //printf("\n%c",s[0]);
    if(s[0]=='a'){
      y=1;
    }else if (s[0]=='b'){
      y=2;
    }else if (s[0]=='c'){
      y=3;
    }else if (s[0]=='d'){
      y=4;
    }else if (s[0]=='e'){
      y=5;
    }else if (s[0]=='f'){
      y=6;
    }else if (s[0]=='g'){
      y=7;
    }else if (s[0]=='h'){
      y=8;
    }
    //printf("\n%d",y);
    /*switch(yo){
      case a:
        y=1;
      case b:
        y=2;
      case c:
        y=3;
      case d:
        y=4;
      case e:
        y=5;
      case f:
        y=6;
      case g:
        y=7;
      case h:
        y=8;
      
    }*/
    printf("何列目に置きますか(123)？\n");
    printf("-->");
    scanf("%d",&t);

      
    



    if(square[y][t] == 1 || square[y][t] == 2){
      printf("ここには置けません\n");
    }else{
      board.setYoko(y);
      board.setTate(t);
      board.setSquare(y,t,Number,square);
      break;
    }
  }

  
}
