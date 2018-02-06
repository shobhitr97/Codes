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
#define INF 1000000
#define num 1000*1000+5

int seg[num], n, k;
int minEle;

bool check(int x){
	int l = minEle/x;
	int r = INF/x;
	int cnt = 0;

	fori(l, r+1){
		int up = min(i*x+k, INF);
		cnt += (seg[up]-seg[i*x-1]);
	}

	if(k == 262 && x==263){	cout<<x<<" "<<cnt<<"\n"; }

	if(cnt == n)	return true;
	return false;
}

int main(){

	int a[300005], ans;

	scanf("%d %d", &n, &k);

	minEle = INF;
	fori(0, n){
		scanf("%d", &a[i]);
		minEle = min(minEle, a[i]);
	}

	if(minEle <= k+1){
		printf("%d\n", minEle);
		return 0;
	}

	memset(seg, 0, sizeof(seg));

	fori(0, n){
		seg[a[i]]++;
	}

	fori(1, INF+1){
		seg[i] = seg[i-1]+seg[i];
	}

	ans = k+1;
	forin(minEle, k+2){
		if(check(i) == true){
			ans = i;
			break;
		}
	}

	cout<<ans<<"\n";

	return 0;
}