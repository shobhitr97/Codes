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
#define num 100005

int main(){
	int n, a[num], siz, cnt;
	ll d, balance, maxDemand, satisfied;
	vll maxBalance;
	vector<pair<int, ll> > demand;
	bool flag = true;

	cin>>n>>d;

	fori(0, n){
		cin>>a[i];
	}

	balance=0;
	fori(0, n){
		balance += a[i];
		if(balance > d){
			flag = false;
		}
		maxBalance.pb(balance);
	}

	// fori(0, n)	cout<<maxBalance[i]<<" ";
	// cout<<"\n";

	// maxBalance[n-1]=max(maxBalance[n-1], (ll)0);
	forin(n-2, 0){
		maxBalance[i]=max(maxBalance[i+1], maxBalance[i]);
	}

	balance=0;
	cnt=0;
	fori(0, n){
		balance+=a[i];
		if(a[i]==0){
			if(balance < 0){
				cnt++;
				if((-1)*balance + maxBalance[i] > d){
					flag = false;
					break;
				}
			}
		}
	}

	if(flag == false){
		cout<<"-1\n";
		return 0;
	}
	if(cnt==0){
		cout<<"0\n";
		return 0;
	}

	// fori(0, n)	cout<<maxBalance[i]<<" ";
	// cout<<"\n";

	// Solution exists
	maxDemand=0;
	balance=0;
	fori(0, n){
		balance+=a[i];
		if(a[i]==0 && balance<0){
			// cout<<(i+1)<<" "<<((-1)*balance)<<"\n";
			// if((-1)*balance > maxDemand){
			maxDemand = (-1)*balance;
			demand.pb(mp(i, maxDemand));
			// }
		}
	}

	// the demand vector has demands in increasing order
	siz = demand.size();
	satisfied=0;
	cnt=0;
	fori(0, siz){
		if(demand[i].se > satisfied){
			cnt++;
			satisfied += (min(d, d - maxBalance[demand[i].fi]));
		}
	}

	cout<<cnt<<"\n";

	return 0;
}