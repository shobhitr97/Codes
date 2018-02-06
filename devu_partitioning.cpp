#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>

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
#define fornn(i, a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second
#define INF 1000000007
#define num 100005

int main(){

	int n, k, p, a[num], odds, evens;
	vi odd, even;

	cin>>n>>k>>p;

	fori(0, n)	{ cin>>a[i]; }

	fori(0, n){
		if(a[i]&1)	odd.pb(a[i]);
		else	even.pb(a[i]);
	}

	odds = odd.size();
	evens = even.size();

	// cout<<odds<<" "<<evens<<"\n";

	if(odds < k-p || evens + (odds-(k-p))/2 < p || (odds -(k-p))%2 == 1 ){
		cout<<"NO\n";
	}
	else
	{
		cout<<"YES\n";
		// if(n == 5962 && k == 5770)	cout<<odds<<" "<<evens<<" "<<k-p<<" "<<p<<"\n";
		if(evens >= p){
			cout<<(odds - (k-p) + evens - p + 1)<<" ";
			fori(k-p, odds)	cout<<odd[i]<<" ";
			fori(p, evens)	cout<<even[i]<<" ";
			if(p == 0){
				cout<<odd[0]<<"\n";
				fori(1, k-p)	cout<<"1 "<<odd[i]<<"\n";
			}
			else{
				if(evens > 0)	cout<<even[0];
				cout<<"\n";
				fori(1, p)	cout<<"1 "<<even[i]<<"\n";
				fori(0, k-p)	cout<<"1 "<<odd[i]<<"\n";
			}
		}
		else{
			// All the evens
			fori(0, evens)	cout<<"1 "<<even[i]<<"\n";
			if(k-p > 0){
				// Remaining evens using odds
				fori(0, p-evens){
					cout<<"2 "<<odd[2*i]<<" "<<odd[2*i+1]<<"\n";
				}
				// (k-p) -1 odds
				fori(2*(p-evens), 2*(p-evens)+(k-p) -1)	cout<<"1 "<<odd[i]<<"\n";
				// All the remaining odds in one go
				cout<<( odds - ( 2*(p-evens) + (k-p) -1) )<<" ";
				fori(2*(p-evens)+(k-p) -1, odds)	cout<<odd[i]<<" ";
				cout<<"\n";
			}
			else{
				// All except 1 even part
				fori(0, p-evens - 1){
					cout<<"2 "<<odd[2*i]<<" "<<odd[2*i+1]<<"\n";	
				}
				// Last even part containing all the odds
				cout<<(2 + odds - (2*(p-evens)))<<" ";
				fori(2*(p-evens-1), odds)	cout<<odd[i]<<" ";
				cout<<"\n";
			}
		}
	}

	return 0;
}