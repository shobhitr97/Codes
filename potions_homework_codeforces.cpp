#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

#define mod 10007
typedef long long int ll;
// int c[100005];
// void countsort(int *a,int n){
// 	int i,b[100005];
// 	for(i=0;i<100005;i++){
// 		c[i]=0;
// 	}
// 	for(i=0;i<n;i++){
// 		c[a[i]]++;
// 	}
// 	for(i=1;i<100005;i++){
// 		c[i]+=c[i-1];
// 	}
// 	for(i=n-1;i>=0;i--){
// 		b[c[a[i]]-1]=a[i];
// 		c[a[i]]--;
// 	}
// 	for(i=0;i<n;i++){
// 		a[i]=b[i]%mod;
// 	}
// }

// int main(){
// 	int n,x,a[100005],i,t;
// 	cin>>n;
// 	for(i=0;i<n;i++){
// 		cin>>a[i];
// 	}
// 	countsort(a,n);
// 	t=0;
// 	for(i=0;i<=(n-1)/2;i++){
// 		t+=(a[i]*a[n-1-i])%mod;
// 		if(i!=n-i){
// 			t=(t+(a[i]*a[n-1-i])%mod)%mod;
// 		}
// 	}
// 	cout<<t<<"\n";
// 	return 0;
// }

int main(){
	vector <ll> a;
	int n, i;
	ll ans, x;

	cin>>n;

	for( i=0 ; i<n ; i++ ){
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());

	ans = 0;	
	for( i=0 ; i<n ; i++ ){
		ans = (ans + (a[ i ]*a[ n-1-i ])%mod )%mod;
	}

	cout<<ans<<"\n";

	return 0;
}