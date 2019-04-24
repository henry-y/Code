#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[1000010],cnt[1000010],ans[1000010];
int main(){
    scanf("%d",&n);
    int Max=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]),cnt[a[i]]++;
        Max=max(Max,a[i]);
    }
    for(int i=1;i<=Max;i++){
        if(cnt[i]){
            for(int j=i;j<=Max;j+=i){
                ans[j]+=cnt[i];
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",ans[a[i]]-1);
    }
    return 0;
} 
