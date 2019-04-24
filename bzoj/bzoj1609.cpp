#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n,a[100000],f[100000];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	memset(f,127,sizeof(f));
	int m=1;f[1]=a[1];
	for(int i=2;i<=n;i++){//LIS
		if(a[i]>=f[m])f[++m]=a[i];
		else {
			int l=1,r=m;
			while(l<r){
				int mid=(l+r)>>1;
				if(f[mid]>a[i])r=mid;
				else l=mid+1;
			}
			f[l]=a[i];
		}
	}
	for(int i=1;i<=n/2;i++)swap(a[i],a[n-i+1]);
	memset(f,127,sizeof(f));
	int m1=m;f[1]=a[1];
	for(int i=2;i<=n;i++){//LIS
		if(a[i]>=f[m])f[++m]=a[i];
		else {
			int l=1,r=m;
			while(l<r){
				int mid=(l+r)>>1;
				if(f[mid]>a[i])r=mid;
				else l=mid+1;
			}
			f[l]=a[i];
		}
	}
	printf("%d\n",n-max(m1,m));
	return 0;
} 
