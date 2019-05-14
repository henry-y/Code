#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 300010;

int n, top;
char s[N];
bool vis[N];
int id[N];

int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    if(s[1] == ')' || s[n] == '(') return puts(":("), 0;
    s[1] = '('; s[n] = ')';

    int cur = 1, tot = 0;
    for(int i = 2; i < n; ++i) if(s[i] == ')') id[++tot] = i;
    for(int i = 2; i < n; ++i) {
        if(s[i] == '(') {
            if(cur <= tot) {
                vis[id[cur]] = 1;
                vis[i] = 1;
                ++cur;
            }
        } 
        if(id[cur] == i) ++cur;
    }
    
    cur = n - 1;
    for(int i = 2; i < n; ++i) {
        if(s[i] == '(' && !vis[i]) {
            while(cur > 1 && ( s[cur] != '?' || (s[cur] == '?' && vis[cur]) ) ) 
                --cur;
            if(s[cur] == '?' && !vis[cur]) 
                vis[cur] = 1, s[cur] = ')', vis[i] = 1;
        } 
    }
    cur = 2;
    for(int i = n - 1; i > 1; --i) {
        if(s[i] == ')' && !vis[i]) {
            while(cur < n && ( s[cur] != '?' || (s[cur] == '?' && vis[cur] ) ) ) ++cur;
            if(s[cur] == '?' && !vis[cur]) vis[cur] = 1, s[cur] = '(', vis[i] = 1;
        }
    }
    
    bool flag = 0;
    top = 0;
    for(int i = 2; i < n; ++i) {
        if(s[i] == '?' && !vis[i]) {
            s[i] = flag ? ')' : '(';
            flag ^= 1;
        }
    }
    
    for(int i = 1; i <= n; ++i) {
        if(s[i] == '(') ++top;
        else --top;
        if(top <= 0 && i != n) return puts(":("), 0;
    }
    if(top != 0) return puts(":("), 0;
    puts(s + 1);
}