#include<iostream>
#include<stdio.h>

using namespace std;

#define num 100005
#define fori(a, b) for( int i=a ; i<b ; i++ )

typedef long long int ll;

int a[num];

// presuming that b is greater than a
int gcd(int a, int b){
	if( b%a == 0 ){
		return a;
	}
	else{
		return gcd(b%a, a);
	}
}

int gcdArr( int x, int y){

	if (x==y){
		return a[x];
	}

	int g1, g2;

	int mid = (x+y)/2;

	g1 = gcdArr(x, mid);
	g2 = gcdArr(mid+1, y);

	return gcd( min(g1, g2), max(g1, g2) );

}

int main(){

	int n, ans, j, count;	

	cin>>n;

	fori(0, n){
		cin>>a[i];
	}

	int g = gcdArr(0, n-1);

	// cout<<g<<"\n";

	if( g > 1 ){
		cout<<"YES\n0\n";
		return 0;
	}

	ans = 0;
	j = 0;
	while( j<n ){
		
		count = 0;

		while( a[j]%2 == 1 ){
			count++;
			j++;
		}

		ans += ( count/2 + (count%2)*2 );

		j++;
	}	

	cout<<"YES\n";
	cout<<ans<<"\n";

	return 0;
}