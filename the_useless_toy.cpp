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
	char s, e;
	int mapch[130];
	mapch[118]=0, mapch[60]=1, mapch[94]=2, mapch[62]=3;
	ll n;
	cin>>s>>e;
	cin>>n;
	int rem=n%4;
	int x=mapch[(int)s];
	int y=mapch[(int)e];
	if(rem%2==0)	cout<<"undefined\n";
	else{
		if((x+rem)%4==y)	cout<<"cw\n";
		else	cout<<"ccw\n";
	}
	return 0;
}