#include <cstdio>
using namespace std;
char s[10000];
bool check(int l,int r){
	for(int i=l;i<=r;i++){
		if(s[i]<s[r-(i-l)])return 1;
		else if(s[i]>s[r-(i-l)])return 0;
	}
	return 1;
}
int main(){
	int n;
	scanf("%d",&n);
	int l=1,r=n,cnt=0;
	for(int i=1;i<=n;i++){
		char c=getchar();
		while(c<'A'||c>'Z')c=getchar();
		s[i]=c;
	}
	while(l<=r){
		if(s[l]>s[r]){
			putchar(s[r]);r--;
		}else {
			if(s[r]>s[l]){
				putchar(s[l]);l++;
			}else {
				if(check(l,r))putchar(s[l++]);
				else putchar(s[r--]);
			}
		}
		cnt++;
		if(cnt==80)putchar('\n'),cnt=0;
	}
	return 0;
} 
