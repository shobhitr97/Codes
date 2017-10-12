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
	int n, k, a, b, p, q, maxDist, prev;
	vector<vi> rel;
	vii edges;
	cin>>n>>k;
	int rem=n;
	rem--;
	a=rem/k;
	b=rem%k;
	p=b;	// a+1
	q=k-p;	// a
	int cur=2;
	fori(0, p){
		prev=1;
		fori(0, a+1){
			edges.pb(mp(prev, cur));
			prev++, cur++;
		}
	}
	fori(0, q){
		prev=1;
		fori(0, a){
			edges.pb(mp(prev, cur));
			prev++, cur++;
		}
	}
	maxDist=2*a;
	maxDist=maxDist+1*(p>=1)+1*(p>=2);
	cout<<maxDist<<"\n";
	for(vii::iterator it=edges.begin();it!=edges.end();it++){
		cout<<(*it).fi<<" "<<(*it).se<<"\n";
	}
	return 0;
}