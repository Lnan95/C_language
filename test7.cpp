#include <stdio.h>
int main()
{  
   int a,b,c;
   float d;
   scanf("%d %d %d",&a,&b,&c);
   d = (float) (a+b+c)/3;
   printf("%.3f",d);
   return 0;
}

//题目描述
//输入三个整数，求出平均值并输出，结果有小数部分。
 
//输入描述
//输入三个整数之间用空格分隔
 
//输出描述
//输出一个平均值，结果为实数，输出3位小数
 
//输入样例
//2 5 4
 
//输出样例
//3.667
