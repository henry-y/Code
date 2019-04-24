#include <bits/stdc++.h>

using namespace std;

#define N 1000100

int n , m ;
int low[  N ] , dfn[ N ] , head[ N ] , cnt ; 
int tot , num , top ; 
int st[ N ] , inst[ N ] , pos[ N ] , CNT[ N ] ;
int in[ N ] ;

struct node {
    int to , nxt ;
}e[ N ];

void ins( int u , int v ) {
    e[ ++ cnt ].to = v ;
    e[ cnt ].nxt = head[ u ] ;
    head[ u ] = cnt ;
}

void tarjan ( int x ) {
    dfn[ x ] = low[ x ] = ++ tot ;
    st[ ++ top ] = x ; inst[ x ] = 1 ;
    for( int i = head[ x ] ; i ; i = e[ i ].nxt ) {
        int v = e[ i ].to ;
        if ( !dfn[ v ] ) tarjan ( v ) , low[ x ] = min ( low[ v ] , low[ x ] ) ;
        else if ( inst[ v ] ) low[ x ] = min( low[ x ] , dfn[ v ] ) ;
    }
    if ( dfn[ x ] == low[ x ] ) {
        num ++ ;
        int i ;
        do {
            i = st[ top -- ] ;
            inst[ i ] = 0 ;
            pos[ i ] = num ;
            CNT[ num ] ++ ;
        }while( x != i ) ;
    }
}

int main(){
    scanf( "%d%d" , &n , &m ) ;
    for( int i = 1 ; i <= m ; i ++ ) {
        int x , y ;
        scanf( "%d%d" , &x , &y ) ;
        ins( x , y ) ;
    }
    for( int i = 1 ; i <= n ; i ++ ) {
        if ( !dfn[ i ] ) tarjan( i ) ;
    }
    int ans = 0 ; 
    for( int x = 1 ; x <= n ; x ++ ) 
        for ( int i = head[ x ] ; i ; i = e[ i ].nxt ) 
            if( pos[ x ] != pos[ e[ i ].to ] ) 
                in[ pos[ x ] ] ++ ;
    for(int i = 1 ; i <= num ; i ++ ) {
        if( !in[ i ] ) {
            if( ans ) return puts( "0" ) , 0 ; 
            ans = i ; 
        }
    }
    printf( "%d\n" , CNT[  ans ] ) ; 
    return 0 ; 
}
