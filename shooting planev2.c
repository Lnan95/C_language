#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


// ��˼�����ʱ���ˣ���ҿ��Ժ�����յ�ȥ�Ľ�����ɻ���Ϸ��������ʾ���ӵ�
// �ɻ�ͼ�Ρ���̨�л����ɻ���ײ�����³��֡���������ӵ����ɻ�Ѫ����������
// ��¼���桢��Ϸ��ͣ�ȵ�......

// ���ӵ���Ϊ���� һ������ܶ��


// ȫ�ֱ���
int position_x,position_y; // �ɻ�λ��
int bullet_x,bullet_y; // �ӵ�λ��
int enemy_x,enemy_y; // �л�λ��
int high,width; //  ��Ϸ����ߴ�
int score; // �÷�
int lifes;
int apple=1; // control the end
int banana=1;// counter

void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy(int x,int y)//��������������������ƶ���ԭ��λ�ý����ػ�
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

void startup() // ���ݳ�ʼ��
{
	high = 20;
	width = 30;
	position_x = high/2;
	position_y = width/2;
	bullet_x = -2;
	bullet_y = position_y;
	enemy_x = 0;
	enemy_y = position_y;
	score = 0;
	lifes = 3;
}

void show()  // ��ʾ����
{
	gotoxy(0,0);  // ����ƶ���ԭ��λ�ý����ػ�����
	int i,j;
	for (i=0;i<high;i++)
	{
		for (j=0;j<width;j++)
		{
			if ((i==position_x) && (j==position_y))
				printf("A");  //   ����ɻ�*
			else if ((i==enemy_x) && (j==enemy_y))
				printf("V");  //   ����л�@
			else if ((i==bullet_x) && (j==bullet_y))
				printf("|");  //   ����ӵ�|
			else
				printf(" ");  //   ����ո�
		}
		printf("\n");
	}
	printf("�÷֣�%d\n",score);
	printf("������%d\n",lifes);
}

void updateWithoutInput()  // ���û������޹صĸ���
{
    int input;
	if (bullet_x>-1)
		bullet_x--;


	if ((bullet_x==enemy_x) && (bullet_y==enemy_y))  // �ӵ����ел�
	{
		score++;                // ������1
		enemy_x = -1;           // �����µķɻ�
		enemy_y = rand()%width;
		bullet_x = -2;          // �ӵ���Ч
	}
	if (enemy_x>high)   // �л��ܳ���ʾ��Ļ
	{
		enemy_x = -1;           // �����µķɻ�
		enemy_y = rand()%width;
	}
    if ((position_x==enemy_x) && (position_y==enemy_y))   // �л��ܳ���ʾ��Ļ
	{
        system("cls");
        printf("\n\n\n\n\n\n\n\n                  aha!you are destroyed!!!!!\n\n                   input <enter> continue\n                    input <esc> exit\n\n\n\n\n\n\n ");
	    startup();
	    lifes = lifes-banana;
	    banana++;
	    if(lifes == -1)
        {
            system("cls");
            printf("\n\n\n\n\n\n\n\n                  Hey dude!no life!!!\n                    try again!!!!!\n\n\n\n\n\n\n\n\n ");
            apple = 0;
        }
	    while(1)
        {
            if(kbhit())
            {
                input = getch();
                if (input == 27)
                {
                    apple = 0;
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n                  welcome to try next time!!!!!\n\n\n\n\n\n\n\n\n\n ");
                    break;
                }
                else
                {
                    system("cls");
                    break;
                }

            }
        }

	}

	// �������Ƶл������ƶ����ٶȡ�ÿ������ѭ�������ƶ�һ�εл�
	// �����޸ĵĻ����û����������ٶȻ��Ǳ��ֺܿ죬������NPC���ƶ���ʾ���Խ���
	static int speed = 0;
	if (speed<20)
		speed++;
	if (speed == 20)
	{
		enemy_x++;
		speed = 0;
	}
}

void updateWithInput()  // ���û������йصĸ���
{
	char input;
	if(kbhit())  // �ж��Ƿ�������
	{
		input = getch();  // �����û��Ĳ�ͬ�������ƶ�����������س�
		if (input == 'a')
            if (position_y>1)
                position_y--;  // λ������
		if (input == 'd')
            if (position_y<20)
                position_y++;  // λ������
		if (input == 'w')
            if (position_x>1)
                position_x--;  // λ������
		if (input == 's')
            if (position_x<19)
                position_x++;  // λ������
		if (input == ' ')  // �����ӵ�
		{
			bullet_x = position_x-1;  // �����ӵ��ĳ�ʼλ���ڷɻ������Ϸ�
			bullet_y = position_y;
		}

	}
	if(score == 15)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n                  aha!nice shooter!!!!!\n\n\n\n\n\n\n\n\n\n ");
        apple = 0;
    }

}

void main()
{
	startup();  // ���ݳ�ʼ��
	while (apple) //  ��Ϸѭ��ִ��
	{
		show();  // ��ʾ����
		HideCursor(); // ���ع��
		updateWithoutInput();  // ���û������޹صĸ���
		updateWithInput();  // ���û������йصĸ���
	}
}
