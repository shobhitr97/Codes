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

int gcd(int a, int b){
	int temp;
	if(a<b){
		temp=a;
		a=b;
		b=temp;
	}
	while(a%b>0){
		temp=b;
		b=a%b;
		a=temp;
	}
	return b;
}

void swap(int a, int b, int* arr){
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}

int main(){
	int n, dp[307][520], c[302], l[302], minCost, cost, temp, cnt, mask;
	vi factor;

	cin>>n;
	fori(0, n)	cin>>l[i];
	fori(0, n)	cin>>c[i];
	
	minCost=INF;
	fori(0, n){
		cost=0;	
		swap(0, i, l);
		swap(0, i, c);
		if(l[0]==1)	minCost=min(c[0], minCost);
		else{
			// Calculate the prime factors of the number at 0th index and push them in factor
			temp=l[0];
			if(temp%2==0){
				factor.pb(2);
				while(temp%2==0)	temp/=2;
			}
			
			int j=3;
			while((ll)j*j<=temp&&temp>1){
				if(temp%j==0){
					factor.pb(j);
					while(temp%j==0)	temp/=j;
				}
				j+=2;
			}

			if(temp>1){
				factor.pb(temp);
				temp=1;
			}

			// forn(k, 0, factor.size())	cout<<factor[k]<<" ";
			// cout<<"\n";

			cnt=factor.size();
			forn(a, 0, n)	forn(b, 0, 1<<cnt)	dp[a][b]=INF;
			dp[0][(1<<cnt)-1]=c[0];
			forn(a, 1, n){
				forn(b, 0, 1<<cnt){
					if(dp[a-1][b]==INF)	continue;
					// cout<<"("<<a-1<<","<<b<<")\n";
					mask=0;
					forn(k, 0, cnt){
						if(b&(1<<k))	if(l[a]%factor[k]==0)	mask+=(1<<k);
					}
					dp[a][mask]=min(dp[a][mask], dp[a-1][b]+c[a]);
					dp[a][b]=min(dp[a][b], dp[a-1][b]);
				}
			}
			minCost=min(minCost, dp[n-1][0]);
			factor.clear();
		}
		// after filling the dp table and calculating the minimum cost
		swap(0, i, l);
		swap(0, i, c);
	}
	if(minCost==INF)	cout<<"-1\n";
	else	cout<<minCost<<"\n";
	return 0;
}