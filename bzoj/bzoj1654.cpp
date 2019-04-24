#include <bits/stdc++.h>

using namespace std;

#define N 100010

int n,m,tot=0,top=0,ans=0;
int dfn[N],low[N],belong[N],st[N];
bool inst[N];
int head[N],cnt,num;
struct edge {
	int to,nxt;
}e[N];

void ins(int u,int v){
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}

void tarjan(int x){
	low[x]=dfn[x]=++tot;
	st[++top]=x;inst[x]=1;
	for(int i=head[x];i;i=e[i].nxt){
		if(!dfn[e[i].to]){
			tarjan(e[i].to);
			low[x]=min(low[x],low[e[i].to]);
		}else {
			if(inst[e[i].to]){
				low[x]=min(dfn[e[i].to],low[x]);
			}
		}
	}
	if(dfn[x]==low[x]){
		num++;
		int u,num1=0;
		do {
			num1++;
			u=st[top--];
			inst[u]=0;
			belong[u]=num;
		}while(u!=x);
		if(num1!=1)ans++;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ins(x,y);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i])tarjan(i);
	}
	printf("%d\n",ans);
} 
