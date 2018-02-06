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
#define num 1000*100+5


int main(){

	int n, p[num], ans, index, survivedDays;
	stack < ii > st;

	cin>>n;
	fori(0, n){
		scanf("%d", &p[i]);
	}

	index = n-1;
	ans = 0;
	while(index >= 0){
		survivedDays = 0;
		while(!st.empty()){
			ii t = st.top();
			st.pop();
			if(p[index] < t.fi){
				survivedDays = max(survivedDays, t.se);
				ans = max(ans, ++survivedDays);
			}
			else{
				st.push( mp(t.fi, max(t.se, survivedDays)) );
				break;
			}
		}
		st.push( mp(p[index], 0) );
		index--;
	}

	cout<<ans<<"\n";

	return 0;
}