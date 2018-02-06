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

int gcd(int a, int b){
	if(b%a == 0)	return a;
	return gcd(b%a, a);
}

int callGCD(int a, int b){
	if(a>b)	return gcd(b, a);
	else	return gcd(a, b);
}

int main(){

	int t,x , y, z;
	cin>>t;

	forn(T, 0, t){
		cin>>x>>y>>z;
		if(callGCD(x, callGCD(y, z)) == 1){
			if(x*x + y*y == z*z || x*x == y*y + z*z || x*x + z*z == y*y){
				cout<<"YES\n";
			}
			else	cout<<"NO\n";
		}
		else	cout<<"NO\n";
	}

	return 0;
}