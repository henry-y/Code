#include <bits/stdc++.h>
using namespace std;

void read(int &x) {
	x = 0; char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
}

#define N 600010
int trie[N * 24][2], root[N];
int n, m, s[N], v[N * 24];
int tot;

void insert(int id, int last, int rt) {
	for(int k = 23; k >= 0; --k) {
		int c = (s[id] >> k) & 1;
		if(last) trie[rt][c ^ 1] = trie[last][c ^ 1];
		v[trie[rt][c] = ++tot] = v[trie[last][c]] + 1;
		rt = trie[rt][c]; last = trie[last][c];
	}
}

int query(int last, int val, int rt) {
	int ans = 0;
	for(int k = 23; k >= 0; --k) {
		int c = (val >> k) & 1;
		if(v[trie[rt][c ^ 1]] > v[trie[last][c ^ 1]]) 
			ans += 1 << k, rt = trie[rt][c ^ 1], last = trie[last][c ^ 1];
		else rt = trie[rt][c], last = trie[last][c];
	}
	return ans;
}

int main() {
	read(n), read(m);
	root[0] = ++tot;
	insert(0, 0, 1);
	for(int i = 1; i <= n; ++i) {
		int x; 
		read(x);
		s[i] = s[i - 1] ^ x;
		root[i] = ++tot;
		insert(i, root[i - 1], root[i]);
	}
	for(int i = 1; i <= m; ++i) {
		char ch[2];
		int l, r, x;
		scanf("%s", ch);
		if(ch[0] == 'A') {
			read(x);
			root[++n] = ++tot;
			s[n] = s[n - 1] ^ x;
			insert(n, root[n - 1], root[n]);
		} else {
			read(l), read(r), read(x);
			--l, --r;
			printf("%d\n", query(l - 1 >= 0 ? root[l - 1] : 0, x ^ s[n], root[r]));
		}
	}
	return 0;
}