#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll mod = 1e9 + 7;

int a[2][1010];
char s[1010];
ll f[1100][11][11][2][2][2];

ll dfs(int op, int pos, int num, bool done, bool lead, bool pre_lead, int pre_1, int pre_2, int tot) {
    // op 是属于r还是属于l , pos 位数, num 当前数, done 上界限制, lead前导零
    //pre_lead上一位的前导零, pre_1上一位, pre_2前一位, tot是否为萌数
    if(!pos) return tot;
    if(!done && f[pos][num][pre_1][tot][lead][pre_lead]) 
        return f[pos][num][pre_1][tot][lead][pre_lead] % mod;
    
    ll res = 0; int ed = done ? a[op][pos] : 9;
    for(int i = 0; i <= ed; ++i) {
        int now = 0;
        if(num == i && !lead) now = 1;
        if(pre_1 == i && !pre_lead) now = 1;

        res += dfs(op, pos - 1, i, done && (i == ed), lead && (!i), lead, num, pre_1, tot | now);
        res %= mod;
    }
    if(!done) return f[pos][num][pre_1][tot][lead][pre_lead] = res % mod;
    return res % mod;
}

ll count(int op, int pos, int num, bool done, bool lead, bool pre_lead, int pre_1, int pre_2, int tot) {
    memset(f, 0, sizeof(f));
    return (dfs(op, pos, num, done, lead, pre_lead, pre_1, pre_2, tot) + mod) % mod;
}

int main() {
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    for(int i = 1; i <= len; ++i) a[0][i] = s[i] - '0';
    reverse(a[0] + 1, a[0] + len + 1);
    
    a[0][1]--;
    int now = 1;
    while(a[0][now] < 0) a[0][now] += 10, a[0][now + 1]--, ++now;
    int len1 = len;
//	for(int i = len; i; --i) printf("%d", a[0][i]); puts("");

    scanf("%s", s + 1);
    len = strlen(s + 1);
    for(int i = 1; i <= len; ++i) a[1][i] = s[i] - '0';
    reverse(a[1] + 1, a[1] + len + 1);
//	for(int i = len; i; --i) printf("%d", a[1][i]); puts("");
    
    printf("%lld\n", (count(1, len, 0, 1, 1, 1, 0, 0, 0) - count(0, len1, 0, 1, 1, 1, 0, 0, 0) + mod) % mod);
}