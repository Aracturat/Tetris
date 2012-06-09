#include <ncurses.h>
#include <malloc.h>
#include "mode.h"
#include "move.h"
#include "game.h"
#include "view.h"
#include "menu.h"
#include "score.h"
#include <stdio.h>

void one_player()
{
	int ch;
	int max_x;
	int max_y;
	int score;
	int i,j;
	char name[10];
	score=0;
	figure** list;
	figure* view;
	figure* next;
	field* pole;

	char * names;
	int * scores;
	names=get_result_name();
	scores=get_result();

	max_x=getmaxx(stdscr);
	max_y=getmaxy(stdscr);
	noecho();

	halfdelay(3);
	keypad(stdscr, TRUE);

	pole=create_field(10,max_y-1,max_x/3,0);
	list=create_all_figure();
	view=figure_random(list,7);
	next=figure_random(list,7);
	figure_set(view,pole->x_c+pole->x/2,pole->y_c+view->y);
	clear();
	while (1)
	{
		move_figure_down(pole,view);
		if (game_end(pole)) 
		{
			goto exit;
		} 

		for (i=0;i<3;i++)
		{

			score+=100*find_full(pole); 
			view_border_area((max_x/3)-1,0,max_x/3+10,max_y-1);
			view_border_area(max_x/3+14,0,max_x/3+22,max_y-1);
			view_score(score,max_x/3+17,max_y/6+2);
			view_next(next,max_x/3+17,max_y-next->y-2);
			view_figure(view);

			view_field(pole);

			refresh();
			move(0,0);

			ch=getch();
			switch(ch)
			{
				case KEY_DOWN : 
				case 'j' : 
				case 'J' : 
					move_figure_down(pole,view);
					break;
				case KEY_LEFT : 
				case 'h' : 
				case 'H' : 
					move_figure_left(pole,view);
					break;
				case KEY_RIGHT : 
				case 'l' : 
				case 'L' : 
					move_figure_right(pole,view);
					break;
				case KEY_UP :
				case 'k' : 
				case 'K' : 
					view=rotate(pole,view);
					break;
				case 'e' :
					goto exit;
			}


			refresh();
			if (!may_go_down(pole,view))
			{
				add_on_field(view,pole);
				figure_delete(view);
				view=next;
				next=figure_random(list,7);
				figure_set(view,pole->x_c+pole->x/2,pole->y_c+1);
			}

			clear();
			move(0,0);
			printw("EXIT-'e'");

			if (score>1000) halfdelay(2);
			if (score>2000) halfdelay(1);

		}
	}

exit:
	figure_delete(view);
	clear();
	figure_delete(next);
	echo();
	nocbreak();
	printw("You are lose!\nYou score is %d.",score);
	printw("Enter your name:");
	ch=getch();
	i=0;
	do
	{
		name[i]=ch;
		i++;
		ch=getch();
	} while (ch!='\n');

	for(j=i;j<10;j++)
	{
		name[j]=' ';
	}
	name[10]='\0';

	take_result(score,name,names,scores);



}
