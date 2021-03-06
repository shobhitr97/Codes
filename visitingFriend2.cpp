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

int main(){

	int a[105], b[105], n, m;

	cin>>n>>m;

	fori(0, n)	cin>>a[i]>>b[i];

	// intial position
	int limit = 0;
	bool flag = true;
	fori(0, n){
		
		if(a[i] > limit){
			flag = false;
			break;
		}
		else{ limit = max(limit, b[i]); }
	}

	if(flag == false)	cout<<"NO\n";
	else{
		if(limit == m)	cout<<"YES\n;"
		else	cout<<"NO\n";
	}

	return 0;
}