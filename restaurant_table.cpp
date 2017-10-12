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
	int n, a, b, c, x, cnt;
	cin>>n>>a>>b;
	c=0, cnt=0;
	fori(0, n){
		cin>>x;
		if(x==1){
			if(a)	a--;
			else{
				if(b)	b--, c++;
				else{
					if(c)	c--;
					else	cnt++;
				}
			}
		}
		else{
			if(b)	b--;
			else	cnt+=2;
		}
	}
	cout<<cnt<<"\n";
	return 0;
}