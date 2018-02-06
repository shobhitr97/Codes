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
#define num 100005

int main(){

	int count[num], a[num], n, siz, winner;
	vi dist;

	cin>>n;

	memset(a, 0, sizeof(a));

	fori(0, n){
		scanf("%d", &a[i]);
		count[a[i]]++;
		if(count[a[i]] == 1)	dist.pb(a[i]);
	}

	sort(dist.begin(), dist.end(), greater<int>());

	siz = dist.size();
	winner = 1;
	fori(0, siz){
		if(count[dist[i]]&1){
			winner = 0;
			break;
		}
	}

	if(winner == 0)	cout<<"Conan\n";
	else	cout<<"Agasa\n";

	return 0;
}