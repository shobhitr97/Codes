#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long int ll;

int main(){
	int n,i;
	ll x,m,n1,o;
	vector< ll > a;

	cin>>n;

	for(i=1;i<=n;i++){
		cin>>x;
		a.push_back(x);
	}

	sort(a.begin(),a.end());
/*
	for(i=1;i<=n;i++){
		cout<<a[i-1]<<" ";
	}
*/
	m=a[0];
	n1=a[1];

	for(i=2 ; i<n ; i++ ){
		o = a[i];
		if( m + n1 > o ){
			cout<<"YES\n";
			return 0;
		}
		else{
			m = n1;
			n1 = o;

		}
	}

	cout<<"NO\n";

	return 0;
}