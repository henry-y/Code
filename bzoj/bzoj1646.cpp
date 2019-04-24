#include <bits/stdc++.h>

using namespace std;

#define N 100010

bool vis[N*2];
int t,x1,y;
int q[5000000][2];

int main(){
	scanf("%d%d",&x1,&y);
	int l=1,r=2;
	q[1][0]=x1,q[1][1]=0;
	while(l<r){
		int x=q[l][0],st=q[l++][1];
		if(x==y){
			printf("%d\n",st);
			break;
		}
		if(x*2<=y*2&&!vis[x*2]){
			q[r][0]=x*2;q[r++][1]=st+1;
			vis[x*2]=1;
		}
		if(!vis[x+1]&&x+1<=y){
			q[r][0]=x+1;q[r++][1]=st+1;
			vis[x+1]=1;
		}
		if(!vis[x-1]&&x-1>0){
			q[r][0]=x-1;q[r++][1]=st+1;
			vis[x-1]=1;
		}
	}
}
