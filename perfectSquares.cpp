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

bool check(int x){
	if(x<0)	return true;
	double y = sqrt((double)x);
	double yi = floor(y);
	if(y-yi > 0.0)	return true;
	return false;
}

int main(){

	int n;
	vi a;

	scanf("%d", &n);

	a.resize(n);
	fori(0, n){
		scanf("%d", &a[i]);
	}

	sort(a.begin(), a.end());

	forin(n-1, 0){
		if(check(a[i]) == true){
			cout<<a[i]<<"\n";
			break;
		}
	}

	return 0;
}