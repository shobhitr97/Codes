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

int arr[12][102], dp[12][102], successor[12][102], a, b;

int cal(int row, int col){
	if(dp[row][col]!=-1)	return dp[row][col];
	int x, y, temp, minm=INF, index;
	fori(-1, 2){
		x=(a+row+i)%a;
		y=col+1;
		if(dp[x][y]!=-1)	temp=arr[x][y]+dp[x][y];
		else	temp=arr[x][y]+cal(x, y);
		if(temp<minm){
			minm=temp;
			index=x;
		}
		else{
			if(temp==minm&&x<index)	index=x;
		}
	}
	dp[row][col]=minm;
	successor[row][col]=index;
	return minm;
}

int main(){
	int minm, index, temp;
	while(cin>>a){
		cin>>b;
		fori(0, a){
			forn(j, 0, b)	cin>>arr[i][j];
		}
		forn(i, 0, a){
			forn(j, 0, b)	dp[i][j]=-1;
		}
		forn(i, 0, a)	dp[i][b-1]=0;
		minm=INF;
		fori(0, a){
			temp=arr[i][0]+cal(i, 0);
			if(temp<minm){
				minm=temp;
				index=i;
			}
		}
		cout<<(index+1)<<" ";
		fori(1, b){
			index=successor[index][i-1];
			cout<<(index+1)<<" ";
		}
		cout<<"\n";
		cout<<minm<<"\n";
	}
	return 0;
}