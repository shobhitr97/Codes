#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

#define num 100005
#define fori(a, b) for( int i=a ; i<b ; i++ )

int main(){

	int n, a[num], sum, oddMax, evenMax, tempOdd, tempEven;

	cin>>n;

	fori(0, n){
		cin>>a[i];
	}

	oddMax = -10001;
	evenMax =-10000;

	fori(0, n){
		if( a[i]%2 == 0 ){
			oddMax = max( oddMax, oddMax + a[i] );
			evenMax = max( evenMax, max( evenMax + a[i], a[i] ) );
		}
		else{
			tempOdd = max( oddMax, max(evenMax + a[i], a[i] ) );
			tempEven = max( evenMax, oddMax + a[i]);
			oddMax = tempOdd;
			evenMax = tempEven;
		}
		// cout<<oddMax<<" "<<evenMax<<"\n";
	}

	cout<<oddMax<<"\n";

	return 0;
}