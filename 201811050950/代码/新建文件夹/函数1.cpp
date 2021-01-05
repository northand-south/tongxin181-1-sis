#include<stdio.h>
int main()
{
    int fun(int a,int b);
    int a,b,c;
    printf("请输入两位数a,b: ");
scanf("%d%d",&a,&b);
 c=fun(a,b);
    printf("The number c is %d\n",c);  //输出正整数c
    return 0;
}

int fun(int a,int b)
{
    int c1,c2,c3,c4;  //c1、c2、c3、c4分别对应c的千位、百位、十位、个位
    c1=a%10;
    c2=b/10;
    c3=a/10;
    c4=b%10;
    return (c1*1000+c2*100+c3*10+c4);
}