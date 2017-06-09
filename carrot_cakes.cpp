#include<iostream>
#include<stdio.h>

using namespace std;

int main(){

	int n, t, k, d, T;

	cin>>n>>t>>k>>d;

	T = n/k;
	if( n%k > 0 ){
		T++;
	}

	T = T*t;

	T =T-t;

	if( d<T ){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}

	return 0;
}