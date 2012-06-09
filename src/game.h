#ifndef h_game

#define h_game

#include "figure.h"

//Описание структуры игрового поля;
typedef struct tField
	{
		int x;
		int y;
		int x_c;
		int y_c;
		char data[1];
	} field;
	

//Создать игровое поле;
field* create_field(int x,int y,int x_c,int y_c);

//Добавить фигуру на поле;
void add_on_field(figure* fig,field* one);

//Ищем полную строку;
int find_full(field* one);

//Проверяем, можно ли спуститься ниже;
int may_go_down(field* one,figure* fig);

//Проверяем, можно ли пойти влево;
int may_go_left(field* one,figure* fig);

//Проверяем, можно ли пойти вправо;
int may_go_right(field* one,figure* fig);

//Получить элемент c координатами x и y;
char* el_field(field* one,int x, int y);

//Проверяем конец игры;
int game_end(field* one);


#endif
