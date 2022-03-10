#ifndef _PLAYER_H
#define _PLAYER_H

#include "Board.h"
#include "Referee.h"


//class Board;

//class Referee;

class Player :public Board ,public Referee{

 private:

  Referee referee;

  Board board;
  

 public:

  //char name[10];
  //char color[10];

  int number;

 public:

  Player(){}

 private:

  //void setName(char name){ this->name = name; }
  //char getName(){ return name; }

  //void setColor(char color){ this->color = color; }
  //char setColor(){ return color; }

  void setNumber(int number){ this->number = number; }
  int getNumber(){return number; }
  
  int input(int Number);

  int initPlace();

  int flipOver(int square[][10]);

 public:

  void run();

};

#endif
