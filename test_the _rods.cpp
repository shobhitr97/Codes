#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>
#include<queue>

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
	int t1, t2, t_pro[33], dp[33][302], m[33], cost1[33][23], cost2[33][23], n, flag=0, minm, backtrack[33][102], arr[33], index;
	while(1){
		cin>>t1>>t2;
		if(!t1&&!t2)	break;
		if(flag)	cout<<"\n";
		if(!flag)	flag=1;
		cin>>n;
		fori(0, n){
			cin>>m[i];
			forn(j, 1, m[i]+1)	cin>>cost1[i][j];
			forn(j, 1, m[i]+1)	cin>>cost2[i][j];			
			cost1[i][0]=cost2[i][0]=0;
		}
		t_pro[0]=m[0];
		fori(1, n)	t_pro[i]=t_pro[i-1]+m[i];
		forn(i, 0, n){
			forn(j, 0, t1+1)	dp[i][j]=INF;
		}
		fori(0, m[0]+1){
			if(i<=t1&&(t_pro[0]-i)<=t2)	dp[0][i]=cost1[0][i]+cost2[0][m[0]-i];
		}
		fori(1, n){
			forn(j, 0, t1+1){
				if(dp[i-1][j]==INF)	continue;
				forn(z, 0, m[i]+1){
					if(j+z<=t1&&(t_pro[i]-(j+z))<=t2){
						if(dp[i][j+z]>dp[i-1][j]+cost1[i][z]+cost2[i][m[i]-z]){
							dp[i][j+z]=dp[i-1][j]+cost1[i][z]+cost2[i][m[i]-z];
							backtrack[i][j+z]=j;
						}
					}
				}
			}
		}
		minm=INF;
		fori(0, t1+1)	if(minm>dp[n-1][i])	minm=dp[n-1][i], index=i;
		forin(n-1, 1){
			arr[i]=index - backtrack[i][index];
			index=backtrack[i][index];
		}
		arr[0]=index;
		// forn(i, 0, n){
		// 	forn(j, 0, t1+1){
		// 		cout<<dp[i][j]<<" ";
		// 	}
		// 	cout<<"\n";
		// }
		cout<<minm<<"\n";	
		fori(0, n)	cout<<arr[i]<<" ";
		cout<<"\n";
	}
	return 0;
}