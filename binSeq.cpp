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

int main(){

	ll n;
	int k, siz, index, cnt;
	vii arr, output;
	ii tmp;

	cin>>n>>k;

	fori(0, 61){
		if(n%2 == 1)	arr.pb(mp(i, 1));
		n/=2;
		if(n == 0)	break;
	}

	sort(arr.begin(), arr.end(), greater<ii>());

	siz = arr.size();
	
	if(siz > k){
		cout<<"No\n";
		return 0;
	}

	cout<<"Yes\n";

	index = 0;
	tmp = arr[0];
	while(index < siz){
		if(index == siz-1 || tmp.fi > arr[index+1].fi){
			if(k-tmp.se >= tmp.se + (siz - (index + 1))){
				tmp.fi--;
				tmp.se *= 2;
			}
			else	break;
		}
		else{
			tmp.se += arr[index+1].se;
			index++;
		}
	}

	output.pb(tmp);
	index++;

	while(index < siz)	output.pb(arr[index++]);

	siz = output.size();
	cnt = 0;
	index = siz-1;
	fori(0, siz)	cnt+=(output[i].se);

	if(k != cnt){
		while((k - cnt)){
			output[index].se--;
			output.pb(mp(output[index].fi-1, 2));
			cnt++;
			index++;
		}
	}

	fori(0, index+1){
		forn(j, 0, output[i].se)	cout<<output[i].fi<<" ";
	}
	cout<<"\n";

	return 0;
}