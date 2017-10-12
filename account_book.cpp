#include<iostream>
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
#define origin 40001

bool dp[42][80002], vis[41][80002], isPos[41], isNeg[41];
int f, n, arr[42];

bool calC(int sum, int index){
	// cout<<"("<<index<<","<<sum<<")\n";
	if(vis[index][sum]==true)	return dp[index][sum];
	if(index==n)	return (((sum-origin)==f)?true:false);	
	vis[index][sum]=true;
	if(calC(sum+arr[index], index+1)==true)	dp[index][sum]=true, isPos[index]=true;
	if(calC(sum-arr[index], index+1)==true)	dp[index][sum]=true, isNeg[index]=true;
	return dp[index][sum];
}

int main(){
	bool flag;
	while(1){
		cin>>n>>f;
		if(n==0&&f==0)	break;
		flag=false;
		fori(0, 41)	isNeg[i]=false, isPos[i]=false;
		fori(0, 41)	forn(j, 0, 80001)	vis[i][j]=false, dp[i][j]=false;	
		fori(0, n)	cin>>arr[i];
		flag=calC(origin, 0);
		if(flag==false)	cout<<"*\n";
		else{
			// fori(0, n)	cout<<isPos[i]<<" ";
			// cout<<"\n";
			// fori(0, n)	cout<<isNeg[i]<<" ";
			// cout<<"\n";
			fori(0, n){
				if(isPos[i]==true&&isNeg[i]==true)	cout<<"?";
				else{
					if(isNeg[i])	cout<<"-";
					else	cout<<"+";
				}
			}	
			cout<<"\n";
		}
	}
	return 0;
}