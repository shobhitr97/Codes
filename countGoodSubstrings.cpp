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
#define aa 0
#define bb 1

int main(){

	int n, cnt, index, par, len, ch;
	string s;
	vi parity;
	ll ans[2], val[2][2][2], t1, t2, t;
	vector<pair<int, ll> > arr;

	cin>>s;
	n = s.length();

	cnt = 1;
	index = 0;
	fori(1, n){
		if(s[i] != s[i-1]){
			arr.pb(mp(index, cnt));
			cnt = 1;
			index = i;
		}
		else{
			cnt++;
		}
	}
	if(cnt)	arr.pb(mp(index, cnt));

	fori(0, 2){
		ans[i] = 0;
		forn(j, 0, 2){
			forn(k, 0, 2)	val[i][j][k] = 0;
		}
	}

	par = 0;
	len = arr.size();
	fori(0, len){
		parity.pb(par);
		par = (par + arr[i].se)&1;
	}

	forin(len-1, 0){
		t = arr[i].se;

		if(s[arr[i].fi] == 'a')	ch = aa;
		else	ch = bb;

		if( ( parity[i]+t&1 )%2 ){
			ans[1] += ( (t/2)*val[ch][1][1] + ((t+1)/2)*val[ch][1][0]  + (t/2)*val[ch][0][0] + ((t+1)/2)*val[ch][0][1] );
			ans[0] += ( (t/2)*val[ch][0][1] + ((t+1)/2)*val[ch][0][0]  + (t/2)*val[ch][1][0] + ((t+1)/2)*val[ch][1][1] );
		}
		else{
			ans[0] += ( (t/2)*val[ch][1][1] + ((t+1)/2)*val[ch][1][0]  + (t/2)*val[ch][0][0] + ((t+1)/2)*val[ch][0][1] );
			ans[1] += ( (t/2)*val[ch][0][1] + ((t+1)/2)*val[ch][0][0]  + (t/2)*val[ch][1][0] + ((t+1)/2)*val[ch][1][1] );
		}

		if( parity[i] ){
			val[ch][1][0] += (t/2);
			val[ch][1][1] += ((t+1)/2);
		}
		else{
			val[ch][0][0] += (t/2);
			val[ch][0][1] += ((t+1)/2);
		}

		if(t&1){
			ans[0] += ( (t-1)/2 + ((t-1)/2)*( ((t-1)/2) + 1 ) );
			ans[1] += ( (t+1)/2 + (t/2)*((t/2) + 1 ) );
		}
		else{
			ans[0] += ( t/2 + ((t-1)/2)*( ((t-1)/2) + 1 ) );
			ans[1] += ( t/2 + (t/2)*((t/2)+1)/2 );
		}

	}

	cout<<ans[0]<<" "<<ans[1]<<"\n";

	return 0;
}