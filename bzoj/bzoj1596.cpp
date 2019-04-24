#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
#define inf 1<<30
#define il inline 
#define in1(a) read(a)
#define in2(a,b) in1(a),in1(b)
#define in3(a,b,c) in2(a,b),in1(c)
#define in4(a,b,c,d) in2(a,b),in2(c,d)
il void readl(ll &x){
    x=0;ll f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    x*=f;
}
il void read(int &x){
    x=0;int f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    x*=f;
}
using namespace std;
/*===================Header Template=====================*/
#define N 100010
struct edge{int to,next;}e[N<<2];
struct node{
    int dep,id,f;
    bool operator < (const node &x) const {
        return dep<x.dep;
    }
}a[N<<1];
int n,cnt=0,head[N<<2];
void ins(int u,int v){
    e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;
}
bool vis[N];
void dfs(int x,int f,int dep){
    a[x].dep=dep;
    a[x].f=f;
    a[x].id=x;
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=f)
            dfs(e[i].to,x,dep+1);
}
priority_queue<node>q;
int main(){
    in1(n);
    for(int i=1;i<n;i++){
        int u,v;
        in2(u,v);
        ins(u,v);ins(v,u);
    }
    dfs(1,1,1);
    for(int i=1;i<=n;i++)q.push(a[i]);
    int ans=0;
    while(!q.empty()){
        node t=q.top();q.pop();
        if(vis[t.id])continue;
        vis[t.id]=1;
        vis[t.f]=1;
        ans++;
        for(int i=head[t.f];i;i=e[i].next){
            int v=e[i].to;
            if(!vis[v])vis[v]=1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
