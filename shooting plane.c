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

	int ny = 5; // һ�����ӣ����ڵ�һ�У�ny����
	int isKilled = 0;

	while (1)
	{
		system("cls");   // ��������

		//
		if (!isKilled)  // �������
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
		if (isFire==0) // ����ɻ�����Ŀ���
		{
			for(i=0;i<x;i++)
				printf("\n");
		}
		else   // ����ɻ�����ļ�������
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
				scores = scores + 100; // ���а���
            }
			isFire = 0;
		}

		// �������һ�����ӵķɻ�ͼ��
		for (j=0;j<y;j++)
			printf(" ");
		printf("  *\n");
		for (j=0;j<y;j++)
			printf(" ");
		printf("*****\n");
		for (j=0;j<y;j++)
			printf(" ");
		printf(" * * \n");

		if(kbhit())  // �ж��Ƿ�������
		{
			input = getch();  // �����û��Ĳ�ͬ�������ƶ�����������س�
			if (input == 'a')
				y--;  // λ������
			if (input == 'd')
				y++;  // λ������
			if (input == 'w')
				x--;  // λ������
			if (input == 's')
				x++;  // λ������
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
