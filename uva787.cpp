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
#define END -999999

int main(){
	int n;
	ll product, x, maxProduct, pro[104][104], seq[104];
	vector<ll> output;
	while(cin>>x){
		n=0;
		while(1){
			if(x==END)	break;
			seq[++n]=x;
			cin>>x;
		}
		maxProduct=seq[1];
		forn(i, 1, n+1){
			product=1;
			forn(j, i, n+1){
				product*=seq[j];
				pro[i][j]=product;
				maxProduct=max(maxProduct, product);
			}	
		}
		// cout<<maxProduct<<"\n";
		output.pb(maxProduct);
	}
	for(vector<ll>::iterator it=output.begin();it!=output.end();it++)	cout<<(*it)<<"\n";
	return 0;
}