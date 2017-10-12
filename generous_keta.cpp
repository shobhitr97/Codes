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
	int arr[27];
	fori(0, 26)	arr[i]=0;
	int n, k;
	cin>>n>>k;
	string s;
	cin>>s;
	fori(0, n){
		arr[s[i]-'a']++;
	}
	bool flag=true;
	fori(0, 26){
		if(arr[i]>k)	flag=false;
	}
	if(flag==false)	cout<<"NO\n";
	else	cout<<"YES\n";
	return 0;
}