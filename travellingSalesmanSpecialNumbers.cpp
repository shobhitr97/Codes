#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
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
#define MOD 1000000007

int val[1001];
vector <vll> choose;
vector <vi> steps;

int cntBits(int n){
	int ans = 0;
	while(n){
		if(n&1)	ans++;
		n/=2;
	}
	return ans;
}

int cntSteps(int n){
	int x = cntBits(n);
	return (val[x]+1);
}

ll cal(int n, int k, int offset){
	if(n == 0){
		return 1*(val[offset] == k);
	}

	int siz, i = 0, x = 1000;
	ll ans = 0;
	siz = steps[k].size();
	// cout<<"Size of "<<k<<" steps -> "<<siz<<"\n";
	while( i < siz ){
		if( steps[k][i] > (offset+n) )	break;
		if( steps[k][i] >= offset ){
			ans = (ans + choose[n][steps[k][i] - offset])%MOD;
		}
		i++;
	}
	// cout<<ans<<"\n";
	return ans;
}

int main(){

	string n;
	int k, len, cnt;
	ll ans=0;

	cin>>n;
	cin>>k;

	if( k > 5 ){
		cout<<"0\n";
		return 0;
	}

	if( k == 0 ){
		cout<<"1\n";
		return 0;
	}

	memset(val, (-1), sizeof(val));
	steps.resize(5);

	val[1] = 0;
	val[0] = -1;
	steps[0].pb(1);
	fori(2, 1001){
		int x = cntSteps(i);
		steps[x].pb(i);
		val[i] = x;
	}

	choose.resize(1003);
	fori(1, 1001){
		choose[i].resize(i+1);
		choose[i][0] = 1;
		choose[i][1] = i;
		choose[i][i] = 1;
	}	

	fori(3, 1001){
		forn(j, 2, i){
			choose[i][j] = ( choose[i-1][j-1]+choose[i-1][j] )%MOD;
		}
	}

	len = n.length();
	cnt = 0;
	fori(0, len){
		if(n[i] == '1'){
			// cout<<"\t"<<i<<"\n";
			ans = (ans +cal(len-i-1, k-1, cnt))%MOD;
			cnt++;
		}
	}

	if(val[cnt] == (k-1) ){
		ans = (ans+1)%MOD;
	}

	if( k == 1)	ans =(ans+MOD -1)%MOD;

	cout<<ans<<"\n";

	return 0;
}