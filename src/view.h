#ifndef h_view

#define h_view
#include "game.h"


//Вывести на экран игровое поле;
void view_field(field* one);

//Вывести на экран фигуру;
void view_figure(figure* fig);

//Вывести на экран вертикальную линию;
void view_line_down(int x,int y0,int y);

//Вывести на экран горизонтальную линию;
void view_line_right(int y,int x0,int x);

//Вывести на экран границу области с координатами (x0,y0)-(x,y);
void view_border_area(int x0,int y0,int x,int y);

//Показать следующую фигуру;
void view_next(figure* fig,int x,int y);

//Показать счет;
void view_score(int score,int x,int y);

#endif
