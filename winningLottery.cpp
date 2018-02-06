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
#define NUM 1050

int bitMap[NUM], present[NUM];
int n;

void bitify(string s){
	int len = s.length();
	int x = 0;
	fori(0, len){
		x |= (1<<(s[i]-'0'));
	}
	cout<<s<<" -> "<<x<<"\n";
	bitMap[x]++;
}

void explore(int x, int exp, int cnt){
	present[x] += cnt;
	// cout<<"\t"<<x<<"\n";
	forin(exp-1, 0){
		if((x & (1<<i)) > 0){
			explore((x&(~(1<<i))), i, cnt);
		}
	}
}

void fillPresent(){
	forin(1023, 0){
		if(bitMap[i] == 0)	continue;
		// cout<<i<<"\n";
		explore(i, 10, bitMap[i]);
	}	
}

int main(){

	string s;
	int x;
	ll ans;

	memset(bitMap, 0, sizeof(bitMap));
	memset(present, 0, sizeof(present));

	cin>>n;

	fori(0, n){
		cin>>s;
		bitify(s);
	}

	fillPresent();

	ans = 0;
	if(bitMap[1023] > 0){
		ans = (ll)bitMap[1023]*((ll)(bitMap[1023]-1)) + ((ll)bitMap[1023])*((ll)(n - bitMap[1023]));
	}
	forin(1022, 0){
		if(bitMap[i] == 0)	continue;
		x = (1023&(~(i)));
		cout<<i<<" + "<<x<<"\n";
		if(present[x] > 0){
			cout<<i<<" -> "<<bitMap[i]<<" X "<<present[x]<<"\n";
			ans += (bitMap[i]*present[x]);
		}
	}

	cout<<(ans/2)<<"\n";

	return 0;
}