#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct node {
	int x,y;
}a[300];

int h1,h2,n;
int c[300],f[300][40000];
//f[i][j]��ʾǰi����ʱ����һ�������ʱ��Ϊj�����Ž� 
//c����ά��ǰ׺�� 

bool cmp(node a,node b){
	return a.y>b.y;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	
	memset(f,0x3f,sizeof(f));
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)c[i]=c[i-1]+a[i].x;
	
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=c[i];j++){
			f[i][j]=min(f[i][j],max(f[i-1][j],c[i]-j+a[i].y));
			//������һ�����ڳ� 
			if(j-a[i].x>=0)f[i][j]=min(f[i][j],max(f[i-1][j-a[i].x],j+a[i].y));
			//�ڵ�ǰ���ڳ� 
		}
	}
	
	int ans=0x3f3f3f3f;
	for(int i=0;i<=c[n];i++){
		ans=min(ans,f[n][i]);
	}
	printf("%d\n",ans);
	
	return 0;
}
