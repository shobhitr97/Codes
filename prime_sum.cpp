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
#define mod 1000000007

int main(){

	int primeN[50], n1, n2, num, t;
	ll dp[2][163][20], x, y, tmp, xp[50];

	/*Preprocessing*/
	primeN[0]=2, primeN[1]=3, primeN[2]=5, primeN[3]=7, primeN[4]=11;
	num=5;
	forn(i, 13, 163){
		bool flag=true;
		forn(j, 0, 5){
			if(i%primeN[j]==0){
				flag=false;
				break;
			}
		}
		if(flag==true)	primeN[num++]=i;
	}

	cout<<num<<"\n";

	forn(i, 0, 2)	forn(j, 0, 163)	forn(k, 0, 20)	dp[i][j][k]=INF;
	forn(i, 0, 10)	dp[1][i][1]=1;
	forn(i, 2, 19){
		forn(j, 0, 163){
			forn(k, 1, 10){
				if(j-k>=0&&dp[1][j-k][i-1]<INF)	dp[1][j][i]=(dp[1][j][i]+dp[1][j-k][i-1])%mod;
			}
		}
	}

	dp[0][0][1]=1;
	forn(i, 2, 19){
		forn(j, 0, 163){
			if(dp[0][j][i-1]!=INF||dp[1][j][i-1]!=INF)	dp[0][j][i]=(dp[0][j][i-1]+dp[1][j][i-1])%mod;
		}
	}

	forn(i, 1, 19){
		forn(j, 0, 10){
			if(dp[0][j][i]==INF)	cout<<"X ";
			else	cout<<dp[0][j][i]<<" ";
		}
		cout<<"\n";
	}

	forn(i, 1, 19){
		forn(j, 0, 10){
			if(dp[1][j][i]==INF)	cout<<"X ";
			else	cout<<dp[1][j][i]<<" ";
		}
		cout<<"\n";
	}

	cin>>t;
	forn(pp, 0, t){
		cin>>x>>y;
		n1=0, n2=0;
		tmp=x;
		while(tmp>0){
			tmp/=10;
			n1++;
		}
		tmp=y;
		while(tmp>0){
			tmp/=10;
			n2++;
		}
		ll ans=0;

	}

	return 0;
}