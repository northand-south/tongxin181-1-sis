#include<stdio.h>
#include<algorithm>
using namespace std;
struct stu //����һ���ṹ�壬�������ݶ���std
{
   int ch,math,english; 
   int num,sum;  //ѧ�������������ܺ�
}student[3000];//Ԥ��ṹ������

int cmp(stu x,stu y)//�Ƚϳɼ�
{
    if(x.sum!=y.sum)//�ֲܷ����
		return x.sum>y.sum;
	//�ܷ����
    if(x.ch!=y.ch) 
		return x.ch>y.ch;
    if(x.num!=y.num) 
		return x.num<y.num;
}
int main()//����
{
    int i,j,n,m;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      scanf("%d%d%d",&student[i].ch,&student[i].math,&student[i].english);
      student[i].num=i+1;
      student[i].sum=student[i].ch+student[i].math+student[i].english;
    }
    sort(student,student+n,cmp);//��������
    for(i=0;i<5;i++)
    printf("%d %d\n",student[i].num,student[i].sum);
    while(1);
    return 0;
}