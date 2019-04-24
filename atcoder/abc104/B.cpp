#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#define ll long long
#define inf 1<<30
#define il inline 
#define in1(a) read(a)
#define in2(a,b) in1(a),in1(b)
#define in3(a,b,c) in2(a,b),in1(c)
#define in4(a,b,c,d) in2(a,b),in2(c,d)
il void readl(ll &x){
    x=0;ll f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    x*=f;
}
il void read(int &x){
    x=0;int f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    x*=f;
}
using namespace std;
/*===================Header Template=====================*/
#define N 100010
char s[N];
int main(){
	scanf("%s",s+1);
	int len=strlen(s+1);
	int pd=0;
	if(s[1]!='A'){puts("WA");return 0;}
	for(int i=3;i<=len-1;i++){
		if(s[i]<'a'||s[i]>'z'){
			if(s[i]=='C'){
				if(!pd)pd=1;
				else return puts("WA"),0;
			}else {
				return puts("WA"),0;
			}
		}
	}
	if(!pd)return puts("WA"),0;
	if(s[len]>'z'||s[len]<'a')return puts("WA"),0;
	if(s[2]>'z'||s[2]<'a')return puts("WA"),0;
	printf("AC\n");
	return 0;
}
