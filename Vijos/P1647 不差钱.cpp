#include <iostream>
#include <cstdio>
#include <algorithm>

#define lowbit(x) ((x) & (-(x)))

using namespace std;

int price, tree[100005], map[100005], clean[100005], size, data_len;

struct Data {
    int flag;
    int value;
    int real;
} datas[100005];

void update(int x, int num) {
    while (x <= size) {
        tree[x] += num;
        x += lowbit(x);
    }
}

long long query(int x) {
    long long ret = 0;

    while (x) {
        ret += tree[x];
        x -= lowbit(x);
    }

    return ret;
}

bool cmp(int a, int b) {
    return datas[a].value < datas[b].value;
}

int main() {
    freopen("in.txt", "r", stdin);

    scanf("%d", &price);

    while (true) {
        ++data_len;
        scanf("%d%d", &datas[data_len].flag, &datas[data_len].value);

        if (datas[data_len].value == datas[data_len].flag && datas[data_len].flag == 0) {
            data_len--;
            break;
        }
            

        if (datas[data_len].flag == 1) {
            clean[++size] = data_len;
            map[size] = data_len;
        }
    }

    sort(clean + 1, clean + 1 + size, cmp);

    for (int i = 1; i <= size; i++) {
        datas[clean[i]].real = datas[clean[i]].value;
        datas[clean[i]].value = i;
    }

    int tot = 0;

    for (int i = 1; i <= data_len; i++) {
        if (datas[i].flag == 1) {
            update(datas[i].value, 1);
            tot++;
        } else if (datas[i].flag == 2)
            datas[map[datas[i].value]].value = -1;
        else {
            int l = 1, r = size, m;

            while (l < r) {
                m = (l + r) >> 1;

                if (query(m) >= tot + 1 - datas[i].value)
                    r = m;
                else
                    l = m + 1;
            }

            if (datas[clean[l]].real > price)
                puts("Dui bu qi,Mei you.");
            else if (datas[clean[l]].value == -1) {
                bool flag = false;
                for (int i = l - 1; i >= 1 && datas[clean[i]].real == datas[clean[l]].real ; i--)
                    if (datas[clean[i]].value != -1) {
                        printf("You. %d Yuan.\n", datas[clean[i]].real);
                        flag = true;
                        break;
                    }

                if (!flag)
                    puts("Mei you. Zhe ge ke yi you. Zhe ge zhen mei you!");
            } else
                printf("You. %d Yuan.\n", datas[clean[l]].real);
        }
    }

    return 0;
}
