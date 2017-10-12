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
	int a, b, ans;
	ll l, r, x, y, p, q;
	cin>>a>>b>>l>>r;
	if(b>=a){
		x=l/(a+b);
		p=l%(a+b);
		p++;
		y=r/(a+b);
		q=r%(a+b);
		q++;
		if(y-x>1){
			cout<<(a+1)<<"\n";
			return 0;
		}
		if(x==y){
			if(p>a)	ans=1;
			else{
				ans=a-p+1;
				if(q<=a)	ans-=(a-q);
			}
		}
		else{
			if(p>a){
				if(q>a)	ans=a+1;
				else	ans=q;
			}
			else{
				ans=a-p+1;
				if(q<p){
					ans+=q;
				}
				else{
					if(q>a-1)	ans=a+1;
					else	ans=a;
				}
			}
		}
	}
	else{
		// a>b
		x=l/(a+b);
		p=l%(a+b);
		p++;
		y=r/(a+b);
		q=r%(a+b);
		q++;
		if(r-l+1>2*(a+b)||y-x>1){
			cout<<(2*a-b+1)<<"\n";
			return 0;
		}
		if(y==x){
			if(p>a)	ans=1;
			else{
				ans=a-p+1;
				if(q<=a)	ans-=(a-q);
			}
		}
		else{
			if(y-x==1){
				if(p>a){
					if(q<a)	ans=q;
					else	ans=a+1;
				}
				else{
					ans=a-p+1;
					if(q<=b){
						if(q<p)	ans+=q;
						else	ans=a;
					}
					else{
						ans+=b;
						if(q<=a)	ans+=(q-b);
						else	ans+=(a-b);
					}
				}
			}
			// else{

			// }
		}
	}
	cout<<ans<<"\n";
	return 0;
}