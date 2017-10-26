#include<iostream>
#include<cstdio>
#include<sstream>
using namespace std;
int n;//´ÎÊý 
int in[100];
int main(){
	freopen("in.txt","r",stdin);
	cin >> n;
	for(int i = n;i >= 0;i--){
		cin >> in[i];
	}
	while(in[n] == 0){
		n--;
	}
	stringstream sout;
	for(int i = n;i >= 0;i--)
		sout << in[i] << " ";
	int x = 1;
	int i = n;
	{
		sout >> x;
		if(x == 1)
			cout << "x^" << i;
		else if(x == -1)
			cout << "-x^" << i;
		else{
			if (x != 0)
				cout << x << "x^" << i;
		}
		i--;
	}
	for(;i >= 2;i--){
		sout >> x;
		if(x == 1)
			cout << "+x^" << i;
		else if(x == -1)
			cout << "-x^" << i;
		else{
			if(x > 0)
				cout << "+" << x << "x^" << i;
			else if (x < 0)
				cout << x << "x^" << i;
		}
	}
	{
		sout >> x;
		if(x == 1)
			cout << "+x";
		else if(x == -1)
			cout << "-x^";
		else{
			if(x > 0)
				cout << "+" << x << "x";
			else if (x < 0)
				cout << x << "x";
		}
	}
	{
		sout >> x;
		if(x == 1)
			cout << "+1";
		else if(x == -1)
			cout << "-1";
		else{
			if(x > 0)
				cout << "+" << x;
			else if (x < 0)
				cout << x;
		}
	}
	
}
