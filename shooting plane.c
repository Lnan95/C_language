#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	int i,j;
	int x = 5;
	int y = 10;
	char input;
	int isFire = 0;
	int scores = 0;

	int ny = 5; // 一个靶子，放在第一行，ny列上
	int isKilled = 0;

	while (1)
	{
		system("cls");   // 清屏函数

		//
		if (!isKilled)  // 输出靶子
		{
			for (j=0;j<=25;j++)
            {
                printf(" ");
                if (j==(ny-1))
                    printf("+");
            }
            printf("Score: %d",scores);
		}
		else
        {
            for (j=0;j<21;j++)
				printf("                         ");

			printf("\n");
            ny = rand()%19+1;
            isKilled = 0;
        }
		if (isFire==0) // 输出飞机上面的空行
		{
			for(i=0;i<x;i++)
				printf("\n");
		}
		else   // 输出飞机上面的激光竖线
		{
			for(i=0;i<x;i++)
			{
				for (j=0;j<y;j++)
					printf(" ");
				printf("  |\n");
			}
			if (y+2==ny)
            {
				isKilled = 1;
				scores = scores + 100; // 击中靶子
            }
			isFire = 0;
		}

		// 下面输出一个复杂的飞机图案
		for (j=0;j<y;j++)
			printf(" ");
		printf("  *\n");
		for (j=0;j<y;j++)
			printf(" ");
		printf("*****\n");
		for (j=0;j<y;j++)
			printf(" ");
		printf(" * * \n");

		if(kbhit())  // 判断是否有输入
		{
			input = getch();  // 根据用户的不同输入来移动，不必输入回车
			if (input == 'a')
				y--;  // 位置左移
			if (input == 'd')
				y++;  // 位置右移
			if (input == 'w')
				x--;  // 位置上移
			if (input == 's')
				x++;  // 位置下移
			if (input == ' ')
				isFire = 1;
		}
		if(scores == 1500)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n                  aha!nice shooter!!!!!\n\n\n\n\n\n\n\n\n\n ");
            break;
        }

	}

	return 0;
}
