#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>

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
#define fi first
#define se second

int main(){
	double a, b;
	int x, y;
	cin>>a>>b;
	x=(int)floor(sqrt(a));
	y=(int)floor((sqrt(1.0+4.0*b)-1)/2);
	if(x<=y)	cout<<"Vladik\n";
	else	cout<<"Valera\n";
	return 0;
}