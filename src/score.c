#include "score.h"
#include <assert.h>
#include <stdio.h>
#include <malloc.h>


char* get_result_name(void)
{
	int i,j;
	char c;
	char* name;
	name=(char*) malloc(sizeof(char)*100);
	
	FILE * file;
	
	file=fopen("scores.dat","r");
	assert(file!=0);
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			name[i*10+j]=fgetc(file);
			
		}	
		
		do 
		{
			c=fgetc(file);
		} while (c!='\n');
	}
	fclose(file);
	return name;
}

int* get_result(void)
{
	int i,j;
	int c;
	int* score;
	score=(int*) malloc(sizeof(int)*10);

	FILE* file;
	file=fopen("scores.dat","r");
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			fgetc(file);
		}	
		fscanf(file,"%d",&c);
		score[i]=c;
	}
	
	return score;
}

int take_result(int score,char* name,char* names,int* scores)
{
	int i,j,value;
	for(i=0;i<10;i++)
	{
		if (score>=scores[i])
		{
			value=i;
			break;
		}
	}
	for(i=9;i>=value;i--)
	{
		scores[i]=scores[i-1];
		for(j=0;j<10;j++)
		{
			names[i*10+j]=names[(i-1)*10+j];
		}	
	}
	for(i=0;i<10;i++)
	{
		names[value*10+i]=name[i];
	}
	scores[value]=score;
	write_result(names,scores);	
	return 0;
}

void write_result(char* names,int* scores)
{
	int i,j;
	
	FILE * file;
	file=fopen("scores.dat","w");
	assert(file!=0);
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			fprintf(file,"%c",names[i*10+j]);
		}	
		fprintf(file,"%d\n",scores[i]);
	}
	fclose(file);
}

