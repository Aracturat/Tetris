#include "view.h"
#include <ncurses.h>
#include <malloc.h>


void view_field(field* one)
{
	int i,j;
	char c;
	for(i=0;i<one->y;i++)
	{
		for(j=0;j<one->x;j++)
		{
			move(i+one->y_c,j+one->x_c);
			c=*el_field(one,j,i);
			if (c=='X') printw("%c",c);
		}
	}
}
void view_line_down(int x,int y0,int y)
{
	int i;
	for(i=y0;i<=y;i++)
	{
		move(i,x);
		printw("#");
	}
	refresh();
}

void view_line_right(int y,int x0,int x)
{
	int i;
	for(i=x0;i<=x;i++)
	{
		move(y,i);
		printw("#");
	}
	refresh();
}

void view_border_area(int x0,int y0,int x,int y)
{
	view_line_right(y0,x0,x);
	view_line_right(y,x0,x);
	view_line_down(x0,y0,y);
	view_line_down(x,y0,y);
}

void view_figure(figure* fig)
{
	int i,j;

	for(i=0;i<fig->y;i++)
	{
		for(j=0;j<fig->x;j++)
		{
			move(fig->y_c+i,fig->x_c+j);
			printw("%c",*(el_figure(fig,j,i)));
		}
	}
	refresh();
}

void view_next(figure* fig,int x,int y)
{
	int temp_x=fig->x_c;
	int temp_y=fig->y_c;
	fig->x_c=x;
	fig->y_c=y;
	move(y-2,x-1);
	printw("Next:");
	view_figure(fig);
	fig->x_c=temp_x;
	fig->y_c=temp_y;
}

void view_score(int score,int x,int y)
{
	move(y,x-1);
	printw("Score:");
	move(y+1,x);
	printw("%d",score);
	refresh();
}
