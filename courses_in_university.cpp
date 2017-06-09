#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

typedef long long int ll;

#define fori(a, b) for( int i=a ; i<b ; i++ )
#define pb push_back
#define num 100005

int main(){

	int t, n, a[num], marked, unmarked;

	cin>>t;

	while(t--){

		cin>>n;

		fori(0, n){
			cin>>a[i];
		}

		marked = 0;
		unmarked = 1;
		fori(1, n){
			if( a[i] > marked ){
				unmarked -= (a[i]-marked);
				marked = a[i];
			}
			unmarked += 1;
		}

		cout<<unmarked<<"\n";

	}

	return 0;
}