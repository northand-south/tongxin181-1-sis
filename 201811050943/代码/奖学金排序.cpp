#include<iostream>
#include<algorithm>
using namespace std;

struct student{
	int id;//ѧ��
	int s;//�ܷ�
	int yw;//���ĳɼ�
}stu[310];

bool cmp(student a,student b){
	if(a.s != b.s) return a.s>b.s; //����ֲܷ�һ�������ָܷߵ�����ǰ
	else{//�ܷ�һ��
		if(a.yw == b.yw) return a.id < b.id;//�ܷ�һ�������ĳɼ�һ��������ѧ��С����
		else return a.yw > b.yw; //�ܷ�һ�������Ĳ�һ�����������ĸߵ���
	}
}

int main()
{
	int n;
	cin>>n;
	int i,j,s1,s2,s3;
	for(i = 1;i <= n;i++){
		cin>>s1>>s2>>s3;
		stu[i].s = s1 + s2 + s3;
		stu[i].id = i;
		stu[i].yw = s1;
	}
	
	sort(stu + 1,stu + n + 1,cmp);//��1~n�ĳɼ�
	
	for(i = 1;i <= 5;i++){
		cout<<stu[i].id<<" "<<stu[i].s<<endl;
	}
	return 0;
}