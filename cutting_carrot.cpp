#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef set<int> si;

#define pb push_back
#define mp make_pair
#define fori(a, b) for(int i=a ; i<b ; i++ )
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second

int main(){

	int n, h;

	double x[10004];
	
	x[0] = 0.0000000000;
	x[1] = 1.0000000000;

	fori(2, 1001){
		x[i] = (2.00000000000)*x[i-1] - x[i-2];
	}

	fori(0, 1001){
		x[i] = sqrt(x[i]);
		// cout<<x[i]<<"\n";
	}

	cin>>n>>h;

	double h1;
	h1 = (double)( (double)h )/x[n];
	// cout<<h1<<"\n";

	fori(1, n){
		double p =(double)(h1*x[i]);
		printf("%0.10f ",p);
	}
	cout<<"\n";

	return 0;
}