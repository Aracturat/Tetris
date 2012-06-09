#include "move.h"

#include <malloc.h>

figure* rotate(field* one,figure* fig)
{
	figure* temp;
	int i,j;
	temp=figure_copy(fig);
	temp->x=fig->y;
	temp->y=fig->x;
	
	if ((temp->x_c+temp->x < one->x+one->x_c+1)&&(temp->y_c+temp->y < one->y+one->y_c))
	{
		for(i=0;i<fig->y;i++)
			for(j=0;j<fig->x;j++)
			{
				*(el_figure(temp,temp->x-i-1,j))=*(el_figure(fig,j,i));
				if ((*(el_figure(temp,temp->x-i-1,j))=='X') 
					&& (*(el_field(one,temp->x_c-one->x_c+temp->x-i-1,temp->y_c-one->y_c+j))=='X'))
				{
					free(temp);
					return fig;			
				}
			}
		figure_delete(fig);
		return temp;
	}
	else
	{
		free(temp);
		return fig;
	}
}

void move_figure_left(field* one,figure* fig)
{
	if (may_go_left(one,fig))
	{
		fig->x_c-=1;
	}
}

void move_figure_right(field* one,figure* fig)
{
	if (may_go_right(one,fig))
	{
		fig->x_c+=1;
	}
}

void move_figure_down(field* one,figure* fig)
{
	if (may_go_down(one,fig))
	{
		fig->y_c+=1;
	}
}
