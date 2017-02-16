#include<iostream>

typedef long long int ll;

using namespace std;

ll powr(int p,int m){
	if(m==1){
		return p;
	}
	ll pp;
	pp=powr(p,m/2);
	ll ans;
	ans=pp*pp;
	if(m%2==1){
		ans=ans*p;
	}
	return ans;
}

int pos(ll k,int n){
	if(n==1){
		return 1;
	}
	ll pp;
	pp=powr(2,n-1);
	if(k<=pp-1){
		return pos(k,n-1);
	}
	else{
		if(k==pp){
			return n;
		}
		else{
			return pos(k-pp,n-1);
		}
	}
}

int main(){
	ll n,k;
	cin>>n>>k;
	cout<<pos(k,n)<<"\n";
	return 0;
}