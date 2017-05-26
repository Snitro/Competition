#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<queue>
using namespace std;
bool cmp(string,string);
string m,n;
int rel = 0,en = 9999;
struct in{
	string m;
	string n;
}re[10];
struct li{
	string m;
	int w;
};
struct lie{//自定义的队列，支持查找是否已入过队 
	string allin[900000];
	int al;
	li sa[900000];
	int hand,tail;
	lie(){
		al = 0;
		hand = 0;
		tail = 0;
	}
	li front(){
		return sa[hand];
	}
	li back(){
		return sa[tail - 1];
	}
	int size(){
		return tail - hand;
	}
	void pop(){
		hand++;
	}
	void push(li l){
		allin[al++] = l.m;
		sa[tail++] = l;
	}
	bool find(string s){
		for(int i = 0;i < al;i++)
			if(cmp(s,allin[i]))
				return true;
		return false;
	}
	bool empty(){
		return size() == 0;
	}
}lie;
li l;
void del(string &m,string &n){
	int p = 0;
	for(int i = 0;i < min(m.size(),n.size());i++)
		if(m[i] != n[i]){
			p = i;
			break;
		}
	if(p == 0)
		return;
	m = m.replace(0,p,"");
	n = n.replace(0,p,"");
}
bool cmp(string m,string n){
	if(m.size() != n.size())
		return false;
	for(int i = 0;i < m.size();i++)
		if(m[i] != n[i])
			return false;
	return true;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin >> m >> n;
	while(cin >> re[rel].m){
		cin >> re[rel].n;
		rel++;
	}
	del(m,n);
	l.m = m;
	l.w = 0;
	lie.push(l);
	while(!lie.empty()){
		cout << lie.size() << endl;
		for(int i = 0;i < rel;i++)	{
			if(lie.front().m.find(re[i].m) != string::npos){
				string s = lie.front().m;
				s = s.replace(lie.front().m.find(re[i].m),re[i].m.size(),re[i].n);
				cout << lie.front().m << "--->" << s << endl;
				l.w = lie.front().w + 1;
				l.m = s;
				if(!lie.find(s))//曾经入队后的不需要再次入队 
					lie.push(l);
				if(cmp(lie.back().m,n)){
					cout << lie.back().w;
					return 0;
				}
			}
		}
		lie.pop();
	}
	cout << "NO ANSWER!";
	return 0;
}
