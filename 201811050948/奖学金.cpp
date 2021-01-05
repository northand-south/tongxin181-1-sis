#include<stdio.h>
#include<algorithm>
using namespace std;
struct stu //定义一个结构体，描述数据对象std
{
   int ch,math,english; 
   int num,sum;  //学生数量，分数总和
}student[3000];//预设结构体容量

int cmp(stu x,stu y)//比较成绩
{
    if(x.sum!=y.sum)//总分不相等
		return x.sum>y.sum;
	//总分相等
    if(x.ch!=y.ch) 
		return x.ch>y.ch;
    if(x.num!=y.num) 
		return x.num<y.num;
}
int main()//排序
{
    int i,j,n,m;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      scanf("%d%d%d",&student[i].ch,&student[i].math,&student[i].english);
      student[i].num=i+1;
      student[i].sum=student[i].ch+student[i].math+student[i].english;
    }
    sort(student,student+n,cmp);//快速排序
    for(i=0;i<5;i++)
    printf("%d %d\n",student[i].num,student[i].sum);
    while(1);
    return 0;
}