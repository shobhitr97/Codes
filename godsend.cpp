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
	int n, nodd;
	int sum;
	int x;
	cin>>n;
	sum=0, nodd=0;
	fori(0, n){
		scanf("%d ", &x);
		int y=x%2;
		sum=sum+y;
		nodd+=y;
	}
	if(sum%2==0){
		if(nodd==0)	cout<<"Second\n";
		else{
			cout<<"First\n";
		}
	}
	else{
		cout<<"First\n";
	}
	return 0;
}