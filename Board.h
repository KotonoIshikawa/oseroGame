#ifndef _BOARD_H_
#define _BOARD_H_
#include<iostream>
using namespace std;

class Board{
 protected:
  
  int  yoko;
  char tate;
  int stone;
  int  square[10][10];

 public:

  Board(){}

  void  showBoard(int square[][10]);
  //void  printBoard(int *square);



  void setYoko(int yoko){ this->yoko =yoko;}
  int getYoko(){ return yoko; }
  void setTate(char tate){this->tate=tate;}
  char getTate(){return tate;}
  void setSquare(int yoko,int tate,int stone,int square[][10]){square[yoko][tate]=stone;}
  //int getSquare(){return square;}

};


#endif /* _BOARD_H_ */
