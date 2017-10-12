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
	int v0, v1, a, l, c, days=1, temp;
	cin>>c>>v0>>v1>>a>>l;
	if(c<=v0){
		cout<<"1\n";
		return 0;
	}
	days=1;
	temp=v0;
	c=c-v0;
	while(c){
		days++;
		if(temp+a>v1){
			if(v1-l>=c)	break;
			c-=(v1-l);
		}
		else{
			if(temp+a-l>=c)	break;
			c-=(temp+a-l);
		}
		temp+=a;
	}
	cout<<days<<"\n";
	return 0;
}