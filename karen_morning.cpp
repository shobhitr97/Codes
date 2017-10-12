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
#define mod 25

int main(){
	int a, b, f1, f2, s1, s2, x, y, t, m;
	bool isPalin;
	scanf("%d:", &a);
	cin>>b;
	// cin>>a;
	// cin>>b;
	// cout<<a<<" "<<b<<"\n";
	f1=(a/10)%10;
	f2=a%10;
	s1=(b/10)%10;
	s2=b%10;
	y=s1+s2*10;
	x=a;
	isPalin=(a==y)?true:false;
	if(isPalin==false){
		if(f1+f2*10<b||f1+f2*10>=60){
			while(isPalin==false){
				x=(x+1)%24;
				f1=(x/10)%10;
				f2=x%10;
				y=f1+f2*10;
				if(y<60)	isPalin=true;
			}
		}
		else	y=f1+f2*10;
	}
	else{
		cout<<"0\n";
		return 0;
	}
	t=0,  m=0;
	while(a!=x)	a=(a+1)%24, t++;
	cout<<(t*60+y-b)<<"\n";
	return 0;
}