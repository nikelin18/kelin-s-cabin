/*#include <stdio.h>
#include <stdlib.h>
#include <getch.h>
#include <time.h>
int main()
{
	// 迷宫数组
	char maze[10][10] = {
		{'#','#','#','#','#','#','#','#','#','#'},
		{'#','@','#','#',' ',' ',' ','#',' ','#'},
		{'#',' ','#','#',' ','#',' ','#',' ','#'},
		{'#',' ','#','#',' ','#',' ','#',' ','#'},
		{'#',' ',' ','#',' ','#',' ',' ',' ','#'},
		{'#','#',' ','#',' ',' ','#',' ','#','#'},
		{'#','#',' ','#',' ','#','#',' ','#','#'},
		{'#','#',' ','#',' ','#','#',' ','#','#'},
		{'#',' ',' ',' ',' ','#','#',' ',' ',' '},
		{'#','#','#','#','#','#','#','#','#','#'}
	};

	// 记录老鼠位置的变量
	char mx = 1 , my = 1;
    int Time1=time(NULL)%1000;
	while(1)
	{
		// 清理界面
		system("clear");
		// 显示界面
		for(int x=0; x<10; x++)
		{
			for(int y=0; y<10; y++)
			{
				printf(" %c",maze[x][y]);
			}
			printf("\n");
		}
		// 检查是否到达出口
		if(8 == mx && my == 9)
		{
			int Time2=time(NULL)%1000;
			printf("alive!\nby %d s",Time2-Time1);
			return 0;
		}

		switch(getch())
		{
			case 183: 
				if(mx>0 && ' ' == maze[mx-1][my])
				{
					maze[mx--][my] = ' ';
					maze[mx][my] = '@';
				}
				break;
			case 184:
				if(mx<9 && ' ' == maze[mx+1][my])
				{
					maze[mx++][my] = ' ';
					maze[mx][my] = '@';
				}
				break;
			case 185:
				if(my<9 && ' ' == maze[mx][my+1])
				{
					maze[mx][my++] = ' ';
					maze[mx][my] = '@';
				}
				break;
			case 186:
				if(my>0 && ' ' == maze[mx][my-1])
				{
					maze[mx][my--] = ' ';
					maze[mx][my] = '@';
				}
				break;
		}
	}
}*/



#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<getch.h>

int main()
{
    char maze[10][10]={
		{'#','#','#','#','#','#','#','#','#','#'},
		{'#','@','#',' ',' ',' ',' ','#','#','#'},
		{'#',' ','#',' ','#',' ',' ',' ','#','#'},
		{'#',' ','#',' ','#','#','#',' ','#','#'},
		{'#',' ','#',' ','#',' ','#',' ','#','#'},
		{'#',' ','#',' ',' ','#','#',' ','#','#'},
		{'#',' ','#',' ','#',' ',' ',' ','#','#'},
		{'#',' ','#',' ','#',' ','#','#','#','#'},
		{'#',' ',' ',' ','#',' ',' ',' ',' ',' '},
		{'#','#','#','#','#','#','#','#','#','#'}};
	int mouse_x=1,mouse_y=1,i,j;
	time_t start_time=time(NULL);
	for(;;)
	{
		system("clear");
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				printf("%c ",maze[i][j]);
			}
			printf("\n");
		}
		if(8==mouse_x&&9==mouse_y)
		{
			printf("用时%u s\n",time(NULL)-start_time);
			return 0;
		}
		switch(getch())
		{
			case 183:
					if(0!=mouse_x&&' '==maze[mouse_x-1][mouse_y])
					{
						maze[mouse_x][mouse_y]=' ';
						maze[--mouse_x][mouse_y]='@';
					}break;
			case 184:
					if(9!=mouse_x&&' '==maze[mouse_x+1][mouse_y])
					{
						maze[mouse_x][mouse_y]=' ';
						maze[++mouse_x][mouse_y]='@';
					}break;
			case 185:
					if(9!=mouse_y&&' '==maze[mouse_x][mouse_y+1])
					{
						maze[mouse_x][mouse_y]=' ';
						maze[mouse_x][++mouse_y]='@';
					}break;
			case 186:
					if(0!=mouse_y&&' '==maze[mouse_x][mouse_y-1])
					{
						maze[mouse_x][mouse_y]=' ';
						maze[mouse_x][--mouse_y]='@';
					}break;
		}
	}
	return 0;
}
