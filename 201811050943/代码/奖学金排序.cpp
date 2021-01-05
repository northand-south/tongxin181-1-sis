#include<iostream>
#include<algorithm>
using namespace std;

struct student{
	int id;//学号
	int s;//总分
	int yw;//语文成绩
}stu[310];

bool cmp(student a,student b){
	if(a.s != b.s) return a.s>b.s; //如果总分不一样，则总分高的排在前
	else{//总分一样
		if(a.yw == b.yw) return a.id < b.id;//总分一样，语文成绩一样，则按照学号小的排
		else return a.yw > b.yw; //总分一样，语文不一样，按照语文高低排
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
	
	sort(stu + 1,stu + n + 1,cmp);//排1~n的成绩
	
	for(i = 1;i <= 5;i++){
		cout<<stu[i].id<<" "<<stu[i].s<<endl;
	}
	return 0;
}