#include <malloc.h>
#include <time.h>
#include "figure.h"
#include <assert.h>
 
char* el_figure(figure* fig,int x,int y)
{
	return fig->data+y*fig->x+x;
}

figure* figure_create(int x,int y)
{
	figure * one;
	one = (figure*) malloc(sizeof(int)*4+sizeof(char)*x*y);
	one->x=x;
	one->y=y;
	one->x_c=0;
	one->y_c=0;
	return one;
}

void figure_delete(figure* one)
{
	free(one);
}

figure* figure_copy(figure* one)
{
	int i;
	figure * temp;
	temp = figure_create(one->x,one->y);
	temp->x_c=one->x_c;
	temp->y_c=one->y_c;
	for(i=0;i<one->x*one->y;i++)
	{
		*(temp->data+i)=*(one->data+i);
	}
	return temp;
}


figure** create_all_figure()
{
	FILE* fi;
	fi = fopen("figures.dat","rt");
	assert(fi!=0);
	figure* temp;
	srand(time(NULL));
	int size;
	int x,y;
	int i,j;
	fscanf(fi,"%d",&size);
	figure** list;
	list=(figure**) malloc(sizeof(figure*)*size);;
	for(i=0;i<size;i++)
	{
		fscanf(fi,"%d %d",&x,&y);
		temp=figure_create(x,y);
		fgetc(fi);
		*(list+i)=temp;
		for(j=0;j<x*y;j++)
		{
			fscanf(fi,"%c",temp->data+j);
	
		}
	}
	fclose(fi);
	return list;
}

figure* figure_random(figure** list,int n)
{
	int c;
	figure* temp;
	srand(time(NULL));
	c =rand() % n;
	temp=figure_copy(*(list+c));
	return temp;
}

figure* figure_num(figure** list,int k)
{
	figure* temp;
	temp=figure_copy(*(list+k));
	return temp;
}

figure* figure_set(figure* fig,int x,int y)
{
	fig->x_c=x;
	fig->y_c=y;
	return fig;
}

