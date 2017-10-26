#include<iostream>
#include<cstdio>
using namespace std;
int n;
int map[205][205];
int main(){
	freopen("in.txt","r",stdin);
	cin >> n;
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			map[k][i] = 99999;
		}
	}
	for(int i = 1;i < n;i++){
        for(int j = i + 1;j <= n;j++){
        	cin >> map[i][j];
        }
    }
    /*
    for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			cout << map[k][i] << "  " ;
		}
		cout << endl;
	}
	cout << endl << endl;
	*/
    for(int k = 1;k <= n;k++){
    	for(int i = 1;i <= n;i++){
    		for(int j = 1;j <= n;j++){
    			if(map[i][j] > map[i][k] + map[k][j])
    				map[i][j] = map[i][k] + map[k][j];
    		}
    	}
    }
    /*
	for(int k = 1;k <= n;k++){
		for(int i = 1;i <= n;i++){
			cout << map[k][i] << "  " ;
		}
		cout << endl;
	}
	*/
    cout << map[1][n];
}
