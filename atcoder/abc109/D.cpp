#include<bits/stdc++.h>
using namespace std;
int a[510][510];
int n,m;
int ans;
struct data{
	int i,j;
	int x,y;
}tot[1000010];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	    scanf("%d",&a[i][j]);
	for(int i=1;i<n;i++)
	  for(int j=1;j<=m;j++)
	  	if(a[i][j]&1) 
			a[i+1][j]++,tot[++ans].i=i,tot[ans].j=j,tot[ans].x=i+1,tot[ans].y=j;
	for(int j=1;j<m;j++) if(a[n][j]&1) a[n][j+1]++,tot[++ans].i=n,tot[ans].j=j,tot[ans].x=n,tot[ans].y=j+1;
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++) printf("%d %d %d %d\n",tot[i].i,tot[i].j,tot[i].x,tot[i].y); 	
	return 0;
}
