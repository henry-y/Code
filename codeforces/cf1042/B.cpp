#include <cstdio>
#include <cstring>
#include <algorithm>

#define ll long long
#define inf 0x3f3f3f3f 
#define il inline 
#define in1(a) read(a)
#define in2(a,b) in1(a),in1(b)
#define in3(a,b,c) in2(a,b),in1(c)
#define in4(a,b,c,d) in2(a,b),in2(c,d)

inline void read( int &x ){
    x = 0 ; int f = 1 ; char c = getchar() ;
    while( c < '0' || c > '9' ) {
        if( c == '-' ) f = -1 ;
        c = getchar() ;
    }
    while( c >= '0' && c <= '9' ) {
        x = (x << 1) + (x << 3) + c - 48 ;
        c = getchar() ;
    }
    x *= f ;
}

inline void readl( ll &x ){
    x = 0 ; ll f = 1 ; char c = getchar() ;
    while( c < '0' || c > '9' ) {
        if( c == '-' ) f = -1 ;
        c = getchar() ;
    }
    while( c >= '0' && c <= '9' ) {
        x = (x << 1) + (x << 3) + c - 48 ;
        c = getchar() ;
    }
    x *= f ;
}

using namespace std ;

#define N 100010

int n , m ,b[100];

int f[1050][2][2][2];

int main(){
	in1(n);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		int x;char s[50];
		scanf("%d%s",&x,s+1);
		int len=strlen(s+1);
		b[0]=b[1]=b[2]=0;
		for(int j = 1 ; j <=len; j ++ ) {
			b[s[j]-'A']=1;
		}
		f[i][b[0]][b[1]][b[2]]=min(f[i][b[0]][b[1]][b[2]],x);
		for(int j=1;j<i;j++){
			for(int a=0;a<=1;a++){
				for(int B=0;B<=1;B++){
					for(int c=0;c<=1;c++){
						f[i][a][B][c]=min(f[j][a][B][c],f[i][a][B][c]);
						f[i][(a||b[0])][(B||b[1])][(c||b[2])]=min(f[j][a][B][c]+x,f[i][(a||b[0])][(B||b[1])][(c||b[2])]);
					}
				}
			}
		}
	}
	if(f[n][1][1][1]>=0x3f3f3f3f)return puts("-1"),0;
	else printf("%d\n",f[n][1][1][1]);
}
