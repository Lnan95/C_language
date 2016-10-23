#include <stdio.h>
int main()
{  
   float a,b,c,d;
   scanf("%f %f %f",&a,&b,&c);
   d =(float) (a+b)*c*1/2;
   printf("%.3f" ,d);
   return 0;
}

//输入梯形的上底、下底和高，求梯形面积。
//输入梯形的上底、下底和高这三个实数，各数之间以空格分隔
//输出结果保留3位小数
//输入范例 3 5 2.5 输出范例  10.000
