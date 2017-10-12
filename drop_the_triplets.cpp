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
#define num 1594324

ll pow3[15], dp[14][num], maxm;

ll calC(int large, ll bitmask){
	if(large<=2)	return 0;
	if(dp[large][bitmask]!=-1)	return dp[large][bitmask];
	int small, middle, cnt1, cnt2, cnt3, cnt;
	ll ans=0;
	cnt1=(bitmask%pow3[large])/pow3[large-1];
	if(cnt1>0){
		for(small=large/2+1*(large%2);small>=1;small--){
			cnt2=((bitmask-pow3[large-1])%pow3[small])/pow3[small-1];
			if(!cnt2)	continue;
			middle=large-small+1;
			while(middle<=large){
				cnt3=((bitmask-pow3[large-1]-pow3[small-1])%pow3[middle])/pow3[middle-1];
				if(!cnt3){
					middle++;
					continue;
				}
				// cout<<"("<<large<<","<<middle<<","<<small<<")\n";
				if((bitmask-pow3[large-1])/pow3[large-1]==1)	ans=max(ans, 1+calC(large, bitmask-(pow3[large-1]+pow3[middle-1]+pow3[small-1])));
				ans=max(ans, 1+calC(large-1, (bitmask-(pow3[large-1]+pow3[middle-1]+pow3[small-1]))%pow3[large-1]));
				middle++;
			}
		}
	}
	else	ans=max(ans, calC(large-1, bitmask%pow3[large-1]));
	// if(ans==1)	cout<<">>"<<large<<">>\n";
	dp[large][bitmask]=ans;
	return ans;
	// maxm=max(ans, maxm);
}
	
int main(){
	int n, arr[10005], cnt[15], a, t=0;
	ll a1, a2, bitmask;
	vi output;

	while(1){
		cin>>n;
		if(n==0)	break;
		t++;
		fori(0, n)	cin>>arr[i];

		a1=0;
		fori(1, 14)	cnt[i]=0;
		fori(0, n)	if(i%2==0)	cnt[arr[i] ]++;
		fori(1, 14)	a1+=(cnt[i]/3);

		a2=0;
		fori(1, 14)	cnt[i]=0;
		fori(0, n)	if(i%2==1)	cnt[arr[i] ]++;
		fori(1, 14)	a2+=(cnt[i]/3);

		// cout<<a1<<" "<<a2<<"\n";

		if(a1==a2){
			pow3[0]=1;
			fori(1, 15)	pow3[i]=pow3[i-1]*3;
			maxm=0;

			bitmask=0;
			fori(1, 14)	cnt[i]=0;
			forn(i, 3, 14) forn(j, 0, num-1)	dp[i][j]=-1;
			fori(0, n)	if(i%2==0)	cnt[arr[i] ]++;
			fori(1, 14)	bitmask+=((cnt[i]%3)*pow3[i-1]);
			// cout<<bitmask<<"\n";
			a1=calC(13, bitmask);
			// cout<<">>"<<a1<<"\n";

			bitmask=0;
			fori(1, 14)	cnt[i]=0;
			forn(i, 3, 14) forn(j, 0, num-1)	dp[i][j]=-1;
			fori(0, n)	if(i%2==1)	cnt[arr[i] ]++;
			fori(1, 14)	bitmask+=((cnt[i]%3)*pow3[i-1]);
			// cout<<"\n"<<bitmask<<"\n";
			a2=calC(13, bitmask);
			// cout<<">>"<<a2<<"\n";
			if(a1==a2)	a=0;
			else	a=(a1>a2)?1:2;
		}
		else	a=(a1>a2)?1:2;
		output.pb(a);
	}
	fori(0, t)	cout<<output[i]<<"\n";
	return 0;	
}