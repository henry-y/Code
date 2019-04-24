#include <bits/stdc++.h>
#define N 100010
using namespace std;
struct edge {
    int to,nxt,v;
}e[N];
int head[N],cnt,n,m;
int in[N],q[N*10];
int x[N],y[N];
void ins(int u,int v){
    e[++cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
int dp[N],f[N];
void dfs(int x){
    if(!head[x]){f[x]=1;return;}
    for(int i=head[x];i;i=e[i].nxt){
        if(!f[e[i].to])dfs(e[i].to);
        f[x]+=f[e[i].to];
    }
}
void dfs1(int x){
    if(!head[x]){dp[x]=1;return;}
    for(int i=head[x];i;i=e[i].nxt){
        if(!dp[e[i].to])dfs1(e[i].to);
        dp[x]+=dp[e[i].to];
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        if(u>v)swap(u,v);
        ins(u,v);
        x[i]=u;y[i]=v;
        in[v]++;
    }
    for(int i=1;i<=n;i++){
        if(!in[i])dfs1(i);
    }
    memset(head,0,sizeof(head));
    cnt=0;
    for(int i=1;i<=m;i++){
        ins(y[i],x[i]);
    }
    dfs(n);
    int ans=0;
    for(int i=1;i<=m;i++){
        ans=max(ans,f[x[i]]*dp[y[i]]);
    }
    printf("%d\n",ans);
    return 0;
} 
