#ifndef h_figure
#define h_figure

//Описание структуры фигуры;
typedef struct tFigure
	{
		int x;
		int y;
		int x_c;
		int y_c;
		char data[1];
	} figure;

//Получить элемент фигуры с координатами x и y;
char* el_figure(figure* fig,int x,int y);

//Создать фигуру с размером x на y;
figure * figure_create(int x,int y);

//Создать лист всех фигур;
figure** create_all_figure();

//Удалить фигуру;
void figure_delete(figure* one);

//Получить случайную фигуру;
figure* figure_random(figure** list,int n);

//Получить фигуру номер k;
figure* figure_num(figure** list,int k);

//Скопировать фигуру;
figure* figure_copy(figure* one);

//Установить фигуре координаты x и y;
figure* figure_set(figure* fig,int x,int y);

#endif

