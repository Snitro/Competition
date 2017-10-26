#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,m;// n 选手总数，m 录取人数
struct pe{
	int id;
	int grade;
}p[5005];
bool cmp(pe a,pe b){
	if(a.grade != b.grade)
		return a.grade > b.grade;
	return a.id < b.id;
}
int main(){
	freopen("in.txt","r",stdin);
	cin >> n >> m;
	m *= 1.5;
	for(int i = 1;i <= n;i++)
		cin >> p[i].id >> p[i].grade;
	sort(p + 1,p + 1 + n,cmp);
	int ans = 0;
	int e = p[m].grade;
	cout << e << " ";
	int sh = m;
	for(int i = m + 1;i <= n;i++){
		if(p[i].grade == p[m].grade)
			sh++;
	}
	cout << sh << endl;
	for(int i = 1;i <= n;i++){
		if(p[i].grade >= p[m].grade)
			cout << p[i].id << " " << p[i].grade << endl;
		else
			return 0;
	}
}
