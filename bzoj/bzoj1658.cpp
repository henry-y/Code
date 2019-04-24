#include <bits/stdc++.h>

using namespace std;

#define N 100010

int n , m ;
int x[ N ] , in[ N ];

int main(){
	scanf("%d%d" , &n , &m );
	for(int i = 1 ; i <= n ; i ++ ){
		scanf("%d" , &x[i] );
	}
	for(int i = 1 ; i <= m ; i ++ ){
		int s , t;
		scanf("%d%d" , &s , &t );
		in[ x[s] ] -- ; in[ x[t] ] ++ ;
	}
	int p1=0 , p2=0 , ans=0 ;
	while( p1 <= N ){
		if(in[ p1 ] <= 0 ) p1 ++ ;
		else if(in [ p2 ] >= 0 )p2++;
		else {
			ans+=abs( p1 - p2 );
			in[ p1 ] -- ;
			in[ p2 ] ++ ;
		}
	}
	printf("%d\n" , ans );
	return 0;
}
