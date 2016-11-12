#include<iostream>

using namespace std;

typedef long long int ll;
#define mod 1000000007

ll ab(int a,int b){
	ll x=1,y=a;
	while(b!=0){
		if(b%2==1){
			x=(x*y)%mod;
			// cout<<x<<" -> ";
		}
		y=(y*y)%mod;
		b=b/2;
	}
	// cout<<"<-\n";
	return x;
}

int main(){
	int t;
	ll n,ans;
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=2){
			cout<<"0\n";
			continue;
		}
		ans=ab(2,n-1);
		if(ans>=2){
			ans=ans-2;
		}
		else{
			ans=mod-1;
		}
		cout<<ans<<"\n";
	}
	return 0;
}