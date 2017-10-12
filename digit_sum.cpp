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

int cnt(ll number){
	int res=0;
	while(number){
		res++;
		number/=10;
	}
	return res;
}

ll digitSum(ll number){
	ll powr=1, sum=0, temp=number;
	int dig;
	while(number){
		dig=number%10;
		number/=10;
		sum+=((45*number+(dig*(dig-1))/2)*powr+dig*(1+(temp%powr)));
		powr*=10;
	}
	return sum;
}

int main(){
	ll n, m, sum, temp;
	vector<ll>output;
	int t=0, cnt1, cnt2;
	while(1){
		cin>>m>>n;
		if(!m&&!n)	break;
		t++;
		sum=digitSum(n)-digitSum(m-1);
		output.pb(sum);
	}
	fori(0, t)	cout<<output[i]<<"\n";
	return 0;
}