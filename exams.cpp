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

	int n, cur; 
	int low, temp;
	vi a, b;
	vii arr;

	cin>>n;

	a.resize(n);
	b.resize(n);

	fori(0, n){
		cin>>a[i]>>b[i];
		arr.pb(mp(a[i], b[i]));
	}

	sort(arr.begin(), arr.end());

	low = 1;

	fori(0, n){
		cur = i;
		temp = low;
		while(i<n && arr[i].fi == arr[cur].fi){
			if(arr[i].fi >= low && arr[i].se >= low)	temp = max(temp, min(arr[i].fi, arr[i].se));	
			else{
				if(arr[i].fi >= low)	temp = max(temp, arr[i].fi);
				else	temp = max(temp, arr[i].se);
			}
			i++;
		}
		low = temp;
		i--;
	}

	cout<<low<<"\n";

	return 0;
}