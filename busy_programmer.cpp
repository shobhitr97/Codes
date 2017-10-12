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
#define mic 0
#define goo 1
#define num 35

// x - MICRO && y - GOO

// int main(){
// 	int d, g, t=0;
// 	ll dp[35][35][2][2], vertSum[35][35][2], horSum[35][35][2];
// 	vector<ll> output;
// 	while(1){
// 		cin>>d>>g;
// 		if(d==-1&&g==-1)	break;
// 		t++;
// 		forn(x, 0, d+1)	forn(y, 0, d+1)	dp[x][y][mic]=	dp[x][y][goo]=0;
// 		forn(x, 0, d+1)	forn(y, 0, d+1)	vertSum[x][y]=horSum[x][y]=0;

// 		fori(1, g+1)	dp[i][0][mic]=1, horSum[i][0]=1;
// 		fori(1, g+1)	dp[0][i][goo]=1, vertSum[0][i]=1;

// 		fori(0, g+1)	dp[1][i][mic]=1;
// 		horSum[1][0]=dp[1][0][mic];
// 		fori(1, d+1)	horSum[1][i]=dp[1][i][mic]+horSum[1][i-1];
// 		fori(0, g+1)	dp[i][1][goo]=1;
// 		vertSum[0][1]=dp[0][1][goo];
// 		fori(1, d+1)	vertSum[i][1]=vertSum[i-1][1]+dp[i][1][goo];

// 		forn(x, 2, d+1){
// 			forn(y, 1, d+1){
// 				if(y-(g+1)>=0)	dp[x][y][mic]=horSum[x-1][y]-horSum[x-1][y-(g+1)];
// 				else	dp[x][y][mic]=horSum[x-1][y];
// 				horSum[x][y]=horSum[x][y-1]+dp[x][y][mic];
// 			}
// 		}

// 		forn(x, 1, d+1){
// 			forn(y, 2, d+1){
// 				if(x-(g+1)>=0)	dp[x][y][goo]=vertSum[x][y-1]-vertSum[x-(g+1)][y-1];
// 				else	dp[x][y][goo]=vertSum[x][y-1];
// 				vertSum[x][y]=vertSum[x-1][y]+dp[x][y][goo];
// 			}
// 		}
// 		// fori(1, d+1){
// 		// 	forn(j, 1, d+1)	cout<<dp[i][j][mic]<<" ";
// 		// 	cout<<"\n";
// 		// }
// 		output.pb(dp[d][d][mic]+dp[d][d][goo]);
// 	}
// 	fori(1, t+1)	cout<<"Case "<<i<<": "<<output[i-1]<<"\n";
// 	return 0;
// }

ll dp[2][2*num][num];

int main(){

	int D, G, d, g, l, r;
	vll output;

	while(1){
		cin>>D>>G;
		if(D==-1&&G==-1)	break;

		fori(0, 2*D+1){
			forn(j, 0, D+1)	dp[0][i][j]=dp[1][i][j]=INF;
		}		

		/*dp[0][0][0]=*/dp[1][0][0]=1;

		forn(i, 1, 2*D){
			l=1, r=min(i, D);
			if(i>D)	l=i-D;
			forn(d, l, r+1){
				dp[0][i][d]=0;
				dp[1][i][d]=0;
				forn(k, 1, G+1){
					if(i<k||d<k)	break;
					if(dp[1][i-k][i-d]!=INF)	dp[0][i][d]+=dp[1][i-k][i-d];
					if(dp[0][i-k][i-d]!=INF)	dp[1][i][d]+=dp[0][i-k][i-d];
					// dp[0][i][d]+=dp[1][i-k][i-d];
					// dp[1][i][d]+=dp[0][i-k][i-d];
				}
				if(dp[0][i][d]==0)	dp[0][i][d]=INF;
				if(dp[1][i][d]==0)	dp[1][i][d]=INF;
			}
		}

		ll temp=0;
		forn(i, 1, G+1){
			if(i<=2*D&&dp[0][2*D-1][D]!=INF)	temp+=dp[0][2*D-i][D];
		}
		output.pb(2*temp);

		// forn(i, 0, 2*D+1){
		// 	forn(j, 0, D+1){
		// 		if(dp[1][i][j]!=INF)	cout<<dp[1][i][j]<<" ";
		// 		else	cout<<"X ";
		// 	}
		// 	cout<<"\n";
		// }
		// forn(i, 0, 2*D+1){
		// 	forn(j, 0, D+1){
		// 		if(dp[0][i][j]!=INF)	cout<<dp[0][i][j]<<" ";
		// 		else	cout<<"X ";
		// 	}
		// 	cout<<"\n";
		// }
	}

	int siz=output.size();
	fori(0, siz)	cout<<"Case "<<(i+1)<<": "<<output[i]<<"\n";

	return 0;
}