#include <stdio.h>
int main()
{  
   int d,h,m,a;
   scanf("%d %d %d",&d,&h,&m);
   a = d*24*60 + h*60 +m;
   printf("%d",a);
   return 0;
}

//将d天h小时m分钟换算成分钟，输入d、h、m，输出换算结果。
//输入天、小时、分钟三个数，以空格分隔
//输出换算好的分钟数
//输入范例 7 4 10 输出范例  10330
