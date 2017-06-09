#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

typedef long long int ll;
typedef vector<int> vec;

#define num 100005
#define pb push_back
#define fori(a, b) for( int i=a ; i<b ; i++ )

int main(){

	int t, n, x;

	cin>>t;

	vec numbers;

	while(t--){
		cin>>n;

		fori(0, 2*n){
			cin>>x;
			numbers.pb(x);
		}

		sort( numbers.begin(), numbers.end() );

		cout<<numbers[ n+(n/2)+1 - 1 ]<<"\n";

		fori(0, n){
			cout<<numbers[i]<<" "<<numbers[n+i]<<" ";
		}

		cout<<"\n";

		numbers.clear();

	}


	return 0;
}