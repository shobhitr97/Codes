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
#define num 20005

int n,  m;
vi d, h;

int main(){
	int x, j, markH[num], markD[num], cnt;
	ll cost;

	while(1){
		cin>>n>>m;
		if(!n&&!m)	return 0;
		fori(0, n){
			cin>>x;
			d.pb(x);
		}
		fori(0, m){
			cin>>x;
			h.pb(x);
		}
		if(m<n){
			cout<<"Loowater is doomed!\n";
			h.clear();
			d.clear();
			continue;
		}
		sort(d.begin(), d.end());
		sort(h.begin(), h.end());
		j=0;
		fori(0, n)	markD[i]=0;
		fori(0, m)	markH[i]=0;
		cost=0;
		cnt=0;
		fori(0, n){
			while(j<m&&h[j]<d[i])	j++;
			if(j!=m){
				cost+=h[j++];
				cnt++;
			}
		}
		if(cnt!=n)	cout<<"Loowater is doomed!\n";
		else	cout<<cost<<"\n";
		h.clear();
		d.clear();
	}

	return 0;
}