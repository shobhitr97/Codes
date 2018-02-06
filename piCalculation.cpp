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

int main(){
	string a;
	int pi[1005], len, temp;

	cin>>a;
	pi[0]=0;
	len=a.length();
	forn(i, 1, len){
		temp=pi[i-1];
		while(temp>0&&a[i]!=a[temp]){
			temp=pi[temp-1];
		}
		if(temp==0)	pi[i]=1*(a[i]==a[0]);
		else{
			pi[i]=temp+1;
		}
	}
	forn(i, 0, len)	cout<<"pi["<<(i+1)<<"] = "<<pi[i]<<"\n";
	return 0;
}