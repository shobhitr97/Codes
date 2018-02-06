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

int ind, k, limit;
vi a;
bool fff;

bool f(int sum, int places){
	if(places == 2){
		fori(0, sum+1){
			ind++;
			if(ind == k){
				a.pb(sum-i);
				a.pb(i);
				// cout<<(sum-i)<<i<<"<-"<<places<<"\n";
				return true;
			}
		}
	}
	else{
		fori(0, sum+1){
			if(f(sum-i, places-1) == true){
				a.pb(i);
				return true;
			}
		}
	}
	return false;
}

int main(){

	cin>>k;

	bool flag = false;

	int x = 2;
	ind = 0;
	fori(1, 10){
		ind++;
		if(ind == k){
			a.pb(10-i);
			a.pb(i);
			flag = true;
			break;
		}
	}
	if(flag == false){
		while(1){
			fori(1, 10){
				if(f(10-i, x) == true){
					a.pb(i);
					flag = true;
					break;
				}
			}
			if(flag == true)	break;
			x++;
		}
	}

	int siz = a.size();
	forin(siz-1, 0)	cout<<a[i];
	cout<<"\n";

	return 0;
}