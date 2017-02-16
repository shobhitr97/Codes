#include<iostream>
#include<stdio.h>

using namespace std;

typedef long long int ll;

#define mod 1000000007 

ll powerr( ll a , ll b){

	ll x , y;
	y=a%mod;
	x=1;
	while(b){
		if(b%2){
			x = (x*y)%mod;
		}

		y = (y*y)%mod;
		b = b/2;
	}
	return x;

}

int main(){

	int n,i,count;

	ll p,al,ans;

	string a;

	cin>>a;
	count=0;

	for( i =0 ;i<a.length();i++){
		if(a[i]=='1'){
			count++;
		}
	}

	cin>>n;

	ans = count;

	for(i=0;i<n;i++){
		cin>>p;
		cin>>al;
		ans = (ans*(powerr(p,al)-powerr(p,al-1) ) )%mod;
	}

	

	cout<<ans<<"\n";
	return 0;

}