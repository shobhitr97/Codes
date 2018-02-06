#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <functional>

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

int main(){
	int n, pos, l, r, ans = 0;

	cin>>n>>pos>>l>>r;

	if(pos <= r && pos >= l){

		if(l > 1 && r < n){
			if( pos-l > r-pos){
				ans += ((r-pos)+1);
				ans += ((r-l)+1);
			}
			else{
				ans += ((pos-l)+1);
				ans += ((r-l)+1);
			}
		}
		else{
			if(l > 1){
				ans += ((pos-l)+1);
			}
			else{
				if(r < n){	ans += ((r-pos)+1); }
			}
		}

	}
	else{
		if(pos > r){
			ans += ((pos-r)+1);
			if( l > 1 ){
				ans += ((r-l)+1);
			}
		}
		else{
			ans += ((l-pos)+1);
			if(r < n){
				ans += ((r-l)+1);
			}
		}
	}

	cout<<ans<<"\n";

	return 0;
}