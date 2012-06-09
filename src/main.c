#include <ncurses.h> //подключаем библиотеку ncurses
#include "move.h"
#include "game.h"
#include "view.h"
#include "menu.h"
#include "mode.h"


int main(int argc,char *argv[])
{
	char ch;
	initscr();

	noecho();
	while (1)
	{
		int exit = 0;
		clear();
		menu_start();
		ch=getch();
		switch(ch)
		{
			case 'h' : 
				do 
				{
					clear();
					menu_help();
					ch=getch();

				} while (ch!='e');
				break;
			case 'e': 
				exit = 1;
				break;
			case 's' : 
				do 
				{
					clear();
					menu_scores();
					printw("\n\nPress 'e' if you want to return in menu");
					refresh();
					ch=getch();
				} while (ch!='e');
				break;
			case 'n' : 
				one_player();
				halfdelay(3);
				noecho();
				refresh();		

				clear();
				menu_scores();
				//printw("\n\nMENU-'m'\nEXIT-'e'\n");
				getch();
				break;
		}
		if (exit)
			break;
	}

	clear();
	endwin(); 
	return 0;
}
