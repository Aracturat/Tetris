#ifndef h_move

#define h_move
#include "figure.h"
#include "game.h"

//Повернуть фигуру;
figure* rotate(field* one,figure* fig);

//Переметить фигуру влево;
void move_figure_left(field* one,figure* fig);

//Переметить фигуру влево;
void move_figure_right(field* one,figure* fig);

//Переметить фигуру вправо;
void move_figure_down(field* one,figure* fig);

#endif
