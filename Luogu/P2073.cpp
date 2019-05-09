#include <bits/stdc++.h>

using namespace std;
#define N 100010
#define ll long long

int n, cnt;
struct task {
    int w, c;
}a[N];

bool operator < (task a, task b) {
    if(a.c == b.c) return 0;
    return a.c < b.c;
}

set<task> s;

int main() {
    int op, x, y;
    while(~scanf("%d", &op) && op != -1) {
        if(op == 1) {
            scanf("%d%d", &x, &y);
            if(s.find({x, y}) != s.end()) continue;
            s.insert({x, y});
        }
        if(op == 3) {
            if(s.empty()) continue;
            s.erase(s.begin());
        }
        if(op == 2) {
            if(s.empty()) continue;
            set<task>::iterator it = s.end();
            --it;
            s.erase(it);
        }
    }
    set<task>::iterator it = s.begin();
    int ans1 = 0, ans2 = 0;
    for(; it != s.end(); it++) {
        ans1 += (*it).w;
        ans2 += (*it).c;
    }
    printf("%d %d\n", ans1, ans2);
}