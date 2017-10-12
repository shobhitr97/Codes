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
#define num 100005

vll L, K;
int n;
ll prefixSum[num];

int bin_search1(ll key, int beg, int end){
	int mid=(beg+end)/2;
	if(mid==n){
		if(L[mid]<key)	return n;
		if(L[mid]>=key)	return bin_search1(key, beg, n-1);
	}
	else{
		if(L[mid]<key&&L[mid+1]>=key)	return mid;
		if(L[mid]>=key&&mid>0)	return bin_search1(key, beg, mid-1);
		if(L[mid+1]<key)	return bin_search1(key, mid+1, end);
	}
}

ll fn(ll r, int f, int e){
	return (r*(e-f+1)-(prefixSum[e]-prefixSum[f]+L[f]));
}
	
int main(){

	int t, q, index, beginIndex, currentIndex, lastIndex;
	ll x, ans;

	cin>>t;
	while(t--){
		cin>>n>>q;
		L.pb(0);
		fori(0, n){
			cin>>x;
			L.pb(x);
		}
		fori(0, q){
			cin>>x;
			K.pb(x);
		}
		sort(L.begin()+1, L.end());
		prefixSum[0]=0;
		fori(1, n+1)	prefixSum[i]=prefixSum[i-1]+L[i];

		fori(0, q){
			ans=0;
			index=bin_search1(K[i], 0, n);
			// cout<<index<<" : ";
			ans=n-index;
			lastIndex=index;
			beginIndex=1;
			// Look for boundary conditions
			while(1){
				if(beginIndex>lastIndex)	break;
				int mid=(beginIndex+lastIndex)/2;
				ll temp=fn(K[i], mid, lastIndex);
				if(temp<=(ll)(mid-1)){
					ans+=(lastIndex-mid+1);
					lastIndex=mid-1;
					continue;
				}
				if(temp>(ll)(mid-1)){
					beginIndex=mid+1;
					continue;
				}
			}
			cout<<ans<<"\n";
		}
		L.clear();
		K.clear();
	}

	return 0;
}