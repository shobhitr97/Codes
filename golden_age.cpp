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
#define INF 1.0e18

int main(){
	ll x, y, pwx[61], pwy[61], maxpw1, maxpw2, tmp, l, r, tmpl, maxVal;
	double temp;
	vector<ll>tim;
	int j;
	cin>>x>>y>>l>>r;
	temp=(double)r/(double)x, tmp=1, j=0;
	pwx[0]=1;
	while(temp>=1.0){
		tmp=tmp*x;
		pwx[++j]=tmp;
		temp=temp/(double)x;
	}	
	maxpw1=j;

	temp=(double)r/(double)y, tmp=1, j=0;
	pwy[0]=1;
	while(temp>=1.0){
		tmp=tmp*y;
		pwy[++j]=tmp;
		temp=temp/(double)y;
	}	
	maxpw2=j;
	// tim.pb(l);
	j=0;
	forn(i, 0, maxpw1+1){
		tmp=r-pwx[i];
		tmpl=l-pwx[i];
		forn(k, 0, maxpw2+1){
			if(pwy[k]>=tmpl&&pwy[k]<=tmp){
				tim.pb(pwx[i]+pwy[k]);
				j++;
			}
		}
	}
	if(!j)	cout<<r-l+1<<"\n";
	else{
		// tim.pb(r);
		sort(tim.begin(), tim.end());
		tmp=tim[0];
		// cout<<tim[0]<<" ";
		maxVal=tim[0]-l;
		for(vector<ll>::iterator it=tim.begin()+1; it!=tim.end(); it++){
			// cout<<(*it)<<" ";
			maxVal=max(maxVal, (*it)-tmp-1);
			tmp=(*it);
		}
		maxVal=max(maxVal, r-tim[j-1]);
		// cout<<"\n";
		cout<<maxVal<<"\n";
	}
	return 0;
}