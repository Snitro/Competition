#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int f[100005],f2[100005],a[100005],a2[100005],t,n;
int getbig(int id){
    int big = 0;
    for(int i = 0;i < id;i++){
    	//cout << id << " " << a[i] << " " << a[id] << endl;
        if(a[i] < a[id])
            if(big < f[i])
                big = f[i];
    }
    return big;
}
int getbig2(int id){
    int big = 0;
    for(int i = 0;i < id;i++){
        if(a2[i] < a2[id])
            if(big < f2[i])
                big = f2[i];
    }
    return big;
}
int main(){
	freopen("in.txt","r",stdin);
    cin >> n;
   	for(int i = 0;i < n;i++){
   		cin >> a[i];
   		a2[n - i - 1] = a[i];
   	}
   	for(int i = 0;i < n;i++){
        f[i] = getbig(i) + 1;
        f2[i] = getbig2(i) + 1;
    }
    /*
    for(int i = 0;i < n;i++)
    	cout << f[i] << " ";
    cout << endl;
    for(int i = n - 1;i >= 0;i--)
    	cout << f2[i] << " ";
    cout << endl;
    */
    int big = 0;
    int a = 0;
    for(int i = n - 1;i >= 0;i--){
    	f[a] += f2[i];
    	if(f[a] > big)
    		big = f[a];
    	a++;
    }
    big --;
    cout << n - big;
}
