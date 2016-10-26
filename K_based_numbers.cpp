#include<iostream>

typedef long long int ll;

using namespace std;

int main(){
	ll P[17];
	int i,n;
	ll k;
	cin>>n>>k;
	P[0]=1;
	P[1]=k-1;
	P[2]=k*k-k;
	if(n<=2){
		cout<<P[n]<<"\n";
		return 0;
	}
	for(i=3;i<=n;i++){
		P[i]=(P[i-2]+P[i-1])*(k-1);
	}
	cout<<P[n]<<"\n";
	return 0;
}