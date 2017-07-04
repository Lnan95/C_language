#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


// 到思考题的时间了，大家可以海阔天空地去改进这个飞机游戏，比如显示复杂的
// 飞机图形、多台敌机、飞机被撞后重新出现、更好玩的子弹、飞机血量、升级、
// 登录界面、游戏暂停等等......

// 将子弹作为数组 一次能射很多个


// 全局变量
int position_x,position_y; // 飞机位置
int bullet_x,bullet_y; // 子弹位置
int enemy_x,enemy_y; // 敌机位置
int high,width; //  游戏画面尺寸
int score; // 得分
int lifes;
int apple=1; // control the end
int banana=1;// counter

void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoxy(int x,int y)//类似于清屏函数，光标移动到原点位置进行重画
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}

void startup() // 数据初始化
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

void show()  // 显示画面
{
	gotoxy(0,0);  // 光标移动到原点位置进行重画清屏
	int i,j;
	for (i=0;i<high;i++)
	{
		for (j=0;j<width;j++)
		{
			if ((i==position_x) && (j==position_y))
				printf("A");  //   输出飞机*
			else if ((i==enemy_x) && (j==enemy_y))
				printf("V");  //   输出敌机@
			else if ((i==bullet_x) && (j==bullet_y))
				printf("|");  //   输出子弹|
			else
				printf(" ");  //   输出空格
		}
		printf("\n");
	}
	printf("得分：%d\n",score);
	printf("生命：%d\n",lifes);
}

void updateWithoutInput()  // 与用户输入无关的更新
{
    int input;
	if (bullet_x>-1)
		bullet_x--;


	if ((bullet_x==enemy_x) && (bullet_y==enemy_y))  // 子弹击中敌机
	{
		score++;                // 分数加1
		enemy_x = -1;           // 产生新的飞机
		enemy_y = rand()%width;
		bullet_x = -2;          // 子弹无效
	}
	if (enemy_x>high)   // 敌机跑出显示屏幕
	{
		enemy_x = -1;           // 产生新的飞机
		enemy_y = rand()%width;
	}
    if ((position_x==enemy_x) && (position_y==enemy_y))   // 敌机跑出显示屏幕
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

	// 用来控制敌机向下移动的速度。每隔几次循环，才移动一次敌机
	// 这样修改的话，用户按键交互速度还是保持很快，但我们NPC的移动显示可以降速
	static int speed = 0;
	if (speed<20)
		speed++;
	if (speed == 20)
	{
		enemy_x++;
		speed = 0;
	}
}

void updateWithInput()  // 与用户输入有关的更新
{
	char input;
	if(kbhit())  // 判断是否有输入
	{
		input = getch();  // 根据用户的不同输入来移动，不必输入回车
		if (input == 'a')
            if (position_y>1)
                position_y--;  // 位置左移
		if (input == 'd')
            if (position_y<20)
                position_y++;  // 位置右移
		if (input == 'w')
            if (position_x>1)
                position_x--;  // 位置上移
		if (input == 's')
            if (position_x<19)
                position_x++;  // 位置下移
		if (input == ' ')  // 发射子弹
		{
			bullet_x = position_x-1;  // 发射子弹的初始位置在飞机的正上方
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
	startup();  // 数据初始化
	while (apple) //  游戏循环执行
	{
		show();  // 显示画面
		HideCursor(); // 隐藏光标
		updateWithoutInput();  // 与用户输入无关的更新
		updateWithInput();  // 与用户输入有关的更新
	}
}
