#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

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

template<class I>
inline void read(I &x) {
    x = 0; I f = 1; char c = G();
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = G(); }
    while(c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = G(); }
    x *= f;
}

#define ll long long
const int N = 500010;
const int M = N * 40;
int n, k, root[N], tot;
ll s[N], a[N];

struct Trie {
	int ch[2], siz, id;
}t[M];

void insert(int id, int v, int p, int &rt, int last) {
	rt = ++tot;
	t[rt] = t[last];
	t[rt].siz++;
	if(p == -1) {t[rt].id = id; return;}
	int c = (v >> p) & 1;
	insert(id, v, p - 1, t[rt].ch[c], t[last].ch[c]);
}

int query(int v, int p, int rt, int last) {
	if(p == -1) return t[rt].id;
	int c = (v >> p) & 1;
	if(t[t[rt].ch[c ^ 1]].siz > t[t[last].ch[c ^ 1]].siz) 
		return query(v, p - 1, t[rt].ch[c ^ 1], t[last].ch[c ^ 1]);
	else return query(v, p - 1, t[rt].ch[c], t[last].ch[c]);
}

struct Node {
	int l, r, id, pos;
	ll v;
	Node(int L, int R, int ID) {
		l = L, r = R, id = ID, pos = query(s[ID], 31, root[R], root[L - 1]);
		v = s[id] ^ s[pos - 1];
	}
};

bool operator < (Node a, Node b) {
	return a.v < b.v;
}
priority_queue<Node> q;

int main() {
#ifndef ONLINE_JUDGE
	freopen("2.in", "r", stdin);
#endif
	read(n), read(k);
	for(int i = 1; i <= n; ++i) {
		read(a[i]);
		s[i] = s[i - 1] ^ a[i];
	}
	for(int i = 1; i <= n; ++i) {
		insert(i, s[i - 1], 31, root[i], root[i - 1]);
	}
	for(int i = 1; i <= n; ++i) q.push(Node(1, i, i));
	ll ans = 0;
	while(!q.empty() && k) {
		int id = q.top().id, l = q.top().l, r = q.top().r, pos = q.top().pos;
		ans += q.top().v; --k; q.pop();
		if(pos != l) q.push(Node(l, pos - 1, id));
		if(pos != r) q.push(Node(pos + 1, r, id));
	}
	printf("%lld\n", ans);
}