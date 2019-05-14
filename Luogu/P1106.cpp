#include <bits/stdc++.h>
using namespace std;

namespace io {
char buf[1<<21], *p1 = buf, *p2 = buf;
inline char gc() {
    if(p1 != p2) return *p1++;
    p1 = buf;
    p2 = p1 + fread(buf, 1, 1 << 21, stdin);
    return p1 == p2 ? EOF : *p1++;
}
#define G gc

#ifndef ONLINE_JUDGE
#undef G
#define G getchar
#endif

#define I int
inline I read() {
    I x = 0, f = 1; char c = G();
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = G(); }
    while(c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = G(); }
    return x * f;
}

inline void write(I x) {
    if(x == 0) {putchar('0'); return;}
    I tmp = x > 0 ? x : -x;
    if(x < 0) putchar('-');
    int cnt = 0;
    while(tmp > 0) {
        buf[cnt++] = tmp % 10 + '0';
        tmp /= 10;
    }
    while(cnt > 0) putchar(buf[--cnt]);
}
#undef I

#define in(x) x = read()
#define outn(x) write(x), putchar('\n')
#define out(x) write(x), putchar(' ')

} using namespace io;

#define ll long long
const int N = 100010;

char st[N], s[N];
int k;

int main() {
    scanf("%s", s + 1);
    k = read();
    int len = strlen(s + 1), top = 0, K = k;
    for(int i = 1; i <= len; ++i) {
        if(!k) {st[++top] = s[i]; continue;}
        if(s[i] >= st[top]) {
            st[++top] = s[i];
        } else {
            while(k && top && st[top] > s[i]) {
                --top;
                --k;
            }
            st[++top] = s[i];
        }
    }
    bool lead = 1;
    for(int i = 1; i <= len - K; ++i) {
        if(lead && st[i] == '0') continue; 
        putchar(st[i]);
        lead = 0;
    }
    if(lead) puts("0");
    return 0;
}