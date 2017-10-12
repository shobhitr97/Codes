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
#define fornn(i, a, b)	for(int i=a ; i>=b ; i--)
#define fi first
#define se second
#define INF 1000000007
#define num 105

// int w, h, dp[num][num], dir[num][num];
// char mtrx[num][num];
// // 0 for right and 1 for down
// void calC1(){
// 	forn(i, 0, h)	forn(j, 0, w)	dp[i][j]=-1;
// 	dp[0][0]=0;
// 	dir[0][0]=-1;
// 	forn(i, 1, h){
// 		if(mtrx[i][0]=='#')	break;
// 		else	dp[i][0]=dp[i-1][0]+1*(mtrx[i][0]=='*'), dir[i][0]=0;
// 	}
// 	forn(i, 1, w){
// 		if(mtrx[0][i]=='#')	break;
// 		else	dp[0][i]=dp[0][i-1]+1*(mtrx[0][i]=='*'), dir[0][i]=1;
// 	}
// 	forn(i, 1, h){
// 		forn(j, 1, w){
// 			if(mtrx[i][j]=='#')	continue;
// 			if(dp[i][j-1]==-1){
// 				if(dp[i-1][j]==-1)	dp[i][j]=-1;
// 				else	dp[i][j]=dp[i-1][j]+1*(mtrx[i][j]=='*'), dir[i][j]=0;
// 			}
// 			else{
// 				if(dp[i-1][j]==-1)	dp[i][j]=dp[i][j-1]+1*(mtrx[i][j]=='*'), dir[i][j]=1;
// 				else{
// 					if(dp[i-1][j]>dp[i][j-1]) dp[i][j]=dp[i-1][j]+1*(mtrx[i][j]=='*'), dir[i][j]=0;
// 					else	dp[i][j]=dp[i][j-1]+1*(mtrx[i][j]=='*'), dir[i][j]=1;
// 				}
// 			}
// 		}
// 	}
// }

// void calC2(){
// 	forn(i, 0, h)	forn(j, 0, w)	dp[i][j]=-1;
// 	dp[h-1][w-1]=0;
// 	forin(h-2, 0){
// 		if(mtrx[i][w-1]=='#')	break;
// 		else	dp[i][w-1]=dp[i+1][w-1]+1*(mtrx[i][w-1]=='*'), dir[i][w-1]=0;
// 	}
// 	forin(w-2, 0){
// 		if(mtrx[h-1][i]=='#')	break;
// 		else	dp[h-1][i]=dp[h-1][i+1]+1*(mtrx[h-1][i]=='*'), dir[h-1][i]=1;
// 	}
// 	fornn(i, h-2, 0){
// 		fornn(j, w-2, 0){
// 			if(mtrx[i][j]=='#')	continue;
// 			if(dp[i][j+1]==-1){
// 				if(dp[i+1][j]==-1)	dp[i][j]=-1;
// 				else	dp[i][j]=dp[i+1][j]+1*(mtrx[i][j]=='*'), dir[i][j]=0;
// 			}
// 			else{
// 				if(dp[i+1][j]==-1)	dp[i][j]=dp[i][j+1]+1*(mtrx[i][j]=='*'), dir[i][j]=1;
// 				else{
// 					if(dp[i+1][j]>dp[i][j+1])	dp[i][j]=dp[i+1][j]+1*(mtrx[i][j]=='*'), dir[i][j]=0;
// 					else	dp[i][j]=dp[i][j+1]+1*(mtrx[i][j]=='*'), dir[i][j]=1;
// 				}
// 			}
// 		}
// 	}
// }

// void backTrack(){
// 	int u, v;
// 	u=h-1, v=w-1;
// 	while(u!=0&&v!=0){
// 		mtrx[u][v]='.';
// 		if(dir[u][v]==0)	u--;
// 		else	v--;
// 	}
// }

int main(){
	int t, ans, dp[num][num][num], l, w, h;
	char mtrx[num][num];
	string ch;
	cin>>t;
	forn(z, 0, t){
		cin>>w>>h;
		forn(i, 0, h){
			cin>>ch;
			forn(j, 0, w)	mtrx[i][j]=ch[j];
		}
		forn(i, 0, h)	forn(j, 0, w)	forn(k, 0, min(i+j+1, h))	dp[i][j][k]=-1;
		dp[0][0][0]=0;
		forn(i, 0, h){
			forn(j, 0, w){
				forn(k, 0, min(i+j+1, h)){
					l=i+j-k;
					if(mtrx[i][j]=='#'||mtrx[k][l]=='#')	continue;
					if(i-1>=0&&(i-1+j-k)>=0)	dp[i][j][k]=max(dp[i][j][k], dp[i-1][j][k]);
					if(i-1>=0&&k-1>=0)	dp[i][j][k]=max(dp[i][j][k], dp[i-1][j][k-1]);
					if(j-1>=0&&(i+j-1-k)>=0)	dp[i][j][k]=max(dp[i][j][k], dp[i][j-1][k]);
					if(j-1>=0&&k-1>=0)	dp[i][j][k]=max(dp[i][j][k], dp[i][j-1][k-1]);
					if(dp[i][j][k]!=-1){
						if(i==k&&j==l)	dp[i][j][k]+=1*(mtrx[i][j]=='*');
						else	dp[i][j][k]+=(1*(mtrx[i][j]=='*')+1*(mtrx[k][l]=='*'));
					}
					// dp[i][j][k]=max(dp[i-1][j][k], max(dp[i-1][j][k-1], max(dp[i][j-1][k], dp[i][j-1][k-1])));
				}
			}
		}
		cout<<dp[h-1][w-1][h-1]<<"\n";
	}
	return 0;
}	