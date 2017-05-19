#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long int;

#define num 1005
#define fori( int i=a ; i<b ; i++ )

int n, m, val[num][num];
char city[num][num];

void traverse(int x, int y, int dir, int turns){
	if( x<0 || x>=n || y<0 || y>=m ){
		return;
	}

	if( city[x][y] == '*' ){
		return;
	}

	if( turns > 2 ){
		return;
	}

	if( val[x][y] == -1 ){
		val[x][y] = turns
	}
	else{
		if( val[x][y] > turns ){
			val[x][y]
		}
	}
}

int main(){

	int n, m, j;

	fori(0, n){
		for( j=0 ; j<m ; j++ ){
			cin>>city[i][j];
			if( city[i][j] == 'S' ){
				x1 = i;
				y1 = j;
			}
			val[i][j] = -1;
		}
	}

	traverse(x1, y1, 0, 0);
	traverse(x1, y1, 1, 0);
	traverse(x1, y1, 2, 0);
	traverse(x1, y1, 3, 0);

	return 0;
}