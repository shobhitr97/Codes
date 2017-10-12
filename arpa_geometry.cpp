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
	double a1, a2, b1, b2, c1, c2, ab, bc;
	cin>>a1>>a2>>b1>>b2>>c1>>c2;
	ab=sqrt((a1-b1)*(a1-b1)+(a2-b2)*(a2-b2));
	bc=sqrt((b1-c1)*(b1-c1)+(b2-c2)*(b2-c2));
	if(ab!=bc)	cout<<"No\n";
	else{
		if((a1-b1)*(b2-c2)-(b1-c1)*(a2-b2)==0)	cout<<"No\n";
		else	cout<<"Yes\n";
	}
	return 0;
}