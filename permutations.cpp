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

int logm(ll m){
	int ans=0;
	ll temp=1;
	while(temp<m){
		temp*=2;
		ans++;
	}
	return ans;
}

int main(){
	int n, temp;
	ll m;
	stack<int> st;
	vi output;
	cin>>n>>m;
	fori(1, n+1){
		int l=logm(m);
		// cout<<l<<"\n";
		if(l<=(n-1-i)){
			output.pb(i);
		}
		else{
			st.push(i);
			// cout<<((1<<l))<<"\n";
			ll temp=1;
			while(temp<m){
				temp*=2;
			}
			temp/=2;
			m-=temp;
		}
	}
	while(!st.empty()){
		int t=st.top();
		st.pop();
		output.pb(t);
	}
	fori(0, n)	cout<<output[i]<<" ";
	cout<<"\n";
	return 0;
} 