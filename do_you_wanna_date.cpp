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
#define num 300005
#define mod 1000000007

ll powr(int expn){
	ll y, x;
	y=1;
	x=2;
	while(expn){
		if(expn%2==1)	y=(y*x)%mod;
		x=(x*x)%mod;
		expn/=2;
	}
	return y;
}

int main(){

	int n;
	ll val, prefixSum[num], sum1, sum2, sum, total_sum, postfixSum[num];
	vector<ll> x;

	cin>>n;
	fori(0, n){
		cin>>val;
		x.pb(val);
	}
	
	sort(x.begin(), x.end());
	prefixSum[0]=x[0];
	fori(1, n){
		prefixSum[i]=prefixSum[i-1]+x[i];
	}	

	postfixSum[0]=x[n-1];
	int j=1;
	forin(n-2, 0){
		postfixSum[j]=postfixSum[j-1]+x[i];
		j++;
	}

	sum=0;
	ll temp;
	fori(1, n){
		sum1=prefixSum[n-i-1];
		sum2=postfixSum[n-i-1];
		temp=(sum2-sum1)%mod;
		if(temp<0)	temp+=mod;
		sum=(sum+(powr(i-1)*temp)%mod)%mod;
	}
	cout<<sum<<"\n";

	return 0;
}
