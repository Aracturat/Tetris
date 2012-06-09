#include "game.h"
#include <malloc.h>

char* el_field(field* one,int x, int y)
{
	return one->data+x+y*one->x;
}


field* create_field(int x,int y,int x_c,int y_c)
{
	int i;
	field* temp;
	
	temp=(field*) malloc(sizeof(char)*x*y+sizeof(int)*4);
	temp->x_c=x_c;
	temp->y_c=y_c;
	temp->x=x;
	temp->y=y;
	
	for(i=0;i<x*y;i++)
	{
		*(temp->data+i)=' ';
	}
	
	return temp;
}

void add_on_field(figure* fig,field* one)
{
	int i;
	int j;
	char c;
	
	for (i=0;i<fig->y;i++)
	{
		for(j=0;j<fig->x;j++)
		{
			c=*(el_figure(fig,j,i));
			if (c=='X')
			{
				*(el_field(one,fig->x_c-one->x_c+j,fig->y_c-one->y_c+i))=c;
			}
		}
	}
}

void del_str(field* one,int n)
{
	int i,j;
	
	for(i=0;i<one->x;i++)
	{
		*(el_field(one,i,n))=' ';
	}
	
	for(j=n;j>0;j--)
	{
		for(i=0;i<one->x;i++)
		{
			*(el_field(one,i,j))=*(el_field(one,i,j-1));
		}
	}
	
	for(i=0;i<one->x;i++)
	{
		*(el_field(one,i,0))=' ';
	}	
}

int find_full(field* one)
{
	int i,j,p,s;
	s=0;
	for(i=0;i<one->y;i++)
	{
		p=0;
		for(j=0;j<one->x;j++)
		{
			if (*(el_field(one,j,i))=='X')
			{
				p++;
			}
		}
		if (p==one->x)
		{
			s++;
			del_str(one,i);
		}
	}
	return s;
}

int may_go_down(field* one,figure* fig)
{
	int p,s,i,j;
	s=0;
	p=0;
	
	if ((fig->y_c+fig->y)<(one->y_c+one->y))
	{
		for(i=0;i<fig->x;i++)
		{
			for(j=0;j<fig->y;j++)
			{
				if (*(el_figure(fig,i,j))=='X')
				{
					p=j;
				}
			}
			if (*(el_field(one,fig->x_c-one->x_c+i,fig->y_c-one->y_c+p+1))==' ')
			{
				s++;
			}	
			
		}
		if (s==fig->x)	return 1;
		else return 0;
	}
	else return 0;
}

int may_go_right(field* one,figure* fig)
{
	int p,s,i,j;
	s=0;
	p=0;
	
	if (fig->x_c+fig->x<one->x_c+one->x)
	{
		for(i=0;i<fig->y;i++)
		{
			for(j=0;j<fig->x;j++)
			{
				if (*(el_figure(fig,j,i))=='X')
				{
					p=j;
				}
			}
			if (*(el_field(one,fig->x_c-one->x_c+p+1,fig->y_c-one->y_c+i))==' ')
			{
				s++;
			}	
			
		}
		if (s==fig->y)	return 1;
		else return 0;
	}
	else return 0;
}

int may_go_left(field* one,figure* fig)
{
	int p,s,i,j;
	s=0;
	p=0;
	if (fig->x_c>one->x_c)
	{
		for(i=0;i<fig->y;i++)
		{
			for(j=0;j<fig->x;j++)
			{
				if (*(el_figure(fig,j,i))=='X')
				{
					p=j;
					break;
				}
			}
			if (*(el_field(one,fig->x_c-one->x_c+p-1,fig->y_c-one->y_c+i))==' ')
			{
				s++;
			}	
			
		}
		if (s==fig->y)	return 1;
		else return 0;
	}
	else return 0;
}

int game_end(field* one)
{
	int i;
	for(i=0;i<one->x;i++)
	{
		if (*el_field(one,i,3)=='X')
		{
			return 1;
		}
	}
	return 0;
}
