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
#define fi first
#define se second
#define INF 1000000007

int main(){
	int m[5][5];
	bool ans=false;
	forn(i, 0, 4){
		forn(j, 0, 4)	cin>>m[i][j];
	}
	if(m[0][3]&(m[0][0]|m[0][1]|m[0][2]|m[1][0]|m[2][1]|m[3][2]))	ans=true;
	if(m[1][3]&(m[1][0]|m[1][1]|m[1][2]|m[0][2]|m[2][0]|m[3][1]))	ans=true;
	if(m[2][3]&(m[2][0]|m[2][1]|m[2][2]|m[0][1]|m[1][2]|m[3][0]))	ans=true;
	if(m[3][3]&(m[3][0]|m[3][1]|m[3][2]|m[0][0]|m[1][1]|m[2][2]))	ans=true;
	if(ans==true)	cout<<"YES\n";
	else	cout<<"NO\n";
	return 0;
}