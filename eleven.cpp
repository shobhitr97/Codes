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

	int n, a, b, c;

	cin>>n;

	if(n <= 2){
		if(n==1){
			cout<<"O\n";
		}
		else{
			cout<<"OO\n";
		}
		return 0;
	}

	cout<<"OO";
	a = 1;
	b = 2;
	c = 3;
	fori(3, n+1){
		if( i == c){
			cout<<"O";
			a = b;
			b = c;
			c = a+b;
		}
		else	cout<<"o";
	}
	cout<<"\n";

	return 0;
}