#include <stdio.h>
int fun(int &a,int &b)
{
int c=(b%10)+10*(a/10)+100*(b/10)+1000*(a%10);
return c;
}
int main() 
{
int a;
int b;
printf("��������λ��a,b: ");
scanf("%d%d",&a,&b);
int c=fun(a,b);
printf("���Ϊ:%d",c);
printf("\n");
return 0;
}