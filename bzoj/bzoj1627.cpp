#include <cstdio>
#include <cstring>
using namespace std;
int a[1100][1100];
int q[5000100][3],tx,ty,n;
const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};
int main(){
	scanf("%d%d%d",&tx,&ty,&n);
	tx+=500;ty+=500;
	memset(a,1,sizeof(a));
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x+500][y+500]=0;
	}
	int l=1,r=2;
	q[l][0]=500;q[l][1]=500;
	while(l!=r){
		int x=q[l][0],y=q[l][1],t=q[l++][2];
		if(l==5000000)l=1;
		if(x==tx&&y==ty){printf("%d\n",t);return 0;}
		for(int i=0;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx>=0&&nx<=1000&&ny>=0&&ny<=1000&&a[nx][ny]){
				q[r][0]=nx;q[r][1]=ny;q[r++][2]=t+1;a[nx][ny]=0;
				if(r==5000000)r=1;
			}
		}
	}
}
