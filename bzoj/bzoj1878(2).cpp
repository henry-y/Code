#include <bits/stdc++.h>

using namespace std;

int read()
{
    char x;
    while((x = getchar()) > '9' || x < '0') ;
    int u = x - '0';
    while((x = getchar()) <= '9' && x >= '0') u = (u << 3) + (u << 1) + x - '0';
    return u;
}
int buf[105];  
inline void write(int i) {  
    int p = 0;  
    if(i == 0) p++;  
    else while(i) {  
        buf[p++] = i % 10;  
        i /= 10;  
    }  
    for(int j = p-1; j >= 0; j--) putchar('0' + buf[j]);  
} 

#define il inline
#define re register

int block,ans=0,cnt[1000001];
int n,m,a[500010],Ans[500010];

struct node {
	int l,r,id;
}q[500010];

il bool cmp(node a,node b){
	return (a.l/block)^(b.l/block)?a.l<b.l:(((a.l/block)&1)?a.r<b.r:a.r>b.r);
}

il void add(int x){
	if(!cnt[a[x]])ans++;
	cnt[a[x]]++;
}

il void del(int x){
	cnt[a[x]]--;
	if(!cnt[a[x]])ans--;
}

int main(){
	n=read();
	for(re int i=1;i<=n;i++)a[i]=read();
	m=read();
	block=n/sqrt(m*2/3);
	for(re int i=1;i<=m;i++){
		q[i].l=read(),q[i].r=read();
		q[i].id=i;
	}
	sort(q+1,q+m+1,cmp);
	re int l=0,r=0;
	for(re int i=1;i<=m;i++){
		re int ql=q[i].l,qr=q[i].r;
		while(l<ql)del(l++);
		while(l>ql)add(--l);
		while(r<qr)add(++r);
		while(r>qr)del(r--);
		Ans[q[i].id]=ans;
	}
	for(re int i=1;i<=m;i++)write(Ans[i]),puts("");
	return 0;
}
