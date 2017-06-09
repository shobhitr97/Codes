#include<iostream>
#include<vector>

using namespace std;

#define fori(a,b) for( int i=a ; i<b ; i++ )
#define num 100005

typedef long long int ll;

ll max( ll a, ll b){
	if( a>b ){
		return a;
	}
	return b;
}

int main(){

	int n, j;
	ll a[num], x, maxm, sum1[num], sum2[num];

	cin>>n;

	fori(1,n+1){
		cin>>a[i];
	}

	fori(1, n){
		
		a[i] = a[i] - a[i+1];

		// mod
		if( a[i] < 0 ){
			a[i] = ( 0 - a[i] );
		}


		// power = (-1)^(i-1)
		if( i%2 == 1 ){
			a[i] = ( 0 - a[i] );
		}

	}

	if( (n-1)%2 == 0 ){
		maxm = a[n-1];
		sum1[n-1] = a[n-1];
		sum2[n-1] = 0-a[n-1];
	}
	else{
		maxm = 0-a[n-1];
		sum1[n-1] = a[n-1];
		sum2[n-1] = 0-a[n-1];
	}
	

	j = n-2;
	while( j >= 1 ){
		if( j%2 == 0 ){
			sum1[j] = max( sum1[j+1] + a[j], a[j] );
			sum2[j] = max( sum2[j+1] -a[j] , -a[j] );
			maxm = max( maxm, sum1[j]);
		}
		else{
			sum1[j] = max( sum1[j+1] + a[j], a[j] );
			sum2[j] = max( sum2[j+1] - a[j] , -a[j] );
			maxm = max( maxm, sum2[j]);
		} 
		j--;
	}

	cout<<maxm<<"\n";

	return 0;
}