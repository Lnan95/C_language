#include <stdio.h>
int main()
{  
   int a,b,c,d,e;
   float f;
   scanf("%d %d",&a,&b);
   c = a+b;
   d = a-b;
   e = a*b;
   f = (float) a/b;
   printf("%d %d %d %.2f" ,c,d,e,f);
   return 0;
}
//输入两个整数，输出它们的和、差、积、商。 
//输入两个整数，第二个数不能为0，以空格间隔
//四个数在同一行中输出，中间以空格分隔，商保留两位小数
//输入样例 3 4 输出样例 7 -1 12 0.75 
