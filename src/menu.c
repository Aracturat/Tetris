#include <ncurses.h>
#include "score.h"

void menu_start(void)
{
	printw("Tetris 0.1\n");
	printw("NEW GAME='n'\n");
	printw("HELP='h'\n");
	printw("SCORES='s'\n");
	printw("EXIT='e'\n");
	refresh();
}

void menu_help(void)
{
	printw("Press UP if you want to rotate figure.\n");
	printw("Press LEFT, DOWN, UP, if you want to move figure.\n");
	printw("Press 'e' if you want to return in menu\n");
	refresh();
}

void menu_scores(void)
{
	int i,j;
	char * name;
	int * score;
	clear();
	name=get_result_name();
	score=get_result();
	printw("Scores:");
	for (i=0;i<10;i++)
	{
		move(i+2,0);
		printw("%d)",i+1);
		move(i+2,4);
		for(j=0;j<10;j++)
		{
			printw("%c",name[i*10+j]);
		}	
		printw("  ");
		printw("%d",score[i]);
	}
	
	
	refresh();
}
