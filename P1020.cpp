#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int i = 1,j,k,x,n,maxx,m;
int a[10000],b[10000],h[10000];
int main()
{
	while(cin>>a[i])
	{
		maxx=0;
		for(j=1;j<=i-1;j++)
			if(a[j]>=a[i])
				if(b[j]>maxx)
					maxx=b[j];
		b[i]=maxx+1;
		if(b[i]>m)
			m=b[i];
		x=0;
		for(k=1;k<=n;k++)
			if(h[k]>=a[i])
				if(x==0)
					x=k;
				else if(h[k]<h[x])
					x=k;
		if(x==0)
			n++;
		x=n;
		h[x]=a[i];
		i++;
	}
	cout<<m<<endl<<n<<endl;
}
