#include <iostream>
#include <cstdio>

using namespace std;

int n, m;

int zero, one;

struct Door {
    int oper;//1:ans 2:or 3:xor
    int num;
} doors[100005];

int count(int num) {
    for (int i = 1; i <= n; i++) {
        if (doors[i].oper == 1)
            num = num & doors[i].num;
        else if (doors[i].oper == 2)
            num = num | doors[i].num;
        else
            num = num ^ doors[i].num;
    }
    
    return num;
}

int main() {
    freopen("in.txt", "r", stdin);
    
    scanf("%d%d", &n, &m);
    
    char temp[5];
    
    for (int i = 1; i <= n; i++) {
        scanf("%s%d", temp, &doors[i].num);
        
        if (temp[0] == 'A')
            doors[i].oper = 1;
        else if (temp[0] == 'O')
            doors[i].oper = 2;
        else
            doors[i].oper = 3;
    }
    
    zero = count(0);
    
    int tem = 0, tot = 0;
    
    do {
        tem = tem << 1;
        tem |= 1;
        tot++;
    } while (tem < m);
    
    one = count(tem);
    
    int ans = 0;
    
    for (int j = tot - 1; j >= 0; j--)
    	if (!(zero & (1 << j)) && (one & (1 << j)) && (ans | (1 << j)) <= m) 
        	ans |= (1 << j);
    
    printf("%d", count(ans));
    
    return 0;
}
