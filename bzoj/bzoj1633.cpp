#include <bits/stdc++.h>
using namespace std;
int f[1010],l[1010];
int w,L;
char a[1010],b[510][60];
int check(int i,int id){
	int tot=0;/*
	for(int j=1;i<=L;i++){
		if(a[i]==b[id][j])j++;
		else tot++;
		if(j==l[id]+1)return tot;
	}
	return -1;*/
	int l1 = i, l2 = 1;
	while(l1 <= L) {
		if(a[l1] == b[id][l2]) ++l2;
		else ++tot;
		if(l2 == l[id] + 1) return tot;
		++l1;
	}
	return -1;
}
int main(){
	scanf("%d%d",&w,&L);
	scanf("%s",a+1);
	for(int i=1;i<=w;i++){
		scanf("%s",b[i]+1);
		l[i]=strlen(b[i]+1);
	}
	f[L+1] = 0;
	for(int i=L;i;i--){
		f[i]=f[i+1]+1;
		for(int j=1;j<=w;j++){
		//	if(a[i]==b[j][1]){
				int pd=check(i,j);
				if(pd!=-1){
					f[i]=min(f[i],f[i+l[j]+pd]+pd);
				}
		//	}
		}
	}
	printf("%d\n",f[1]);
	return 0;
} 
