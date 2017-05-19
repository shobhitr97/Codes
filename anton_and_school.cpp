#include<iostream>
#include<string>

using namespace std;

#define MOD 1000000007
typedef long long int ll;

int left[200004], right[200004],n;
string s;

void printt( int arr[], int n ){
	for( int i=1 ; i<=n ; i++ ){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

ll 

int main(){
	cin>>s;

	n = s.length();

	if( n==0 ){
		cout<<"0\n";
		return 0;
	}

	int  i, counterl, counterr;

	counterl = 0,counterr = 0 ;
	for( i=0 ; i<n-1 ; i++ ){
		if( s[i] == '(' ){
			counterl++;
		}

		if( s[ n-1-i ] == ')' ){
			counterr++;
		}

		left[ i+1 ] = counterl;
		right[ n-1-i ] = counterr;
	
	}
	left[0] = 0;
	right[n] = 0;
	// printt( left, n-1);
	// printt( right, n-1);

	cout<<answer(1, n-1 )<<"\n";

	return 0;
}