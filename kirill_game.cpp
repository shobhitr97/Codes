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
	ll l, r, x, y, k;
	bool flag=true;
	cin>>l>>r>>x>>y>>k;
	if(x*k<l){
		if(y*k<l)	flag=false;
	}
	else{
		if(x*k>r){
			flag=false;
		}
	}
	if(flag==true){
		if(l-r+1<k){
			if(x*k<l){
				ll temp=x*k+((l-x*k)/k)*k;
				if(temp<l&&temp+k>r)	flag=false;
			}
		}
	}
	if(flag==false)	cout<<"NO\n";
	else	cout<<"YES\n";
	return 0;
}