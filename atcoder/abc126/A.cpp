#include <bits/stdc++.h>
using namespace std;

int n, k;
char s[1000];

int main() {
	cin >> n >> k;
	scanf("%s", s + 1);
	s[k] = s[k] - 'A' + 'a';
	puts(s + 1);
}