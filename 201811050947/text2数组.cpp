#include <iostream>
#include <stdlib.h>
using namespace std;

int SelectMonkey(int *p,int m,int n);
main()
{
    int *p;
    int m,n,flag,temp;
    cout<<"依次输入猴子数量m报数大小n:";
	while(1){
    cin>>m;
	cin>>n;
    p=(int *)malloc(sizeof(int)*m); //为指针分配内存，申请m个int型大小的内存空间
    for(int i=0;i<m;i++)  //为m只猴子编号 
        p[i]=i+1;
    cout<<"按照"<<m<<"个猴子，每数到第"<<n<<"个数的方法，输出为大王的猴子是"<<SelectMonkey(p,m,n)<<"号";
    }
    free(p);  //将p（地址）指向的单元以后的内存段释放
}
int SelectMonkey(int *p,int m,int n)
{
    int temp,flag,count;
    temp=0;
    count=m;  //此时猴子的数量 
     while(count!=1)
    {
        flag=1;         //计数器
        while(flag<n)   //查找要删除的猴子的编号
        {
            if(temp>=m)
                temp=0;
            if(p[temp]!=0)
            {
                flag++;
            }
            temp++;
        }
        if(temp>=m)
            temp=0;
        while(temp<m&&p[temp]==0)
            {
                   temp++;
                   if(temp>=m)
                       temp=0;
            }      //跳过已删除猴子的标号
        p[temp]=0;   //删除猴子的编号 
        count-=1;    //剩下猴子的个数-1
    }
    for(int i=0;i<m;i++)
    {
        if(p[i]!=0)
        {
            return p[i];
        }
    }
}