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

int dp[28][353][28], l, s, sum[28];	

int Calculate(int len, int ss, int pos){
	if(len==1)	return 1*(ss>0&&ss<pos);
	if(ss==sum[len]){
		if(pos>=len+1){
			dp[len][ss][pos]=1;
			return 1;
		}
		else{
			dp[len][ss][pos]=0;
			return 0;
		}
	}
	if(ss<sum[len]){
		dp[len][ss][pos]=0;
		return 0;
	}
	int temp=0;
	forn(j, len, pos){
		if(ss>(sum[j]-sum[j-len]))	continue;
		if(dp[len-1][ss-j][j]==-1)	temp+=Calculate(len-1, ss-j, j);
		else	temp+=dp[len-1][ss-j][j];
	}
	dp[len][ss][pos]=temp;
	return temp;
}

int main(){
	int temp, t;
	sum[0]=0;
	fori(1, 27)	sum[i]=sum[i-1]+i;
	vi output;
	t=0;
	while(1){
		cin>>l>>s;
		if(!l&&!s)	break;
		t++;
		if(l>26||s>351||l>(sum[26]-sum[26-l])||s<sum[l]){
			output.pb(0);
			continue;
		}	
		forn(i, 0, 27){
			forn(j, 0, 352){
				forn(k, 0, 27)	dp[i][j][k]=-1;
			}
		}
		temp=0;
		forn(j, l, 27){
			if(s<j||s>sum[j]-sum[j-l])	continue;
			temp+=Calculate(l-1, s-j, j);
		}
		output.pb(temp);
	}
	fori(0, t)	cout<<"Case "<<(i+1)<<": "<<output[i]<<"\n";
	return 0;
}