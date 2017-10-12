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

map<int, int>slas, pushok;

void sfactorize(ll n){
	// cout<<"Entry:"<<n<<"\n";
	if(n==1)	slas[1]=1;
	int i=2, pow=0;
	if(n%i==0){	
		while(n%i==0){
			pow++;
			n/=2;
		}
		// cout<<i<<" "<<pow<<"\n";
		slas[i]=pow;
		// i++;
	}
	i=3;
	while((ll)(i*i)<=n){
		if(n%i==0){
			pow=0;
			while(n%i==0){
				pow++;
				n/=i;
			}
			// cout<<i<<" "<<pow<<"\n";
			slas[i]=pow;
		}
		i+=2;
	}
	if(n!=1)	slas[n]=1;
	// cout<<"Exit:"<<n<<"\n";
}

void pfactorize(ll n){
	// cout<<"Entry:"<<n<<"\n";
	int i=2, pow=0;
	if(n==1)	pushok[1]=1;
	if(n%i==0){	
		while(n%i==0){
			pow++;
			n/=2;
		}
		// cout<<i<<" "<<pow<<"\n";
		pushok[i]=pow;
		// i++;
	}
	i=3;
	while((ll)(i*i)<=n){
		if(n%i==0){
			pow=0;
			while(n%i==0){
				pow++;
				n/=i;
			}
			// cout<<i<<" "<<pow<<"\n";
			pushok[i]=pow;
		}
		i+=2;
	}
	if(n!=1)	pushok[n]=1;
	// cout<<"Exit:"<<n<<"\n";
}

int main(){
	double x, y, r, s;
	ll a, b;
	int n;
	vi output;
	cin>>n;
	bool flag;
	fori(0, n){
		flag=true;
		cin>>a>>b;
		if(a==1&&b==1){
			output.pb(1);
			continue;
		}
		sfactorize(a);
		pfactorize(b);
		map<int, int>::iterator ic, it;
		for(it=slas.begin();it!=slas.end();it++){
			ic=pushok.find(it->fi);
			if(ic==pushok.end()){
				// cout<<"Could not find:"<<it->fi<<"\n";
				flag=false;
				break;
			}
			x=it->se, y=ic->se;
			r=(2.0*x-y)/3.0;
			s=(2.0*y-x)/3.0;
			// cout<<(it->fi)<<" "<<r<<","<<s<<"\n";
			if(((r-floor(r))>0.00000000000000000000000)||((s-floor(s))>0.000000000000000000000)){
				flag=false;
				break;
			}
		}
		if(flag==true)	output.pb(1);
		else	output.pb(0);
		slas.clear();
		pushok.clear();
	}
	fori(0, n){
		if(output[i]==0)	cout<<"No\n";
		else	cout<<"Yes\n";
	}
	return 0;
}