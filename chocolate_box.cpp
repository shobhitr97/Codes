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
#define num 105

int main(){
	int n, m, t=0;
	double dp[num][num];
	vector<double> output;
	while(1){
		cin>>n;
		if(n==-1)	break;
		cin>>m;
		t++;
		fori(0, m+1)	dp[i][0]=0.000;
		dp[1][1]=(double)1.00/m;
		fori(2, n+1)	dp[1][i]=(double)(1.000/m)*dp[1][i-1];
		forn(i, 2, m+1){
			forn(j, 1, n+1){
				if(i>j)	dp[i][j]=0.000;
				int k=1;
				double temp=0.00, par=1.000;
				while(i-1<=j-k){
					par=par*((double)(j-(k-1))/(k-1+1))*((double)1/m);
					temp=temp+(double)(par*dp[i-1][j-k]);
					k++;
				}
				// cout<<"("<<i<<","<<j<<") : "<<temp<<"\n";
				dp[i][j]=temp;
			}
		}
		output.pb(1.00000-dp[m][n]);
	}
	fori(0, t)	printf("Case %d: %.7f\n", i+1, output[i]);
	return 0;
}