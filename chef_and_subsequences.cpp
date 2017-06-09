#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

#define fori(a, b) for( int i=a ; i<b ; i++ )
#define pb push_back
#define num 32

typedef long long int ll;
typedef vector<ll> vecl;
typedef vector<int> vec;

ll total_subsequences;

void recur(ll a[], ll k, int n, int index){
	if( index >= n ){
		return;
	}

	ll temp;
	int j=index;
	while( j<n && a[j] <= k ){
		if( a[j] <= k ){
			total_subsequences++;
			temp = (k/a[j]);
			if( a[j] <= temp ){
				recur(a, temp, n, j+1);
			}
		}
		j++;
	}
}

int main(){

	int j, n;
	ll x, k, array[num];;
	vecl arr;

	cin>>n>>k;

	fori(0, n){
		cin>>x;
		arr.pb(x);
	}

	sort(arr.begin(), arr.end());

	fori(0, n){
		array[i] = arr[i];
	}

	recur(array, k, n, 0);

	cout<<total_subsequences<<"\n";

	// fori(0, n){
	// 	cout<<arr[i]<<"\n";
	// }

	return 0;
}