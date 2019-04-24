#include <cstdio>
#include <cstdlib>
using namespace std;
int n,f[20][20],a[20],s;
bool vis[20];
void dfs(int x,int sum){
    if(sum>s)return;
    if(x==n+1){
        if(sum!=s)return;
        for(int i=1;i<=n;i++)printf("%d ",a[i]);
        puts("");
        exit(0);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            a[x]=i;
            vis[i]=1;
            dfs(x+1,f[n][x]*i+sum);
            vis[i]=0;
        }
    }
}
int main(){
    scanf("%d%d",&n,&s);
    f[1][1]=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            f[i][j]=f[i-1][j]+f[i-1][j-1];
        }
    }
    dfs(1,0);
    return 0;
}
