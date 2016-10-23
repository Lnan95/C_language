#include <math.h>
#include <stdio.h>
int main()
{  
   float a,b,c;
   scanf("%f %f",&a,&b);
   c =(float) sqrt(a*a+b*b);
   printf("%.2f" ,c);
   return 0;
}


//输入直角三角形的两条边，利用勾股定理，求出该三角形的斜边，结果精确到小数点后2位。(求平方根函数为sqrt(x))。
//输入两条直角边长度，两数之间用空格间隔
//输出结果保留两位小时
//输入范例 3.2 4.365 输出范例  5.41
