#include <bits/stdc++.h>

using namespace std;

int s1,s2,t1,t2,n;
int q[500010][3];
int step[110][110];
int a[110][110];

const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};

bool check(int x,int y){
	if(x<1||x>n||y<1||y>n)return 0;
	if(a[x][y])return 0;
	return 1;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char ch;
		for(int j=1;j<=n;j++){
			cin>>ch;
			if(ch=='x')a[i][j]=1;
			else {
				if(ch=='A')s1=i,s2=j;
				if(ch=='B')t1=i,t2=j;
			}
		}
	}
	memset(step,0,sizeof(step));
	int l=1,r=2;
	q[1][0]=s1,q[1][1]=s2;
	while(l<r){
		int x=q[l][0],y=q[l++][1];
		if(x==t1&&y==t2)break;
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			while(check(nx,ny)){
				if(step[nx][ny]){
					nx+=dx[i];ny+=dy[i];
					continue;
				}
				step[nx][ny]=step[x][y]+1;
				q[r][0]=nx,q[r++][1]=ny;
				nx+=dx[i],ny+=dy[i];
			}
		}
	}
	printf("%d\n",step[t1][t2]-1);
	return 0;
}
