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
#define forn(i, a, b) for(int i=a ; i<b ; i++ )
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second

int main(){

	// double n, k, average, needed, temp;
	float n, k, a[104], sum, average;
	float MinAvg;

	cin>>n>>k;
	MinAvg=k-0.5;
	fori(0, n){
		cin>>a[i];
	}
	sum=0;
	fori(0, n){
		sum+=a[i];
	}
	if(MinAvg*n>sum)	cout<<(int)ceil(2.0*(MinAvg*n-sum))<<"\n";
	else	cout<<"0\n";
	// cout<<average<<" "<<sum<<"\n";
	// cout<<max(0, average-sum)<<"\n";

	return 0;
}