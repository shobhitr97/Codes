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

int main(){
	int n, t, rem, temp;
	cin>>n;
	if(n<=2)	cout<<"-1\n";
	else{
		if(n==3)	cout<<"210\n";
		else{
			temp=100%21;
			fori(0, n-3){
				rem=temp%21;
				temp=(temp*10)%21;
			}
			// cout<<rem<<"\n";
			temp=21-rem;
			cout<<"1";
			fori(0, n-4)	cout<<"0";
			cout<<temp/10<<temp%10<<"0\n";
		}
	}
	return 0;
}