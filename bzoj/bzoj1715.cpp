#include <cstdio>
#include <cstring>
using namespace std;
#define N 100010
int n,m,w,f,cnt,head[N];
struct edge {int to,nxt,v;}e[N];
void ins(int u,int v,int w){
    e[++cnt].to=v;e[cnt].nxt=head[u];e[cnt].v=w;head[u]=cnt;
    e[++cnt].to=u;e[cnt].nxt=head[v];e[cnt].v=w;head[v]=cnt;
}
void ins2(int u,int v,int w){
    e[++cnt].to=v;e[cnt].nxt=head[u];e[cnt].v=w;head[u]=cnt;
}
int t[N],q[N*10],d[N];
bool vis[N];
void spfa(){
    memset(vis,0,sizeof(vis));
    memset(d,127,sizeof(d));
    memset(t,0,sizeof(t));
    d[1]=0;q[1]=1;vis[1]=1;t[1]=1;
    int l=1,r=2;
    while(l<r){
        int u=q[l++];
        t[u]++;
        if(t[u]>n-1){puts("YES");return;}
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].to;
            if(d[v]>d[u]+e[i].v){
                d[v]=d[u]+e[i].v;
                if(!vis[v])vis[v]=1,q[r++]=v;
            }
        }
        vis[u]=0;
    }
    puts("NO");
}
int main(){
    scanf("%d",&f);
    while(f--){
        memset(head,0,sizeof(head));
        cnt=0;
        scanf("%d%d%d",&n,&m,&w);
        for(int i=1;i<=m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            ins(x,y,z);
        }
        for(int i=1;i<=w;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            ins2(x,y,-z);
        }
        spfa();
    }
}
