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
typedef pair<ll, int> pli;

#define pb push_back
#define mp make_pair
#define fori(a, b) for(int i=a ; i<b ; i++ )
#define forn(i, a, b) for(int i=a ; i<b ; i++ )
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fornn(i, a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second
#define INF 1000000007
#define num 200005

int main(){
	int n, t[num], a[num], l, r, mid, cnt;
	ll T, tim;
	vector < pli > data;

	cin>>n>>T;

	fori(0, n){
		scanf("%d %d", &a[i], &t[i]);
	}

	// fori(0, n)	cout<<t[i]<<"\n";

	fori(0, n){
		data.pb(mp(t[i], i));
	}

	sort(data.begin(), data.end());

	// fori(0, n)	cout<<data[i].se<<" "<<data[i].fi<<"\n";

	l = 0, r = n;
	while(l <= r){
		mid = (l+r)/2;
		// cout<<"("<<l<<","<<r<<") :"<<mid<<"\n";
		cnt = 0;
		tim = 0;
		fori(0, n){
			if(a[ data[i].se ] >= mid && cnt < mid){
				tim += data[i].fi;
				cnt++;
			}
		}
		if(cnt < mid){
			r = mid-1;
		}
		else{
			if(tim <= T)	l = mid+1;
			else	r = mid - 1;
		}
	}

	cout<<(l-1)<<"\n"<<(l-1)<<"\n";

	if(l > 1){
		cnt = 0;
		fori(0, n){
			if(a[ data[i].se ] >= l-1 && cnt < (l-1)){
				cout<<(data[i].se+1)<<" ";
				cnt++;
			}
		}
		cout<<"\n";
	}

	return 0;
}