#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 100010;
const ll mod = 1e9 + 7;

ll n;
char s[N];
struct mat {
    ll m[26][26];
};

mat operator * (mat a, mat b) {
    mat c;
    memset(c.m, 0, sizeof(c.m));
    for(int i = 0; i < 26; ++i) {
        for(int j = 0; j < 26; ++j) {
            for(int k = 0; k < 26; ++k) {
                c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j] % mod) % mod;
            }
        }
    }
    return c;
}

mat base, ans, now;

int idx(char c) {return c - 'a';} 

void print(mat a) {
    for(int i = 0; i < 26; ++i) {
        for(int j = 0; j < 26; ++j) printf("%d ", a.m[i][j]);
        puts("");
    }
}

int main() {
    scanf("%lld%s", &n, s + 1);
    for(int i = 0; i < 26; ++i) for(int j = 0; j < 26; ++j) base.m[i][j] = 1;
    int len = strlen(s + 1);
    for(int i = 1; i < len; ++i) {
        base.m[idx(s[i])][idx(s[i + 1])] = 0;
    }

    memset(ans.m, 0, sizeof(ans.m));
    memset(now.m, 0, sizeof(now.m));
    for(int i = 0; i < 26; ++i) ans.m[i][i] = 1;

    --n;
    while(n) {
        if(n & 1) ans = ans * base;
        base = base * base; n >>= 1;
    }
    for(int i = 0; i < 26; ++i) for(int j = 0; j < 26; ++j) now.m[i][j] = 1;
    now = now * ans;

    ll sum = 0;
    for(int i = 0; i < 26; ++i) sum = (sum + now.m[i][i]) % mod;
    printf("%lld\n", sum);
}