#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,d[100000];
int f[10505][505];
//f[i,j]��ʾ��i���ӵ�ƣ�Ͷ�Ϊj�����Ž� 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
	}
	f[1][1]=d[1];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=min(m,i);j++){
			if(j==0){
				f[i][j]=max(f[i-1][0],f[i][j]);
			}else {
				f[i+j][0]=max(f[i+j][0],f[i][j]);//ѡ����Ϣ
			}
			f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+d[i+1]);//ѡ���ܲ�
		}
	}
	printf("%d\n",f[n][0]);
	return 0;
}
